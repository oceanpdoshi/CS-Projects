#include "History.h"
#include <iostream>

using namespace std;

//Arguments assumed to be correct
History::History(int nRows, int nCols)
{
	m_rows = nRows;
	m_cols = nCols;
	//Intialize 2D array of dots (Like display from city), first coordinate is (1,1)
	//. corresponds to 0 conversions at that location
	for (int i = 1; i <= m_rows; i++) {
		for (int j = 1; j <= m_cols; j++) {
			m_conversions[i][j] = '.';
		}
	}
}



//Note that on the ASCII Table 001-026 are A-Z respectively
bool History::record(int r, int c)
{
	if (((r > 0 && r <= m_rows) && (c > 0 && c <= m_cols))) //If the specified location IS on the grid...
		if (m_conversions[r][c] >= 'A' && m_conversions[r][c] <= 'Z') {
			m_conversions[r][c] += 1;
			return true;
		}
		else {
			m_conversions[r][c] = 'A';
			return true;
		}

	else {
		return false;
	}

}

//Display the grid with the #of conversions at a specific location w/A-Z notatiohn
void History::display() const
{
	//Similar implmentation as display from City 
	clearScreen();
	for (int i = 1; i <= m_rows; i++) {
		for (int j = 1; j <= m_cols; j++) {
			cout << m_conversions[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

