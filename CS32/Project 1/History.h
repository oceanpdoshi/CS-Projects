#ifndef HISTORY_H
#define HISTORY_H
#include "globals.h"
class City;

class History
{
public:
	History(int nRows, int nCols);
	bool record(int r, int c);
	void display() const;

private: 
	
	int   m_rows;
	int   m_cols;
	char  m_conversions[MAXROWS][MAXCOLS]; 
	//Partially filled array to track characters.
	//Memory Inefficient though, could use dynamically
	//2D pointer array instead. would then add public
	//deconsructor.
};
#endif // !HISTORY_H
