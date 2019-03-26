#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <string>

using ItemType = std::string;

class Sequence
{
public:
	//Comments in cpp, testing in main
	Sequence();
	Sequence(const Sequence &copy);
	Sequence& operator=(const Sequence & copy);
	~Sequence();
	bool empty() const;
	int size() const;
	bool insert(int pos, const ItemType& value);
	int insert(const ItemType& value);
	bool erase(int pos);
	int remove(const ItemType& value);
	bool get(int pos, ItemType& value) const;
	bool set(int pos, const ItemType& value);
	int find(const ItemType& value) const;
	void swap(Sequence& other);
	
	//For testing, only prints out to cerr
	void dump() const;


private:
	//Doubly Linked (NON-CIRCULAR) List that sequence will use Node struct
	struct Node {
			Node * m_next;
			Node * m_prev;
			ItemType m_value;
	};
	Node* m_head;
	Node* m_tail;
	int m_size;
};

//Implement after completing sequence
int subsequence(const Sequence& seq1, const Sequence& seq2);

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);


#endif

