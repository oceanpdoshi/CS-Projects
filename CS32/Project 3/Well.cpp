#include "Well.h"
#include "UserInterface.h"

//Initalizes the values of the well to ' '
Well::Well()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 18; j++) {
			m_well[i][j] = ' ';
		}
	}
}

//Iterates through the member variable 2D character array and prints out the array as well as the @ boundaries
void Well::display(Screen& screen, int x, int y) const
{

	//Print out @ down the left and right columns
	for (int i = 0; i < 18; i++) {
		screen.gotoXY(0, i);
		screen.printChar('@');
		screen.gotoXY(11, i);
		screen.printChar('@');
	}

	//Print out @ at the bottom row
	for (int i = 0; i < 12; i++) {
		screen.gotoXY(i, 18);
		screen.printChar('@');
	}

	//Print out the well.
	for (int i = 1; i < 11; i++) {
		for (int j = 0; j < 18; j++) {

			screen.gotoXY(i, j);
			screen.printChar(m_well[i - 1][j]);
		}

	}

}

//Checks if you can add a piece, and if so it adds it to the well.
//If this returns false, it means that the player has lost as the blocks have reached the top of the well.
bool Well::addPiece(Piece* p)
{
	switch (p->get_type()) {
	case PIECE_O:
		if (m_well[3][0] == ' ' && m_well[3][1] == ' ' && m_well[4][0] == ' ' && m_well[4][1] == ' ') {
			print_to_well(p, '#');
			return true;
		}
		else return false;
	case PIECE_I:
		if (m_well[3][1] == ' ' && m_well[4][1] == ' ' && m_well[5][1] == ' ' && m_well[6][1] == ' ') {
			print_to_well(p, '#');
			return true;
		}
		else return false;
	case PIECE_VAPOR:
		if (m_well[4][0] == ' ' && m_well[5][0] == ' ') {
			print_to_well(p, '#');
			return true;
		}
		else return false;
	case PIECE_T:
		if (m_well[4][0] == ' ' && m_well[3][1] == ' ' && m_well[4][1] == ' ' && m_well[5][1] == ' ') {
			print_to_well(p, '#');
			return true;
		}
		else return false;
	case PIECE_L:
		if (m_well[3][1] == ' ' && m_well[4][1] == ' ' && m_well[5][1] == ' ' && m_well[3][2] == ' ') {
			print_to_well(p, '#');
			return true;
		}
		else return false;
	case PIECE_J:
		if (m_well[4][1] == ' ' && m_well[5][1] == ' ' && m_well[6][1] == ' ' && m_well[6][2] == ' ') {
			print_to_well(p, '#');
			return true;
		}
		else return false;
	case PIECE_S:
		if (m_well[3][2] == ' ' && m_well[4][2] == ' ' && m_well[4][1] == ' ' && m_well[5][1] == ' ') {
			print_to_well(p, '#');
			return true;
		}
		else return false;
	case PIECE_Z:
		if (m_well[3][1] == ' ' && m_well[4][1] == ' ' && m_well[4][2] == ' ' && m_well[5][2] == ' ') {
			print_to_well(p, '#');
			return true;
		}
		else return false;
	case PIECE_CRAZY:
		if (m_well[3][0] == ' ' && m_well[4][1] == ' ' && m_well[5][1] == ' ' && m_well[6][0] == ' ') {
			print_to_well(p, '#');
			return true;
		}
		else return false;
	case PIECE_FOAM:
		if (m_well[4][1] == ' ') {
			print_to_well(p, '#');
			return true;
		}
		else return false;
	default:
		return false;
	}
	return false;
}

//Inserts the piece into the well depending on its type and orientation. Where the '#'s go depend on the piece passed.
//This function is passed '#', '$', ' ' as detailed by the spec to either move pieces with '#', represent them at rest 
// with '$', or to delete the previous position of a piece with ' '
void Well::print_to_well(Piece* p, char c)
{
	switch (p->get_type()) {
	case PIECE_O:
		m_well[p->get_x()][p->get_y()] = c;
		m_well[p->get_x()][p->get_y() + 1] = c;
		m_well[p->get_x() + 1][p->get_y()] = c;
		m_well[p->get_x() + 1][p->get_y() + 1] = c;
		return;
	case PIECE_I:
		if (p->get_orientation() == 0 || p->get_orientation() == 2) {
			m_well[p->get_x()][p->get_y()+1] = c;
			m_well[p->get_x()+1][p->get_y() + 1] = c;
			m_well[p->get_x() + 2][p->get_y()+1] = c;
			m_well[p->get_x() + 3][p->get_y() + 1] = c;
			return;
		}
		else if (p->get_orientation() == 1 || p->get_orientation() == 3) {
			m_well[p->get_x()+1][p->get_y()] = c;
			m_well[p->get_x()+1][p->get_y() + 1] = c;
			m_well[p->get_x() + 1][p->get_y()+2] = c;
			m_well[p->get_x() + 1][p->get_y() + 3] = c;
			return;
		}
	case PIECE_VAPOR:
		m_well[p->get_x() + 1][p->get_y()] = c;
		m_well[p->get_x() + 2][p->get_y()] = c;
		return;
	case PIECE_T:
		if (p->get_orientation() == 0) {
			m_well[p->get_x() + 1][p->get_y()] = c;
			m_well[p->get_x()][p->get_y() + 1] = c;
			m_well[p->get_x()+1][p->get_y() + 1] = c;
			m_well[p->get_x()+2][p->get_y() + 1] = c;
			return;
		}
		else if (p->get_orientation() == 1) {
			m_well[p->get_x() + 1][p->get_y()] = c;
			m_well[p->get_x() + 1][p->get_y() + 1] = c;
			m_well[p->get_x() + 2][p->get_y() + 1] = c;
			m_well[p->get_x() + 1][p->get_y() + 2] = c;
			return;
		}
		else if (p->get_orientation() == 2) {
			m_well[p->get_x()][p->get_y() + 1] = c;
			m_well[p->get_x() + 1][p->get_y() + 1] = c;
			m_well[p->get_x() + 2][p->get_y() + 1] = c;
			m_well[p->get_x() + 1][p->get_y() + 2] = c;
			return;
		}
		else if (p->get_orientation() == 3) {
			m_well[p->get_x()][p->get_y() + 1] = c;
			m_well[p->get_x() + 1][p->get_y()] = c;
			m_well[p->get_x() + 1][p->get_y() + 1] = c;
			m_well[p->get_x() + 1][p->get_y() + 2] = c;
			return;
		}
	case PIECE_L:
		if (p->get_orientation() == 0) {
			m_well[p->get_x()][p->get_y() + 1] = c;
			m_well[p->get_x()][p->get_y() + 2] = c;
			m_well[p->get_x() + 1][p->get_y() + 1] = c;
			m_well[p->get_x() + 2][p->get_y() + 1] = c;
			return;
		}
		else if (p->get_orientation() == 1) {
			m_well[p->get_x() + 1][p->get_y()] = c;
			m_well[p->get_x() + 2][p->get_y()] = c;
			m_well[p->get_x() + 2][p->get_y() + 1] = c;
			m_well[p->get_x() + 2][p->get_y() + 2] = c;
			return;
		}
		else if (p->get_orientation() == 2) {
			m_well[p->get_x()][p->get_y() + 2] = c;
			m_well[p->get_x() + 1][p->get_y() + 2] = c;
			m_well[p->get_x() + 2][p->get_y() + 1] = c;
			m_well[p->get_x() + 2][p->get_y() + 2] = c;
			return;
		}
		else if (p->get_orientation() == 3) {
			m_well[p->get_x()+1][p->get_y() + 1] = c;
			m_well[p->get_x() + 1][p->get_y() + 2] = c;
			m_well[p->get_x() + 1][p->get_y() + 3] = c;
			m_well[p->get_x() + 2][p->get_y() + 3] = c;
			return;
		}
	case PIECE_J:
		if (p->get_orientation() == 0) {
			m_well[p->get_x() + 1][p->get_y() + 1] = c;
			m_well[p->get_x() + 2][p->get_y() + 1] = c;
			m_well[p->get_x() + 3][p->get_y() + 1] = c;
			m_well[p->get_x() + 3][p->get_y() + 2] = c;
			return;
		}
		else if (p->get_orientation() == 1) {
			m_well[p->get_x() + 1][p->get_y() + 3] = c;
			m_well[p->get_x() + 2][p->get_y() + 3] = c;
			m_well[p->get_x() + 2][p->get_y() + 2] = c;
			m_well[p->get_x() + 2][p->get_y() + 1] = c;
			return;
		}
		else if (p->get_orientation() == 2) {
			m_well[p->get_x() + 1][p->get_y() + 1] = c;
			m_well[p->get_x() + 1][p->get_y() + 2] = c;
			m_well[p->get_x() + 2][p->get_y() + 2] = c;
			m_well[p->get_x() + 3][p->get_y() + 2] = c;
			return;
		}
		if (p->get_orientation() == 3) {
			m_well[p->get_x() + 1][p->get_y()] = c;
			m_well[p->get_x() + 2][p->get_y()] = c;
			m_well[p->get_x() + 1][p->get_y() + 1] = c;
			m_well[p->get_x() + 1][p->get_y() + 2] = c;
			return;
		}
	case PIECE_S:
		if (p->get_orientation() == 0 || p->get_orientation() == 2) {
			m_well[p->get_x()][p->get_y() + 2] = c;
			m_well[p->get_x() + 1][p->get_y() + 2] = c;
			m_well[p->get_x() + 1][p->get_y() + 1] = c;
			m_well[p->get_x() + 2][p->get_y() + 1] = c;
			return;
		}
		else if (p->get_orientation() == 1 || p->get_orientation() == 3) {
			m_well[p->get_x() + 1][p->get_y()] = c;
			m_well[p->get_x() + 1][p->get_y() + 1] = c;
			m_well[p->get_x() + 2][p->get_y() + 1] = c;
			m_well[p->get_x() + 2][p->get_y() + 2] = c;
			return;
		}
	case PIECE_Z:
		if (p->get_orientation() == 0 || p->get_orientation() == 2) {
			m_well[p->get_x()][p->get_y() + 1] = c;
			m_well[p->get_x() + 1][p->get_y() + 1] = c;
			m_well[p->get_x() + 1][p->get_y() + 2] = c;
			m_well[p->get_x() + 2][p->get_y() + 2] = c;
			return;
		}
		else if (p->get_orientation() == 1 || p->get_orientation() == 3) {
			m_well[p->get_x() + 2][p->get_y()] = c;
			m_well[p->get_x() + 2][p->get_y() + 1] = c;
			m_well[p->get_x() + 1][p->get_y() + 1] = c;
			m_well[p->get_x() + 1][p->get_y() + 2] = c;
			return;
		}
	case PIECE_CRAZY:
		if (p->get_orientation() == 0) {
			m_well[p->get_x()][p->get_y()] = c;
			m_well[p->get_x() + 1][p->get_y() + 1] = c;
			m_well[p->get_x() + 2][p->get_y() + 1] = c;
			m_well[p->get_x() + 3][p->get_y()] = c;
			return;
		}
		else if (p->get_orientation() == 1) {
			m_well[p->get_x() + 3][p->get_y()] = c;
			m_well[p->get_x() + 2][p->get_y() + 1] = c;
			m_well[p->get_x() + 2][p->get_y() + 2] = c;
			m_well[p->get_x() + 3][p->get_y() + 3] = c;
			return;
		}
		else if (p->get_orientation() == 2) {
			m_well[p->get_x()][p->get_y() + 3] = c;
			m_well[p->get_x() + 1][p->get_y() + 2] = c;
			m_well[p->get_x() + 2][p->get_y() + 2] = c;
			m_well[p->get_x() + 3][p->get_y() + 3] = c;
			return;
		}
		if (p->get_orientation() == 3) {
			m_well[p->get_x()][p->get_y()] = c;
			m_well[p->get_x() + 1][p->get_y() + 1] = c;
			m_well[p->get_x() + 1][p->get_y() + 2] = c;
			m_well[p->get_x()][p->get_y() + 3] = c;
			return;
		}
	case PIECE_FOAM:
		m_well[p->get_x() + 1][p->get_y() + 1] = c;
		return;
	default:
		return;
	}

}

//Checks if the spot in the well at the passed coordinates (x,y) is occupied.
//Avoids undefined behavior by checking if the passed coordinates are out of bounds.
bool Well::isOccupied(int x, int y) const
{
	//Prevents an out of bounds error
	if (x < 0 || y > 17) return false;
	if (m_well[x][y] == ' ') return false;
	return true;

}

//Iterates through the row at the passed y-coordinate and checks if any spots are emtpy
//if full returns true, if not full returns false.
bool Well::isRowFull(int y) const
{
	for (int x = 0; x < 10; x++) {
		if (m_well[x][y] != ' ') continue;
		else return false;
	}
	return true;
}

//Removes the row at the passed y-coordinate from the well and shifts all of the above rows in the well down by one.
void Well::removeRow(int y)
{
	//clear out the row at y
	for (int x = 0; x < 10; x++) {
		m_well[x][y] = ' ';
	}
	
	//Shift down all the rows above y.
	for (y; y > 0; y--) {
		for (int x = 0; x < 10; x++) {
			m_well[x][y] = m_well[x][y - 1];
		}
	}
	for (int x  = 0; x < 10; x++) {
		m_well[x][0] = ' ';
	}
	
}

//Move the piece either down, left and right. Returns true if the move was possible and thus executed
//Returns false if the move could not be executed.
//Each of these functions has a switch statement as different pieces w/diffferent orientations have different conditions that need to be checked
//These functions are the "meat" of the program as they handle all the boundary/collision checking for every single piece.
bool Well::move_down(Piece* p)
{
	switch (p->get_type()) {
	case PIECE_O:
		//About to land on an invalid character
		if (isOccupied(p->get_x(),p->get_y() + 2) || isOccupied(p->get_x() + 1, p->get_y() + 2) || (p->get_y() + 1 >16)) {
			return false;
		}
		else {
			print_to_well(p, ' ');
			p->set_y(p->get_y() + 1);
			print_to_well(p, '#');
			return true;
		}
	case PIECE_I:
		if (p->get_orientation() == 0 || p->get_orientation() == 2) {
			if (isOccupied(p->get_x(), p->get_y() + 2) || isOccupied(p->get_x() + 1, p->get_y() + 2) || isOccupied(p->get_x() + 2, p->get_y() + 2) || isOccupied(p->get_x() + 3, p->get_y() + 2)
				|| p->get_y() + 2 > 17) return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1 || p->get_orientation() == 3) {
			if (isOccupied(p->get_x() + 1, p->get_y() + 4) 
				|| p->get_y() + 4 > 17) return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_VAPOR:
		if (isOccupied(p->get_x()+1, p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y() + 1) || (p->get_y() + 1 > 17)) {
			return false;
		}
		else {
			print_to_well(p, ' ');
			p->set_y(p->get_y() + 1);
			print_to_well(p, '#');
			return true;
		}
	case PIECE_T:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x(), p->get_y() + 2) || isOccupied(p->get_x()  + 1, p->get_y() + 2) || isOccupied(p->get_x() + 2, p->get_y() + 2) ||
				p->get_y() + 2 > 17)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x() + 1, p->get_y() + 3) || isOccupied(p->get_x() + 2, p->get_y() + 2)
				|| p->get_y() + 3 > 17)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x(), p->get_y() + 2) || isOccupied(p->get_x() + 1, p->get_y() + 3) || isOccupied(p->get_x() + 2, p->get_y() + 2)
				|| p->get_y() + 3 > 17)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x() + 1, p->get_y() + 3) || isOccupied(p->get_x(), p->get_y() + 2)
				|| p->get_y() + 3 > 17)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_L:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x(), p->get_y() + 3) || isOccupied(p->get_x() + 1, p->get_y() + 2) || isOccupied(p->get_x() + 2, p->get_y() + 2) ||
				p->get_y() + 1 > 15)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x() + 1, p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y() + 3)
				|| p->get_y() + 1 > 15)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x(), p->get_y() + 3) || isOccupied(p->get_x() + 1, p->get_y() + 3) || isOccupied(p->get_x() + 2, p->get_y() + 3)
				|| p->get_y() + 1 > 15)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x() + 1, p->get_y() + 4) || isOccupied(p->get_x() + 2, p->get_y() + 4)
				|| p->get_y() + 1 > 14)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_J:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x() + 1, p->get_y() + 2) || isOccupied(p->get_x() + 2, p->get_y() + 2) || isOccupied(p->get_x() + 3, p->get_y() + 3) ||
				p->get_y() > 14)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x() + 1, p->get_y() + 4) || isOccupied(p->get_x() + 2, p->get_y() + 4)
				|| p->get_y() > 13)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x() + 1, p->get_y() + 3) || isOccupied(p->get_x() + 2, p->get_y() + 3) || isOccupied(p->get_x() + 3, p->get_y() + 3)
				|| p->get_y() > 14)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x() + 1, p->get_y() + 3) || isOccupied(p->get_x() + 2, p->get_y() + 1)
				|| p->get_y() > 14)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_S:
		if (p->get_orientation() == 0 || p->get_orientation() == 2) {
			if (isOccupied(p->get_x(), p->get_y() + 3) || isOccupied(p->get_x() + 1, p->get_y() + 3) || isOccupied(p->get_x() + 2, p->get_y() + 2) 
				|| p->get_y() > 14) return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1 || p->get_orientation() == 3) {
			if (isOccupied(p->get_x() + 1, p->get_y() + 2) || isOccupied(p->get_x() + 2, p->get_y() + 3)
				|| p->get_y() > 14) return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_Z:
		if (p->get_orientation() == 0 || p->get_orientation() == 2) {
			if (isOccupied(p->get_x(), p->get_y() + 2) || isOccupied(p->get_x() + 1, p->get_y() + 3) || isOccupied(p->get_x() + 2, p->get_y() + 3)
				|| p->get_y() > 14) return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1 || p->get_orientation() == 3) {
			if (isOccupied(p->get_x() + 1, p->get_y() + 3) || isOccupied(p->get_x() + 2, p->get_y() + 2)
				|| p->get_y() > 14) return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_CRAZY:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x(), p->get_y() + 1) || isOccupied(p->get_x() + 1, p->get_y() + 2) || isOccupied(p->get_x() + 2, p->get_y() + 2) || isOccupied(p->get_x() + 3, p->get_y() + 1)
				|| p->get_y() > 15)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x() + 3, p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y() + 3) || isOccupied(p->get_x() + 3, p->get_y() + 4) 
				|| p->get_y()  > 13)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x(), p->get_y() + 4) || isOccupied(p->get_x() + 1, p->get_y() + 3) || isOccupied(p->get_x() + 2, p->get_y() + 3) || isOccupied(p->get_x() + 3, p->get_y() + 4)
				|| p->get_y() > 13)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x(), p->get_y() + 1) || isOccupied(p->get_x() + 1, p->get_y() + 3) || isOccupied(p->get_x(), p->get_y() + 4)
				|| p->get_y() > 13)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_y(p->get_y() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_FOAM:
		//About to land on an invalid character
		if (isOccupied(p->get_x() + 1, p->get_y() + 2) 
			|| p->get_y() > 15) {
			return false;
		}
		else {
			print_to_well(p, ' ');
			p->set_y(p->get_y() + 1);
			print_to_well(p, '#');
			return true;
		}
	default:
		return false;
	}
	return false;
}

bool Well::move_left(Piece * p)
{
	switch (p->get_type()) {
	case PIECE_O:
		if (p->get_x() < 1 || isOccupied(p->get_x()-1, p->get_y()) || isOccupied(p->get_x()-1, p->get_y() + 1))
			return false;
		else {
			print_to_well(p, ' ');
			p->set_x(p->get_x() - 1);
			print_to_well(p, '#');
			return true;
		}
	case PIECE_I:
		if (p->get_orientation() == 0 || p->get_orientation() == 2) {
			if (isOccupied(p->get_x() - 1, p->get_y() + 1) || p->get_x() - 1 < 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1 || p->get_orientation() == 3) {
			if (isOccupied(p->get_x(), p->get_y()) || isOccupied(p->get_x(), p->get_y() + 1) || isOccupied(p->get_x(), p->get_y() + 2) || isOccupied(p->get_x(), p->get_y() + 3)
				|| p->get_x() < 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_VAPOR:
		if (p->get_x() < 0 || isOccupied(p->get_x(), p->get_y()))
			return false;
		else {
			print_to_well(p, ' ');
			p->set_x(p->get_x() - 1);
			print_to_well(p, '#');
			return true;
		}
	case PIECE_T:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x() - 1, p->get_y() + 1) || isOccupied(p->get_x(), p->get_y())
				|| p->get_x() <= 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x(), p->get_y()) || isOccupied(p->get_x(), p->get_y() + 1) || isOccupied(p->get_x(), p->get_y() + 2)
				|| p->get_x() < 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x() - 1, p->get_y() + 1) || isOccupied(p->get_x(), p->get_y() + 2)
				|| p->get_x() <= 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x() - 1, p->get_y() + 1) || isOccupied(p->get_x(), p->get_y()) || isOccupied(p->get_x(), p->get_y() + 2)
				|| p->get_x() <= 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_L:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x() - 1, p->get_y() + 1) || isOccupied(p->get_x() - 1, p->get_y() + 2)
				|| p->get_x() <= 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x(), p->get_y()) || isOccupied(p->get_x() + 1, p->get_y() + 1) || isOccupied(p->get_x() + 1, p->get_y() + 2)
				|| p->get_x() < 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x() - 1, p->get_y() + 2) || isOccupied(p->get_x() + 1, p->get_y() + 1)
				|| p->get_x() <= 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x(), p->get_y() + 1) || isOccupied(p->get_x(), p->get_y() + 2) || isOccupied(p->get_x(), p->get_y() + 3)
				|| p->get_x() < 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_J:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x() , p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y() + 2)
				|| p->get_x() < 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x(), p->get_y() + 3) || isOccupied(p->get_x() + 1, p->get_y() + 2) || isOccupied(p->get_x() + 1, p->get_y() + 1)
				|| p->get_x() < 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x(), p->get_y() + 1) || isOccupied(p->get_x(), p->get_y() + 2)
				|| p->get_x() < 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x(), p->get_y()) || isOccupied(p->get_x(), p->get_y() + 1) || isOccupied(p->get_x(), p->get_y() + 2)
				|| p->get_x() < 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_S:
		if (p->get_orientation() == 0 || p->get_orientation() == 2) {
			if (isOccupied(p->get_x() - 1, p->get_y() + 2) || isOccupied(p->get_x(), p->get_y() + 1)
				|| p->get_x() <= 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1 || p->get_orientation() == 3) {
			if (isOccupied(p->get_x(), p->get_y()) || isOccupied(p->get_x(), p->get_y() + 1) || isOccupied(p->get_x() + 1, p->get_y() + 2)
				|| p->get_x() < 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_Z:
		if (p->get_orientation() == 0 || p->get_orientation() == 2) {
			if (isOccupied(p->get_x() - 1, p->get_y() + 1) || isOccupied(p->get_x(), p->get_y() + 2)
				|| p->get_x() <= 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1 || p->get_orientation() == 3) {
			if (isOccupied(p->get_x(), p->get_y() + 1) || isOccupied(p->get_x(), p->get_y() + 2) || isOccupied(p->get_x() + 1, p->get_y())
				|| p->get_x() < 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_CRAZY:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x() - 1, p->get_y()) || isOccupied(p->get_x(), p->get_y() + 1)
				|| p->get_x() <= 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x() + 2, p->get_y()) || isOccupied(p->get_x() + 1, p->get_y() + 1) || isOccupied(p->get_x() + 1, p->get_y() + 2) || isOccupied(p->get_x() + 2, p->get_y() + 3)
				|| p->get_x() < -1)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x() - 1, p->get_y() + 3) || isOccupied(p->get_x() + 2, p->get_y() + 3)
				|| p->get_x() <= 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x()-1, p->get_y()) || isOccupied(p->get_x(), p->get_y() + 1) || isOccupied(p->get_x(), p->get_y() + 2) || isOccupied(p->get_x() - 1, p->get_y() + 3)
				|| p->get_x() <= 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() - 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_FOAM:
		if (p->get_x() < 0 || isOccupied(p->get_x(), p->get_y() + 1))
			return false;
		else {
			print_to_well(p, ' ');
			p->set_x(p->get_x() - 1);
			print_to_well(p, '#');
			return true;
		}
	default:
		return false;
	}
	return false;
}

bool Well::move_right(Piece * p)
{
	switch (p->get_type()) {
	case PIECE_O:
		if (p->get_x() >= 8 || isOccupied(p->get_x() + 2, p->get_y()) || isOccupied(p->get_x() + 2, p->get_y() + 1))
			return false;
		else {
			print_to_well(p, ' ');
			p->set_x(p->get_x() + 1);
			print_to_well(p, '#');
			return true;
		}
	case PIECE_I:
		if (p->get_orientation() == 0 || p->get_orientation() == 2) {
			if (isOccupied(p->get_x() + 4, p->get_y() + 1) || p->get_x() + 4 > 9)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1 || p->get_orientation() == 3) {
			if (isOccupied(p->get_x() + 2, p->get_y()) || isOccupied(p->get_x() + 2, p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y() + 2) || isOccupied(p->get_x() + 2, p->get_y() + 3)
				|| p->get_x() + 1 > 8)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_VAPOR:
		if (p->get_x() >= 7 || isOccupied(p->get_x() + 3, p->get_y()))
			return false;
		else {
			print_to_well(p, ' ');
			p->set_x(p->get_x() + 1);
			print_to_well(p, '#');
			return true;
		}
	case PIECE_T:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x() + 2, p->get_y()) || isOccupied(p->get_x() + 3, p->get_y() + 1)
				|| p->get_x() > 6)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x() +2, p->get_y()) || isOccupied(p->get_x() + 3, p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y() + 2)
				|| p->get_x() > 6)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x() + 3, p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y() + 2)
				|| p->get_x() > 6)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x() + 2  , p->get_y()) || isOccupied(p->get_x() + 2, p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y() + 2)
				|| p->get_x() > 7)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_L:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x() + 3, p->get_y() + 1) || isOccupied(p->get_x() + 1, p->get_y() + 2)
				|| p->get_x() > 6)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x() + 3, p->get_y()) || isOccupied(p->get_x() + 3, p->get_y() + 1) || isOccupied(p->get_x() + 3, p->get_y() + 2)
				|| p->get_x() > 6)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x() + 3, p->get_y() + 1) || isOccupied(p->get_x() + 3, p->get_y() + 2)
				|| p->get_x() > 6)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x() + 2, p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y() + 2) || isOccupied(p->get_x() + 3, p->get_y() + 3)
				|| p->get_x() > 6)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_J:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x() + 4, p->get_y() + 1) || isOccupied(p->get_x() + 4, p->get_y() + 2)
				|| p->get_x() > 5)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x() + 3, p->get_y() + 1) || isOccupied(p->get_x() + 3, p->get_y() + 2) || isOccupied(p->get_x() + 3, p->get_y() + 3)
				|| p->get_x() > 6)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x() + 2, p->get_y() + 1) || isOccupied(p->get_x() + 4, p->get_y() + 2)
				|| p->get_x() > 5)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x() + 3, p->get_y()) || isOccupied(p->get_x() + 2, p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y() + 2)
				|| p->get_x() > 6)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_S:
		if (p->get_orientation() == 0 || p->get_orientation() == 2) {
			if (isOccupied(p->get_x() + 3, p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y() + 2) ||
				p->get_x() > 6)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1 || p->get_orientation() == 3) {
			if (isOccupied(p->get_x() + 2, p->get_y()) || isOccupied(p->get_x() + 3, p->get_y() + 1) || isOccupied(p->get_x() + 3, p->get_y() + 2) 
				|| p->get_x() > 6)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_Z:
		if (p->get_orientation() == 0 || p->get_orientation() == 2) {
			if (isOccupied(p->get_x() + 2, p->get_y() + 1) || isOccupied(p->get_x() + 3, p->get_y() + 2) ||
				p->get_x() > 6)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1 || p->get_orientation() == 3) {
			if (isOccupied(p->get_x() + 3, p->get_y()) || isOccupied(p->get_x() + 3, p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y() + 2)
				|| p->get_x() > 6)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_CRAZY:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x() + 4, p->get_y()) || isOccupied(p->get_x() + 3, p->get_y() + 1)
				|| p->get_x() > 5)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x() + 4, p->get_y()) || isOccupied(p->get_x() + 3, p->get_y() + 1) || isOccupied(p->get_x() + 3, p->get_y() + 2) || isOccupied(p->get_x() + 4, p->get_y() + 3)
				|| p->get_x() > 5)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x() + 3, p->get_y() + 2) || isOccupied(p->get_x() + 4, p->get_y() + 3) || isOccupied(p->get_x() + 1, p->get_y() + 3)
				|| p->get_x() > 5)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x() + 1, p->get_y()) || isOccupied(p->get_x() + 2, p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y() + 2) || isOccupied(p->get_x() + 1, p->get_y() + 3)
				|| p->get_x() > 7)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_x(p->get_x() + 1);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_FOAM:
		if (p->get_x() > 7 || isOccupied(p->get_x() + 2, p->get_y() + 1) )
			return false;
		else {
			print_to_well(p, ' ');
			p->set_x(p->get_x() + 1);
			print_to_well(p, '#');
			return true;
		}
	default:
		return false;
	}
	return false;
}

//This is very simple to implmenet as long as move_down is correct, and is the same for all normal pices -> check special piece cases.
bool Well::move_all_the_way_down(Piece * p)
{
	while (move_down(p));
	return false;
}


//Need to consider cases where vapor bomb is too high in the well or too low in the well to avoid undefined behavior.
//Deletes a 2x5 section of the well depending on the vaporBomb's position in the well. 
bool Well::blowUpVaporBomb(Piece * p)
{
	//If it's too high
	if (p->get_y()< 2) {
		if (p->get_y() == 0) {
			m_well[p->get_x() + 1][p->get_y()] = ' ';
			m_well[p->get_x() + 1][p->get_y() + 1] = ' ';
			m_well[p->get_x() + 1][p->get_y() + 2] = ' ';

			m_well[p->get_x() + 2][p->get_y()] = ' ';
			m_well[p->get_x() + 2][p->get_y() + 1] = ' ';
			m_well[p->get_x() + 2][p->get_y() + 2] = ' ';
		}
		else if (p->get_y() == 1) {
			m_well[p->get_x() + 1][p->get_y()] = ' ';
			m_well[p->get_x() + 1][p->get_y() + 1] = ' ';
			m_well[p->get_x() + 1][p->get_y() + 2] = ' ';
			m_well[p->get_x() + 1][p->get_y() - 1] = ' ';

			m_well[p->get_x() + 2][p->get_y()] = ' ';
			m_well[p->get_x() + 2][p->get_y() + 1] = ' ';
			m_well[p->get_x() + 2][p->get_y() + 2] = ' ';
			m_well[p->get_x() + 2][p->get_y() - 1] = ' ';
		}
	}
	//It's too low
	else if (p->get_y() > 15) {
		if (p->get_y() == 16) {
			m_well[p->get_x() + 1][p->get_y()] = ' ';
			m_well[p->get_x() + 1][p->get_y() - 1] = ' ';
			m_well[p->get_x() + 1][p->get_y() - 2] = ' ';
			m_well[p->get_x() + 1][p->get_y() + 1] = ' ';

			m_well[p->get_x() + 2][p->get_y()] = ' ';
			m_well[p->get_x() + 2][p->get_y() - 1] = ' ';
			m_well[p->get_x() + 2][p->get_y() - 2] = ' ';
			m_well[p->get_x() + 2][p->get_y() + 1] = ' ';
		}
		else if (p->get_y() == 17) {
			m_well[p->get_x() + 1][p->get_y()] = ' ';
			m_well[p->get_x() + 1][p->get_y() - 1] = ' ';
			m_well[p->get_x() + 1][p->get_y() - 2] = ' ';

			m_well[p->get_x() + 2][p->get_y()] = ' ';
			m_well[p->get_x() + 2][p->get_y() - 1] = ' ';
			m_well[p->get_x() + 2][p->get_y() - 2] = ' ';
		}
	}
	else {
		m_well[p->get_x() + 1][p->get_y()] = ' ';
		m_well[p->get_x() + 1][p->get_y() - 1] = ' ';
		m_well[p->get_x() + 1][p->get_y() - 2] = ' ';
		m_well[p->get_x() + 1][p->get_y() + 1] = ' ';
		m_well[p->get_x() + 1][p->get_y() + 2] = ' ';

		m_well[p->get_x() + 2][p->get_y()] = ' ';
		m_well[p->get_x() + 2][p->get_y() - 1] = ' ';
		m_well[p->get_x() + 2][p->get_y() - 2] = ' ';
		m_well[p->get_x() + 2][p->get_y() + 1] = ' ';
		m_well[p->get_x() + 2][p->get_y() +2] = ' ';

	}
	return false;
}

//use the maze algorithm w/constraints being the well boundaries or 5x5 surrounding the bomb
//This function should be passed the point x, y where the foam bomb dropped I.E p->get(x)+1, p->get(y)+1
//The piece will be used for comparison to check if within a 5 x 5 box.
//Make sure to check for going out of bounds of the well  - visited spots are marked by '*'
bool Well::blowUpFoamBomb(Piece* p, int x, int y)
{
	m_well[x][y] = '*';

	//North
	if (y - 1 >= 0 && y-1 >= p->get_y()-1 && m_well[x][y-1] == ' ') {
		if (blowUpFoamBomb(p, x, y-1)) return true;
	}
	//West
	if (x-1 >= 0 && x - 1 >= p->get_x() - 1 && m_well[x-1][y] == ' ') {
		if (blowUpFoamBomb(p, x-1, y)) return true;
	}
	//South
	if (y + 1 <= 17 && y + 1 <= p->get_y() + 3 && m_well[x][y + 1] == ' ') {
		if (blowUpFoamBomb(p, x, y + 1)) return true;
	}
	//East
	if (x + 1 <= 9 && x + 1 <= p->get_x() +3  && m_well[x + 1][y] == ' ') {
		if (blowUpFoamBomb(p, x + 1, y)) return true;
	}
	return false;
}

//Change the orientation of a piece -> A LOT OF error checking to see if somethign is occupied 
//Check left or right out bonds, up/ down out of bounds (depends on the piece) O block is the easiest. 
//This along with the move functions is also the "meat" of the program as it handles so much boundary and collision checking.
bool Well::change_orientation(Piece * p)
{
	switch (p->get_type()) {
	//Changing the orientation doesn't do anything.
	case PIECE_O:
		if (p->get_orientation() == 0)
			p->set_orientation(1);
		else if (p->get_orientation() == 1)
			p->set_orientation(2);
		else if (p->get_orientation() == 2)
			p->set_orientation(3);
		else if (p->get_orientation() == 3)
			p->set_orientation(0);
		return true;
	case PIECE_I:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x() + 1, p->get_y()) || isOccupied(p->get_x() + 1, p->get_y() + 2) || isOccupied(p->get_x() + 1, p->get_y() + 3)
				|| p->get_y() + 4 > 17)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x(), p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y() + 1) || isOccupied(p->get_x()+3, p->get_y() + 1)
				|| p->get_x() < 0  || p->get_x() + 3 > 9)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(2);
				print_to_well(p, '#');
				return true;
			}
		}
		//Basically the same as orientation == 0
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x() + 1, p->get_y()) || isOccupied(p->get_x() + 1, p->get_y() + 2) || isOccupied(p->get_x() + 1, p->get_y() + 3)
				|| p->get_y() + 4 > 17)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(3);
				print_to_well(p, '#');
				return true;
			}
		}
		//Basically the same as orientation == 1
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x(), p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y() + 1) || isOccupied(p->get_x() + 3, p->get_y() + 1)
				|| p->get_x() < 0 || p->get_x() + 3 > 9)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(0);
				print_to_well(p, '#');
				return true;
			}
		}
		return true;
	case PIECE_VAPOR:
		if (p->get_orientation() == 0)
			p->set_orientation(1);
		else if (p->get_orientation() == 1)
			p->set_orientation(2);
		else if (p->get_orientation() == 2)
			p->set_orientation(3);
		else if (p->get_orientation() == 3)
			p->set_orientation(0);
		return true;
	case PIECE_T:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x() + 1, p->get_y() + 2)
				|| p->get_y() > 15)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x(), p->get_y() + 1)
				|| p->get_x() < 0
				)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(2);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x() + 1, p->get_y()) )
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(3);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x() + 2, p->get_y() + 1) 
				|| p->get_x() > 7)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(0);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_L:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x() + 1, p->get_y()) || isOccupied(p->get_x() + 2, p->get_y()) || isOccupied(p->get_x() + 2, p->get_y() + 2)
				|| p->get_y() > 16)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x(), p->get_y() + 2) || isOccupied(p->get_x() + 1, p->get_y() + 2)
				|| p->get_y() > 16 || p->get_x() < 0
				)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(2);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x() + 1, p->get_y() + 1) || isOccupied(p->get_x() + 1, p->get_y() + 3) || isOccupied(p->get_x() + 2, p->get_y() + 3)
				|| p->get_y() > 14)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(3);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x(), p->get_y() + 1) || isOccupied(p->get_x(), p->get_y() + 2) || isOccupied(p->get_x() + 2, p->get_y() + 1)
				|| p->get_y() > 16  || p->get_x() < 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(0);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_J:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x() + 2, p->get_y() + 2) || isOccupied(p->get_x() + 2, p->get_y() + 3) || isOccupied(p->get_x() + 1, p->get_y() + 3)
				|| p->get_y() > 14)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x() + 1, p->get_y() + 1) || isOccupied(p->get_x() + 1, p->get_y() + 2) || isOccupied(p->get_x() + 3, p->get_y() + 2)
				|| p->get_y() > 14 || p->get_x() > 6
				)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(2);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x() + 1, p->get_y()) || isOccupied(p->get_x() + 2, p->get_y()) 
				|| p->get_y() > 14)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(3);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x() + 2, p->get_y() + 1) || isOccupied(p->get_x() + 3, p->get_y() + 1) || isOccupied(p->get_x() + 3, p->get_y() + 2)
				|| p->get_y() > 14 || p->get_x() > 6)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(0);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_S:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x() + 1, p->get_y()) || isOccupied(p->get_x() +2, p->get_y() + 2) 
				|| p->get_y() > 15)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x(), p->get_y() + 2) || isOccupied(p->get_x() + 1, p->get_y() + 2) 
				|| p->get_y() > 15 || p->get_x() < 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(2);
				print_to_well(p, '#');
				return true;
			}
		}
		//Basically the same as orientation == 0
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x() + 1, p->get_y()) || isOccupied(p->get_x() + 2, p->get_y() + 2)
				|| p->get_y() > 15)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(3);
				print_to_well(p, '#');
				return true;
			}
		}
		//Basically the same as orientation == 1
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x(), p->get_y() + 2) || isOccupied(p->get_x() + 1, p->get_y() + 2)
				|| p->get_y() > 15 || p->get_x() < 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(0);
				print_to_well(p, '#');
				return true;
			}
		}
		return true;
	case PIECE_Z:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x() + 2, p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y())
				|| p->get_y() > 15)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x(), p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y() + 2)
				|| p->get_y() > 15 || p->get_x() < 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(2);
				print_to_well(p, '#');
				return true;
			}
		}
		//Basically the same as orientation == 0
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x() + 2, p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y())
				|| p->get_y() > 15)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(3);
				print_to_well(p, '#');
				return true;
			}
		}
		//Basically the same as orientation == 1
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x(), p->get_y() + 1) || isOccupied(p->get_x() + 2, p->get_y() + 2)
				|| p->get_y() > 15 || p->get_x() < 0)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(0);
				print_to_well(p, '#');
				return true;
			}
		}
		return true;
	case PIECE_CRAZY:
		if (p->get_orientation() == 0) {
			if (isOccupied(p->get_x() + 2, p->get_y() + 2) || isOccupied(p->get_x() + 3, p->get_y() + 3) 
				|| p->get_y() > 14)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(1);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 1) {
			if (isOccupied(p->get_x(), p->get_y() + 3) || isOccupied(p->get_x() + 1, p->get_y() + 2) 
				|| p->get_y() > 14 || p->get_x() < 0
				)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(2);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 2) {
			if (isOccupied(p->get_x(), p->get_y()) || isOccupied(p->get_x() + 1, p->get_y() + 1)
				|| p->get_y() > 14)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(3);
				print_to_well(p, '#');
				return true;
			}
		}
		else if (p->get_orientation() == 3) {
			if (isOccupied(p->get_x() + 2, p->get_y() + 1) || isOccupied(p->get_x() + 3, p->get_y()) 
				|| p->get_y() > 15 || p->get_x() > 6)
				return false;
			else {
				print_to_well(p, ' ');
				p->set_orientation(0);
				print_to_well(p, '#');
				return true;
			}
		}
	case PIECE_FOAM:
		if (p->get_orientation() == 0)
			p->set_orientation(1);
		else if (p->get_orientation() == 1)
			p->set_orientation(2);
		else if (p->get_orientation() == 2)
			p->set_orientation(3);
		else if (p->get_orientation() == 3)
			p->set_orientation(0);
		return true;
	default:
		return false;
	}
	return false;
}

//To clean out the well, reset all characters to ' '
//This is called at the end of the level when the well needs to be reset.
void Well::cleanWell()
{

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 18; j++) {
			m_well[i][j] = ' ';
		}
	}
}
