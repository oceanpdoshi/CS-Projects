#ifndef WELL_INCLUDED
#define WELL_INCLUDED
#include "Piece.h"
#include<vector>

class Screen;

//This class does the majority of the work of the program as its functions do the boundary and collision checking.
//This is represnted as a simple 2D character array of the well size specified in the design document.
//The functions make generous usage of switch statements to execute different changes to the 2D array depending on the piece passed 
//and its type/orientation. (WELL uses PIECES)
class Well
{
public:
	//Constructs an empty well to the appropriate size, an empty spot is represented by the character ' '
	Well();

	//Prints the well
	void display(Screen& screen, int x, int y) const;

	//If the well isn't full, adds a piece to (3,0) and returns true, otherwise returns false.
	bool addPiece(Piece* p);
	
	//Inserts the passed piece into the well, it should be passed '#', ' ', '*', or '$' depending on wheter the piece has reached the bottom,
	//it's a foam  bomb, or the piece is being removed, or the piece is simply being printed.
	void print_to_well(Piece* p, char c);
	
	//Checks if the specified spot in the well is occupied
	bool isOccupied(int x,  int y) const;

	//Checks if a row at the given y is full
	bool isRowFull(int y) const;

	//removes the row at the given y and shifts down all the rows above the passed y
	void removeRow(int y);

	//Move the passed piece up, down, left right, or all way down.
	bool move_down(Piece* p);
	bool move_left(Piece* p);
	bool move_right(Piece* p);
	bool move_all_the_way_down(Piece* p);

	//Executes the special piece commands for the vapor bomb thus deleting a 2x 5
	bool blowUpVaporBomb(Piece * p);

	//Utilizes recursion and previous maze algorithm bounded to a 5x5 box (or the boundaries of the well.)
	//Explodes the Foam Bomb as per the specifications.
	bool blowUpFoamBomb(Piece * p, int x, int y);

	//Change the orientation of a piece - will need a lot of specifics and error checking in here depending on the piece passed.
	bool change_orientation(Piece* p);

	//Cleans up the well to get ready for the next level.
	void cleanWell();
	
private:
	//Each well is represented by a character array to be printed to the screen and accessed to determine the status of the well. 
	//(Well USES pieces and game uses well to check the well's status)
	char m_well[10][18];
};

#endif // WELL_INCLUDED
