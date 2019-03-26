#include "Sequence.h"
#include <iostream>

//No memory need to be allocated for an empty sequence (not using dummy node)
Sequence::Sequence()
{
	m_size = 0;
	m_head = nullptr;
	m_tail = nullptr;
}

//Make sure that the following code runs correctly
//Sequence a = b;
Sequence::Sequence(const Sequence & copy)
{
	//Can't I just swap heads and tails? -> WRONG

	//Check if empty
	if (copy.m_head == nullptr) {
		m_head = nullptr;
		m_tail = nullptr;
		m_size = 0;
	}

	//Otherwise you gotta make a deep copy
	else {
		
		Node * finder = copy.m_head;
		
		//copy over size
		m_size = copy.m_size;

		//Need this temp to link together the new nodes
		Node * temp = nullptr;

		//Iterate through list you want to copy, and make new nodes (node by node)
		while (finder != nullptr) {
			//Special cases where we also have to specify m_head and m_tail

			//First element
			if (finder->m_prev == nullptr) {
				
				//Make a new node and copy info into it and link it appropriately
				Node * new_node = new Node;
				new_node->m_prev = nullptr;
				new_node->m_next = nullptr;
				new_node->m_value = finder->m_value;
				
				
				//For linking later on
				temp = new_node;

				m_head = new_node;
				m_tail = new_node; //Need this in case the list size is only 1
				finder = finder->m_next;
				continue;
			}

			//Last element
			else if (finder->m_next == nullptr) {
				Node * new_node = new Node;
				
				//Link with temporary, because this is last element, don't need to do anything further with temporary
				new_node->m_prev = temp;
				temp->m_next = new_node;

				new_node->m_next = nullptr;
				new_node->m_value = finder->m_value;
				

				m_tail = new_node;
				break;
			}

			//In the middle
			else {

				Node * new_node = new Node;

				//link using temp
				new_node->m_prev = temp;
				temp->m_next = new_node;
				temp = new_node;

				new_node->m_next = nullptr;
				new_node->m_value = finder->m_value;
				
				finder = finder->m_next;
				continue;
			}
		}

	}
}

//Makes sure that the following code runs correctly and don't forget to clean up!
//Sequence a;
//Sequence b;
//a = b;
Sequence & Sequence::operator=(const Sequence & copy)
{
	//Check for aliasing
	if (this != &copy) {
		
		//Don't forget to clean up
		while (m_tail != m_head) {
			Node *garbage = m_tail;
			m_tail = m_tail->m_prev;
			delete garbage;
		}

		delete m_head;

		//Check if empty
		if (copy.m_head == nullptr) {
			m_head = nullptr;
			m_tail = nullptr;
			m_size = 0;
		}

		//Otherwise you gotta make a deep copy
		else {

			Node * finder = copy.m_head;

			//copy over size
			m_size = copy.m_size;

			//Need this temp to link together the new nodes
			Node * temp = nullptr;

			//Iterate through list you want to copy, and make new nodes (node by node)
			while (finder != nullptr) {
				//Special cases where we also have to specify m_head and m_tail

				//First element
				if (finder->m_prev == nullptr) {

					//Make a new node and copy info into it and link it appropriately
					Node * new_node = new Node;
					new_node->m_prev = nullptr;
					new_node->m_next = nullptr;
					new_node->m_value = finder->m_value;


					//For linking later on
					temp = new_node;

					m_head = new_node;
					m_tail = new_node; //Need this in case the list size is only 1
					finder = finder->m_next;
					continue;
				}

				//Last element
				else if (finder->m_next == nullptr) {
					Node * new_node = new Node;

					//Link with temporary, because this is last element, don't need to do anything further with temporary
					new_node->m_prev = temp;
					temp->m_next = new_node;

					new_node->m_next = nullptr;
					new_node->m_value = finder->m_value;


					m_tail = new_node;
					break;
				}

				//In the middle
				else {

					Node * new_node = new Node;

					//link using temp
					new_node->m_prev = temp;
					temp->m_next = new_node;
					temp = new_node;

					new_node->m_next = nullptr;
					new_node->m_value = finder->m_value;

					finder = finder->m_next;
					continue;
				}
			}

		}
	}

	return *this;
}

//Need to delete all nodes, THEN delete head.
Sequence::~Sequence()
{
	while (m_tail != m_head) {
		Node *garbage = m_tail;
		m_tail = m_tail->m_prev;
		delete garbage;
	}
	delete m_head;
	
}

//return true if size == 0, else return false
bool Sequence::empty() const
{
	if (m_size == 0) return true;
	else return false;
}

int Sequence::size() const
{
	return m_size;
}

//Insert a new node at a given position
bool Sequence::insert(int pos, const ItemType & value)
{
	//Invalid position
	if (pos < 0 || pos > m_size) return false;

	//Check start and end of list test cases in addition to middle
	if (0 <= pos && pos < m_size) {
		//Inserting at the start (don't need to account for empty _list)
		if (pos == 0) {
			Node * new_node = new Node;

			new_node->m_value = value;
			new_node->m_next = m_head;
			new_node->m_prev = nullptr;

			m_head->m_prev = new_node;
			m_head = new_node;

			m_size += 1;
			return true;

		}
		//Inserting in the middle
		else {
			Node* finder = m_head;
			for (int i = 0; i < pos; i++) {
				finder = finder->m_next;
			}

			Node * new_node = new Node;
			new_node->m_value = value;
			new_node->m_next = finder;
			new_node->m_prev = finder->m_prev;

			finder->m_prev->m_next = new_node;
			finder->m_prev = new_node;
			
			m_size += 1;
			return true;

		}
		
	}
	//Second case insert node at the end of the linked list (or start of an empty list)
	else if (pos == m_size) {

		//Empty list case
		if (m_size == 0) {
			Node* new_node = new Node;

			new_node->m_value = value;
			new_node->m_next = nullptr;
			new_node->m_prev= nullptr;

			m_head = new_node;
			m_tail = new_node;

			m_size += 1;
			return true;

		}
		//End of non-empty list
		else {
			Node * new_node = new Node;

			new_node->m_value = value;
			new_node->m_next = nullptr;
			new_node->m_prev = m_tail;

			m_tail->m_next = new_node;
			m_tail = new_node;

			m_size += 1;
			return true;
		}
	}

	//Only for the g++ compiler
	return false;
}

//Compare values at nodes, then insert a node at first location where value <= finder->value
//return position of insertion
int Sequence::insert(const ItemType & value)
{
	int pos = m_size;

	Node * finder = m_head;

	for (int i = 0; i < m_size; i++) {
		if (value <= finder->m_value) {
			pos = i;
			break;
		}
		finder = finder->m_next;
	}

	//No need to edit size because calling the already implemented insert does it for me!!!
	//(Assumign the already implemented insert works) this saves so much time
	insert(pos, value);
	return pos;

}


//erase element at position and return true
//If invalide position or empty list return false
bool Sequence::erase(int pos)
{
	//Empty or position out of bounds
	if (m_size == 0) return false;
	if (pos < 0 || pos >= m_size) return false;

	//erase first element
	if (pos == 0) {
		//1 element list
		if (m_size == 1) {
			delete m_head;
			m_head = nullptr;
			m_tail = nullptr;
			m_size -= 1;
			return true;
		}
		//list has 2 or greater elements 
		else {
			Node * garbage = m_head;
			m_head = m_head->m_next;
			m_head->m_prev = nullptr;
			delete garbage;
			m_size -= 1;
			return true;
		}
	}
	//erase last element
	else if (pos == m_size - 1) {
		Node * garbage = m_tail;
		m_tail = m_tail->m_prev;
		m_tail->m_next = nullptr;
		delete garbage;
		m_size -= 1;
		return true;
	}
	//erase something in the middle
	else {
		Node * garbage = m_head;
		for (int i = 0; i < m_size; i++) {
			if (pos == i) {
				break;
			}
			garbage = garbage->m_next;
		}

		garbage->m_prev->m_next = garbage->m_next;
		garbage->m_next->m_prev = garbage->m_prev;
		delete garbage;
		m_size -= 1;
		return true;
	}
}	

//Remove all instances of value in the list, and return the amount of times value was removed from the list
int Sequence::remove(const ItemType & value)
{
	int counter = 0;

	//nothing to remove (empty list case)
	if (m_size == 0) return counter;

	Node * finder = m_head;

	//Does check first element
	while (finder != nullptr) {
		if (finder->m_value == value) {
			//if at the first element
			if (finder->m_prev == nullptr) {
				Node * garbage = finder;
				finder = finder->m_next;
				m_head = finder;
				finder->m_prev = nullptr;
				delete garbage;
				counter++;
				m_size--;
			}
			//at the last element
			else if (finder->m_next == nullptr) {
				Node* garbage = finder;
				finder->m_prev->m_next = nullptr;
				m_tail = finder->m_prev;
				delete garbage;
				counter++;
				m_size--;
				break;
			}
			//In the middle
			else {
				Node* garbage = finder;
				finder->m_prev->m_next = finder->m_next;
				finder->m_next->m_prev = finder->m_prev;
				finder = finder->m_next;
				delete garbage;
				m_size--;
				counter++;
			}
		}
		//Needs to be in else because sequence is advanced anyway without this
		else {
			finder = finder->m_next;
		}
	}

	return counter;
}

//NOTE get and set are essentially the same, just reverse the order of assignment (finder->m_value = value or vice versa)

//Set the value passed equal to the item at pos
//return true if successful, return false if list is empty or pos is out of bounds
bool Sequence::get(int pos, ItemType & value) const
{
	//Check if empty
	if (m_size > 0) {
		//Check if pos in boundaries
		if (0 <= pos && pos < m_size) {
			//At the start
			if (pos == 0) {
				value = m_head->m_value;
				return true;
			}
			//At the end
			else if (pos == m_size - 1) {
				value = m_tail->m_value;
				return true;
			}
			//In the middle
			else {
				Node * finder = m_head;
				for (int i = 0; i < m_size; i++) {
					if (pos == i) {
						value = finder->m_value;
						break;
					}
					finder = finder->m_next;
				}
				return true;
			}
		}
		else return false;
	}
	else return false;
}

//Set the item at pos equal to the value passed
//return true if successful, return false if the list is empty or pos is out of bounds
bool Sequence::set(int pos, const ItemType & value)
{
	//Check if empty
	if (m_size > 0) {
		//Check if pos in boundaries
		if (0 <= pos && pos < m_size) {
			//At the start
			if (pos == 0) {
				m_head->m_value = value;
				return true;
			}
			//At the end
			else if (pos == m_size - 1) {
				m_tail->m_value = value;
				return true;
			}
			//In the middle
			else {
				Node * finder = m_head;
				for (int i = 0; i < m_size; i++) {
					if (pos == i) {
						finder->m_value = value;
						break;
					}
					finder = finder->m_next;
				}
				return true;
			}
		}
		else return false;
	}
	else return false;
}

//If item not found in sequence return -1 (also return -1 if empty)
//If item found, return position of item
int Sequence::find(const ItemType & value) const
{
	int pos = -1;
	if (m_size <= 0) return pos;
	Node * finder = m_head;
	for (int i = 0; i < m_size; i++)
	{
		if (finder->m_value == value) {
			pos = i; 
			return pos;
		}
		finder = finder->m_next;
	}
	return pos;
}

//Make diligent use of the copy constructor and assignment operator and this becomes very easy :D
void Sequence::swap(Sequence & other)
{
	Sequence temp = other;

	other = *this;
	*this = temp;

}

//For testing of the linked list
//Prints out the size of the linked list then each element plus its "index" in the linked list (order)
void Sequence::dump() const
{
	std::cerr << "The size is: " << m_size << std::endl;
	
	Node * iterator = m_head;

	for (int i = 0; i < m_size; i++) {
		std::cerr << i << ": " << iterator->m_value << std::endl;
		//an extra (should be uneeded check)
		if (iterator->m_next != nullptr) {
			iterator = iterator->m_next;
		}
 	}
}

//Iterate through seq1 and try to find seq2 as a subsequence
int subsequence(const Sequence & seq1, const Sequence & seq2)
{
	if (seq2.empty() || seq1.empty()) return -1;
	if (seq2.size() > seq1.size()) return -1;
	
	//No point in checking past difference because then you know it's impossible for all of
	//seq2 to be inside seq1 as it simply won't fit
	int difference = seq1.size() - seq2.size();

	ItemType start;
	seq2.get(0, start);

	for (int i = 0; i <= difference; i++) {
		ItemType s1;
		seq1.get(i, s1);
		//Have to keep comparing to first element because subsequence has to be in order

		if (s1 == start) {
			bool truth = true;
			int k = i;
			for (int j = 0; j < seq2.size(); j++) {
				ItemType prime1;
				ItemType prime2;

				seq1.get(k, prime1);
				seq2.get(j, prime2);

				if (prime1 != prime2) {
					truth = false;
					break;
				}
				k++;

			}

			if (truth) return i;
			
		}

	}

	return -1;
}

/*
result should be an alternating combination of seq1 and seq2
Check for aliasing, then check for any empty lists before executing anything
Will need to use copy constructor/assignment operator
Check the sizes of the lists as well before copying into result
Don't forget to clear result
*/
void interleave(const Sequence & seq1, const Sequence & seq2, Sequence & result)
{
	//Use return to just exit function once complete
	if (&result != &seq1 && &result != &seq2) {

		//If both are empty make result empty
		if ((seq1.empty() == true) && (seq2.empty() == true)) {
			result = seq1;
			return;
		}
		//Just set result equal to seq2 as seq1 is empty
		else if (seq1.empty() == true) {
			result = seq2;
			return;
		}
		//Just set result equal to seq as seq2 is empty
		else if (seq2.empty() == true) {
			result = seq1;
			return;
		}
		else {
			//Check case of result not being empty
			if (result.empty() == false) {
				Sequence empty;
				result = empty;
			}

			//The size of seq1 < seq2
			if (seq1.size() < seq2.size()) {

				//i is declared outside the scope of the for loop because we need it again
				int i = 0;
				int pos = 0;

				//Insert the alternating list
				for (i; i < seq1.size(); i++) {
					ItemType s1;
					seq1.get(i, s1);

					ItemType s2;
					seq2.get(i, s2);

					result.insert(pos, s1);
					result.insert(pos + 1, s2);
					pos += 2;
				}

				//Need this would repeat an element of sequence 2
				//i += 1;

				//Insert the rest of seq2 onto the end of the list
				for (i; i < seq2.size(); i++) {
					ItemType s2;
					seq2.get(i, s2);
					result.insert(pos, s2);
					pos++;
				}

				return;
			}
			//The size of seq2 < seq1
			else if (seq2.size() < seq1.size()) {
				//i is declared outside the scope of the for loop because we need it again
				int i = 0;
				int pos = 0;

				//Insert the alternating list
				for (i; i < seq2.size(); i++) {
					ItemType s1;
					seq1.get(i, s1);

					ItemType s2;
					seq2.get(i, s2);

					result.insert(pos, s1);
					result.insert(pos + 1, s2);
					pos += 2;
				}

				//Need this would repeat an element of sequence 2
				//i += 1;

				//Insert the rest of seq1 onto the end of the list
				for (i; i < seq1.size(); i++) {
					ItemType s1;
					seq1.get(i, s1);
					result.insert(pos, s1);
					pos++;
				}

				return;
			}
			//Same size
			else {
				int pos = 0;
				for (int i = 0; i < seq1.size(); i++) {
					ItemType s1;
					seq1.get(i, s1);

					ItemType s2;
					seq2.get(i, s2);

					result.insert(pos, s1);
					result.insert(pos + 1, s2);
					pos += 2;
				}
				return;
			}
		}
	}

	else {
		//Everything is the same
		if ( (&result == &seq1) && (&result == &seq2) ) {
			Sequence empty_sequence;
			Sequence copy = seq1;
			result = empty_sequence;
			int pos = 0;
			for (int i = 0; i < copy.size(); i++) {
				ItemType s1;
				copy.get(i, s1);

				ItemType s2;
				copy.get(i, s2);

				result.insert(pos, s1);
				result.insert(pos+1, s2);
				pos += 2;
			}
			return;
		}
		//Result is the same as seq1
		else if ((&result == &seq1) && (&result != &seq2)) {
			Sequence empty_sequence;
			Sequence copy = seq1;
			result = empty_sequence;
			//The size of seq1 < seq2
			if (copy.size() < seq2.size()) {

				//i is declared outside the scope of the for loop because we need it again
				int i = 0;
				int pos = 0;
				//Insert the alternating list
				for (i; i < copy.size(); i++) {
					ItemType s1;
					copy.get(i, s1);

					ItemType s2;
					seq2.get(i, s2);

					result.insert(pos, s1);
					result.insert(pos+1, s2);
				}

				//Need this would repeat an element of sequence 2
				//i += 1;

				//Insert the rest of seq2 onto the end of the list
				for (i; i < seq2.size(); i++) {
					ItemType s2;
					seq2.get(i, s2);
					result.insert(pos, s2);
					pos++;
				}

				return;
			}
			//The size of seq2 < seq1
			else if (seq2.size() < copy.size()) {
				//i is declared outside the scope of the for loop because we need it again
				int i = 0;
				int pos = 0;
				//Insert the alternating list
				for (i; i < seq2.size(); i++) {
					ItemType s1;
					copy.get(i, s1);

					ItemType s2;
					seq2.get(i, s2);

					result.insert(pos, s1);
					result.insert(pos+1, s2);
					pos += 2;
				}

				//Need this would repeat an element of sequence 2
				//i += 1;

				//Insert the rest of seq1 onto the end of the list
				for (i; i < copy.size(); i++) {
					ItemType s1;
					copy.get(i, s1);
					result.insert(pos, s1);
					pos++;
				}

				return;
			}
			//Same size
			else {
				int pos = 0;
				for (int i = 0; i < copy.size(); i++) {
					ItemType s1;
					copy.get(i, s1);

					ItemType s2;
					seq2.get(i, s2);

					result.insert(pos, s1);
					result.insert(pos+1, s2);
					pos += 2;
				}
				return;
			}
		}
		//Result is the same as seq2
		else if ((&result != &seq1) && (&result == &seq2)) {
			Sequence empty_sequence;
			Sequence copy = seq2;
			result = empty_sequence;
			//The size of seq1 < seq2
			if (seq1.size() < copy.size()) {

				//i is declared outside the scope of the for loop because we need it again
				int i = 0;
				int pos = 0;
				//Insert the alternating list
				for (i; i < seq1.size(); i++) {
					ItemType s1;
					seq1.get(i, s1);

					ItemType s2;
					copy.get(i, s2);

					result.insert(pos, s1);
					result.insert(pos+1, s2);
				}

				//Need this would repeat an element of sequence 2
				//i += 1;

				//Insert the rest of seq2 onto the end of the list
				for (i; i < copy.size(); i++) {
					ItemType s2;
					copy.get(i, s2);
					result.insert(pos, s2);
					pos++;
				}

				return;
			}
			//The size of seq2 < seq1
			else if (copy.size() < seq1.size()) {
				//i is declared outside the scope of the for loop because we need it again
				int i = 0;
				int pos = 0;
				//Insert the alternating list
				for (i; i < copy.size(); i++) {
					ItemType s1;
					seq1.get(i, s1);

					ItemType s2;
					copy.get(i, s2);

					result.insert(pos, s1);
					result.insert(pos+1, s2);
					pos += 2;
				}

				//Need this would repeat an element of sequence 2
				//i += 1;

				//Insert the rest of seq1 onto the end of the list
				for (i; i < seq1.size(); i++) {
					ItemType s1;
					seq1.get(i, s1);
					result.insert(pos, s1);
					pos++;
				}

				return;
			}
			//Same size
			else {
				int pos = 0;
				for (int i = 0; i < seq1.size(); i++) {
					ItemType s1;
					seq1.get(i, s1);

					ItemType s2;
					copy.get(i, s2);

					result.insert(pos, s1);
					result.insert(pos+1, s2);
					pos += 2;
				}
				return;
			}
		}
	}

}
