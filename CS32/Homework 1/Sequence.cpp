#include "Sequence.h"
#include <iostream>
Sequence::Sequence()
{
	m_size = 0;
}

bool Sequence::empty() const
{
	if (m_size == 0) return true;

	else return false;

}

int Sequence::size() const
{
	return m_size;
}

bool Sequence::insert(int pos, const ItemType& value)
{
	if (m_size >= DEFAULT_MAX_ITEMS) return false;

	if (0 <= pos && pos <= m_size) {
		if (pos == m_size) {
			m_array[pos] = value;
			m_size++;
			return true;
		}
		else {
			for (int i = m_size; i > pos; i--) {
				m_array[i] = m_array[i - 1];
			}
			m_array[pos] = value;
			m_size++;
			return true;
		}
	}
	else return false;

}

int Sequence::insert(const ItemType& value)
{
	if (m_size >= DEFAULT_MAX_ITEMS) return -1;
	
	int p = 0;

	while (p < m_size) {
		if (m_array[p] <= value) {
			p++;
		}
		else {
			for (int i = m_size; i > p; i--) {
				m_array[i] = m_array[i - 1];
			}
			m_array[p] = value;
			m_size++;
			return true;
		}
	}
	//If p == m_size
	m_array[p] = value;
	m_size++;
	return true;

}

bool Sequence::erase(int pos)
{
	if (0 <= pos && pos < m_size) {
		for (int i = pos; i < m_size; i++) {
			m_array[i] = m_array[i + 1];
		}
		m_size--;
		return true;
	}
	else return false;
}

//Cannot just call erase because erase will return a bool which is interpreted as a 0 or 1.
int Sequence::remove(const ItemType& value)
{
	int counter = 0;
	for (int i = 0; i < m_size; i++) {
		if (m_array[i] == value) {
			counter++;
			for (int j = i; j < m_size; j++) {
				m_array[j] = m_array[j + 1];
			}
			m_size--;
			i--; //Because array is shifted to the left, you have to re-check the current index.
		}
	}
	return counter;
}

bool Sequence::get(int pos, ItemType& value) const
{
	if (0 <= pos && pos <= m_size) {
		value = m_array[pos];
		return true;
	}
	else return false;
}

bool Sequence::set(int pos, const ItemType& value)
{
	if (0 <= pos && pos <= m_size) {
		m_array[pos] = value;
		return true;
	}
	else return false;
}

int Sequence::find(const ItemType& value) const
{
	for (int p = 0; p < m_size; p++) {
		if (m_array[p] == value) {
			return p;
		}
	}
	return -1;
}

void Sequence::swap(Sequence & other)
{
	Sequence temp = other;
	other.m_size = m_size;
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++) {
		other.m_array[i] = m_array[i];
	}

	m_size = temp.m_size;
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++) {
		m_array[i] = temp.m_array[i];
	}

}

void Sequence::dump() const
{
	std::cerr << "Size is: " << m_size << std::endl;
	for (int i = 0; i < m_size; i++) {
		std::cerr << i << " : " << m_array[i] << std::endl;
	}
}
