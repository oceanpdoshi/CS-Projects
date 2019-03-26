// Dictionary.cpp

// First Attempt - Open Hash Table - to resolve collision have each position in the array be a linked list
//The head of each linked list is just HashTable[key]
//Have to write insert(), hashfunction(), and lookup()
//Have to modify the constructor and destructor

#include "Dictionary.h"
#include <string>

using namespace std;

const int MAX_HASH_SIZE = 50000;
const int ALPHABET_SIZE = 26;

void removeNonLetters(string& s);

//Searches through a string to see if there are any characters in s1 that aren't in s2
//For example, the words egan and hola have the same key and size, but contain different letters therefore they aren't anagrams -> the function return false
//The function woudl return true for anagrams like hola and halo
bool matchingCharacters(const string & s1, const string & s2);

//Linked list for each bucket
//Each node has a value and key (in case we want to work backwards and get the key of an anagram without utilizing the "Secret" hash function.
struct Node {
	Node(string str, int k) : value(str), key(k)
	{}
	Node * next;
	string value;
	int key;
};

class DictionaryImpl
{
  public:
	  DictionaryImpl();
	  ~DictionaryImpl();
    void insert(string word);
    void lookup(string letters, void callback(string)) const;
  private:
	 Node* hash_table[MAX_HASH_SIZE];
	int hashfunction(string & str) const;
};

//Set all the elements of the hashtable to nullptr
DictionaryImpl::DictionaryImpl()
{
	for (int i = 0; i < MAX_HASH_SIZE; i++) {
		hash_table[i] = nullptr;
	}
}

//Follow along each of the linked lists and delete values.
DictionaryImpl::~DictionaryImpl()
{
	for (int i = 0; i < MAX_HASH_SIZE; i++) {
		Node * curr = hash_table[i];
		while (curr != nullptr) {
			Node* prev = curr;
			curr = curr->next;
			delete prev;
		}
	}
}

//Insert an elmement into one of the linked-list buckets.
//If bucket is empty, this is trivial, if bucket is not empty, need to traverse linked list.
void DictionaryImpl::insert(string word)
{
    removeNonLetters(word);

	int key = hashfunction(word);
	
	if (hash_table[key] == nullptr) {
		hash_table[key] = new Node(word, key);
		hash_table[key]->next = nullptr;
		return;
	}
	else {
		Node * ptr = hash_table[key];
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		ptr->next = new Node(word, key);
		ptr->next->next = nullptr;
	}
}

//NO NEED TO USE PERMUTATION FUNCTION
//The hash function will generate the same key for anagrams as it bases the key on the ASCII character table
//Thus, we just have to go to the index of the hashtable corresponding to the key and iterate through the linked list at that location.
void DictionaryImpl::lookup(string letters, void callback(string)) const
{
    if (callback == nullptr)
        return;

    removeNonLetters(letters);
    if (letters.empty())
        return;

		Node * ptr = hash_table[hashfunction(letters)];

		//Need while loop in the case of collision
		while (ptr != nullptr) {
			//Checks for the case of  generating the same key for two words with different lenghts or for two words with same length but differing characters
			//this is efficient due to short-circuit evaluation.
			if ((ptr->value.length() == letters.length()) && matchingCharacters(letters, ptr->value)) {
				callback(ptr->value);
			}
			ptr = ptr->next;
		}
}

//Utilizes prime numbers and the modulus operator to generate unique keys for strings.
//Is fast and returns the same keys for the same values - Does a decent job of evenly distributing numbers across the buckets. -> could probably improve
//the key is stored as an unsigned long long in the case where the user inputs something like zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz, as  teh first operation of multiplying 101^26 could be very large.
//As a precaution in an actual implmentation, could throw an exception if the user inputs a string that is longer than ~40 letter characters or the longest word in the english language.
int DictionaryImpl::hashfunction(string & str) const
{
	removeNonLetters(str);
	
	//Need to come up with some hashing algorithm that returns as many unique keys as possible -> Use the first 26 prime numbers and the modulus operator
	int primes[ALPHABET_SIZE] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
	
	//Using long long just in case the numbers get really really big, so like if someone entered a word with 32 letters.
	unsigned long long key = 1;
	
	//Based assigns a prime number to each charcater based upon the ASCII table.
	for (int i = 0; i < str.length(); i++) {
		key *= primes[str[i] - 'a'];
	}

	return key % MAX_HASH_SIZE;

}
    
void removeNonLetters(string& s)
{
    string::iterator to = s.begin();
    for (string::const_iterator from = s.begin(); from != s.end(); from++)
    {
        if (isalpha(*from))
        {
            *to = tolower(*from);
            to++;
        }
    }
    s.erase(to, s.end());  // chop everything off from "to" to end.
} 

//Checks to see if any characters that are in s1 are not contained in s2
//Does not run the inner for loop if the character is already checked -> maximizes efficiency of inputs like cccccccccccccccccccccc
bool matchingCharacters(const string & s1, const string & s2 ){
	string already_checked = "";
	int counter = 0;
	char c = '\0';

	for (int i = 0; i < s1.length(); i++) {
		counter = 0;
		c = s1[i];
		//string::find(char c) returns the position of the first found character that was passed, returns -1 if it can't find the character
		//So if a character hasn't been checked...
		if (already_checked.find(c) == -1) {
			for (int j = 0; j < s2.length(); j++) {
				if (c == s2[j]) counter++;
			}
			already_checked += c;
		}
		//If it has been checked move on
		else continue;
		//if it was chekced and no entries found -> invalid
		if (counter == 0) return false;
	}
	return true;
}

//******************** Dictionary functions ********************************

// These functions simply delegate to DictionaryImpl's functions.
// You probably don't want to change any of this code

Dictionary::Dictionary()
{
    m_impl = new DictionaryImpl;
}

Dictionary::~Dictionary()
{
    delete m_impl;
}

void Dictionary::insert(string word)
{
    m_impl->insert(word);
}

void Dictionary::lookup(string letters, void callback(string)) const
{
    m_impl->lookup(letters,callback);
}
