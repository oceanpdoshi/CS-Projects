#include "Piece.h"

//Constructor for the piece class sets the coordinate in the well to (3,0), the orientation to 0, and the type to the PieceType passed
Piece::Piece(PieceType p) : m_type(p)
{
	set_x(3);
	set_y(0);
	set_orientation(0);
}


//Setters
void Piece::set_x(int x)
{
	m_x = x;
}

void Piece::set_y(int y)
{
	m_y = y;
}

void Piece::set_orientation(int o)
{
	m_orientation = o;
}

//getters
int Piece::get_x() const
{
	return m_x;
}

int Piece::get_y() const
{
	return m_y;
}

int Piece::get_orientation() const
{
	return m_orientation;
}

PieceType Piece::get_type() const
{
	return m_type;
}

