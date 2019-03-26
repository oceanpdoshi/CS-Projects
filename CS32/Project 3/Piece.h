#ifndef PIECE_INCLUDED
#define PIECE_INCLUDED

enum PieceType {
    PIECE_I, PIECE_L, PIECE_J, PIECE_T, PIECE_O, PIECE_S, PIECE_Z,
    PIECE_VAPOR, PIECE_FOAM, PIECE_CRAZY, NUM_PIECE_TYPES
};

PieceType chooseRandomPieceType();

//In my representation, Every piece is the same EXCEPT for its PieceType which is stored in a member variable..
//Therefore to construct a piece, you have to pass the PieceType to the constructor.
//The well class does all the moving and position management based upon the type of piece its given.
//No setter for the Piecetype is provided as that should never be modified.
//There is no dynamic memory allocation and all the member variables are ints or Enumerated types so 
//the default destructor and copy constructor should work fine.
class Piece {
public: 
	Piece(PieceType p);
	
	//Setters for all piece objects
	void set_x(int x);
	void set_y(int y);
	void set_orientation(int o);
	
	//Getters for all piece objects
	int get_x() const;
	int get_y() const;
	int get_orientation() const;
	PieceType get_type() const;

private:
	//Every piece has an orientation, piecetype, and x&y coordinate in the well
	int m_x;
	int m_y;
	int m_orientation;
	PieceType m_type;
};


#endif // PIECE_INCLUDED
