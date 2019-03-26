#include "ScoreList.h"

//Need initialization list to make the sequence member object
ScoreList::ScoreList() : m_sequence()
{
}

bool ScoreList::add(unsigned long score)
{
	if ((0 <= score && score <= 100) && m_sequence.size() != DEFAULT_MAX_ITEMS) {
		if (m_sequence.insert(score) != -1)
			return true;
		else
			return false;
	}
	else return false;
}

bool ScoreList::remove(unsigned long score)
{
	if (m_sequence.erase(score)) return true;
	else return false;
}

int ScoreList::size() const
{
	return m_sequence.size();
}

//Note that for the min and max functions, m_sequence is already sorted
unsigned long ScoreList::minimum() const
{

	if (m_sequence.size() == 0) return NO_SCORE;
	else {
		unsigned long min;
		m_sequence.get(0, min);
		return min;
	}
}

unsigned long ScoreList::maximum() const
{
	if (m_sequence.size() == 0) return NO_SCORE;
	else {
		unsigned long max;
		m_sequence.get(m_sequence.size()-1,max);
		return max;
	}
}
