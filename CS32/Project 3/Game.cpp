#include "Game.h"
#include "Well.h"
#include "UserInterface.h"
#include <string>
#include <algorithm> //This is only used for the max() function to calculate the gravity of a level

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 25;

const int WELL_X = 0;
const int WELL_Y = 0;

const int PROMPT_Y = 20;
const int PROMPT_X = 0;

const int SCORE_X = 16;
const int SCORE_Y = 8;

const int ROWS_LEFT_X = 16;
const int ROWS_LEFT_Y = 9;

const int LEVEL_X = 16;
const int LEVEL_Y = 10;

const int NEXT_PIECE_TITLE_X = 16;
const int NEXT_PIECE_TITLE_Y = 3;

const int NEXT_PIECE_X = 16;
const int NEXT_PIECE_Y = 4;

//Constructor initalizes the member variables to the values specified in specification for start of a game
Game::Game(int width, int height)
 : m_screen(SCREEN_WIDTH, SCREEN_HEIGHT), m_level(1), m_score(0), m_rows_left(5)
{
}

//Didn't edit this at all
void Game::play()
{
    m_well.display(m_screen, WELL_X, WELL_Y);
    displayStatus();  //  score, rows left, level
    displayPrompt("Press the Enter key to begin playing Chetyris!");
    waitForEnter();  // [in UserInterface.h]

    for(;;)
    {
        if ( ! playOneLevel())
            break;
        displayPrompt("Good job!  Press the Enter key to start next level!");
        waitForEnter();
        m_level++;
    }
    displayPrompt("Game Over!  Press the Enter key to exit!");
    waitForEnter();

}

//Didn't edit this at all.
void Game::displayPrompt(std::string s)     
{
    m_screen.gotoXY(PROMPT_X, PROMPT_Y);
    m_screen.printStringClearLine(s);   // overwrites previous text
    m_screen.refresh();
}

//Prints out the non-well elements such as score, lines left, level, and next piece.
void Game::displayStatus()
{
	m_screen.gotoXY(16, 3);
	m_screen.printStringClearLine("Next piece:");
	m_screen.gotoXY(16, 8);
	m_screen.printStringClearLine("Score:     " + std::to_string(m_score));
	m_screen.gotoXY(16, 9);
	m_screen.printStringClearLine("Rows left: " + std::to_string(m_rows_left));
	m_screen.gotoXY(16, 10);
	m_screen.printStringClearLine("Level:     " + std::to_string(m_level));
    // [Replace this with code to display the status.]
}

//Handles the keyboard input appropriately, and returns true if executed, return false if
//and only if 'q' or 'Q' was hit to quit out.
//Very simple except for a,4,d,6 as have to add in an extra if statement to account for the crazy_piece
//Also need to reset timer if the player hits the down arrow, also piece should immediately come to rest after user hits space bar.
bool Game::keyboardInput(Piece* p, Piece * q,  Timer& t, int time)
{
	char ch = ' ';
	if (getCharIfAny(ch)) {
		switch (ch) {
		case 'q':
			delete p;
			delete q;
			return false;
		case 'Q':
			delete p;
			delete q;
			return false;
		case 'a':
			if (p->get_type() == PIECE_CRAZY) {
				m_well.move_right(p);
				m_well.display(m_screen, WELL_X, WELL_Y);
				return true;
			}
			m_well.move_left(p);
			m_well.display(m_screen, WELL_X, WELL_Y);
			return true;
		case '4':
			if (p->get_type() == PIECE_CRAZY) {
				m_well.move_right(p);
				m_well.display(m_screen, WELL_X, WELL_Y);
				return true;
			}
			m_well.move_left(p);
			m_well.display(m_screen, WELL_X, WELL_Y);
			return true;
		case 'd':
			if (p->get_type() == PIECE_CRAZY) {
				m_well.move_left(p);
				m_well.display(m_screen, WELL_X, WELL_Y);
				return true;
			}
			m_well.move_right(p);
			m_well.display(m_screen, WELL_X, WELL_Y);
			return true;
		case '6':
			if (p->get_type() == PIECE_CRAZY) {
				m_well.move_left(p);
				m_well.display(m_screen, WELL_X, WELL_Y);
				return true;
			}
			m_well.move_right(p);
			m_well.display(m_screen, WELL_X, WELL_Y);
			return true;
		case 's':
			if (m_well.move_down(p) == false)
				return true;
			m_well.display(m_screen, WELL_X, WELL_Y);
			t.start();
			return true;
		case '2':
			if (m_well.move_down(p) == false)
				return true;
			m_well.display(m_screen, WELL_X, WELL_Y);
			t.start();
			return true;
		case ' ':
			m_well.move_all_the_way_down(p);
			m_well.display(m_screen, WELL_X, WELL_Y);
			while (t.elapsed() < time);
			return true;
		case 'w':
			m_well.change_orientation(p);
			m_well.display(m_screen, WELL_X, WELL_Y);
			return true;
		case '8':
			m_well.change_orientation(p);
			m_well.display(m_screen, WELL_X, WELL_Y);
			return true;
		default:
			return true;
		}
	}
	return true;
}

//Displays the next piece clearing out the area designated for the piece
//and depending on what piece is passed, prints out its bounding box in orientation 0 at location (16,4) on the screen
void Game::displayNextPiece(Piece * p)
{
	//upper left courner of bounding box is at 16,4 in the screen
	//Pieces are always added in the 0 orientation.
	
	//Clear before printing
	for (int x = 16; x < 20; x++) {
		for (int y = 4; y < 8; y++) {
			m_screen.gotoXY(x, y);
			m_screen.printChar(' ');
		}
	}

	switch (p->get_type()) {
	case PIECE_O:
		m_screen.gotoXY(16, 4);
		m_screen.printChar('#');
		m_screen.gotoXY(16, 5);
		m_screen.printChar('#');
		m_screen.gotoXY(17, 4);
		m_screen.printChar('#');
		m_screen.gotoXY(17, 5);
		m_screen.printChar('#');
		return;
	case PIECE_I:
		m_screen.gotoXY(16, 5);
		m_screen.printChar('#');
		m_screen.gotoXY(17, 5);
		m_screen.printChar('#');
		m_screen.gotoXY(18, 5);
		m_screen.printChar('#');
		m_screen.gotoXY(19, 5);
		m_screen.printChar('#');
		return;
	case PIECE_T:
		m_screen.gotoXY(17, 4);
		m_screen.printChar('#');
		m_screen.gotoXY(16, 5);
		m_screen.printChar('#');
		m_screen.gotoXY(17, 5);
		m_screen.printChar('#');
		m_screen.gotoXY(18, 5);
		m_screen.printChar('#');
		return;
	case PIECE_L:
		m_screen.gotoXY(16, 5);
		m_screen.printChar('#');
		m_screen.gotoXY(17, 5);
		m_screen.printChar('#');
		m_screen.gotoXY(18, 5);
		m_screen.printChar('#');
		m_screen.gotoXY(16, 6);
		m_screen.printChar('#');
		return;
	case PIECE_J:
		m_screen.gotoXY(17, 5);
		m_screen.printChar('#');
		m_screen.gotoXY(18, 5);
		m_screen.printChar('#');
		m_screen.gotoXY(19, 5);
		m_screen.printChar('#');
		m_screen.gotoXY(19, 6);
		m_screen.printChar('#');
		return;
	case PIECE_S:
		m_screen.gotoXY(16, 6);
		m_screen.printChar('#');
		m_screen.gotoXY(17, 6);
		m_screen.printChar('#');
		m_screen.gotoXY(17, 5);
		m_screen.printChar('#');
		m_screen.gotoXY(18, 5);
		m_screen.printChar('#');
		return;
	case PIECE_Z:
		m_screen.gotoXY(16, 5);
		m_screen.printChar('#');
		m_screen.gotoXY(17, 5);
		m_screen.printChar('#');
		m_screen.gotoXY(17, 6);
		m_screen.printChar('#');
		m_screen.gotoXY(18, 6);
		m_screen.printChar('#');
		return;
	case PIECE_CRAZY:
		m_screen.gotoXY(16, 4);
		m_screen.printChar('#');
		m_screen.gotoXY(17, 5);
		m_screen.printChar('#');
		m_screen.gotoXY(18, 5);
		m_screen.printChar('#');
		m_screen.gotoXY(19, 4);
		m_screen.printChar('#');
		return;
	case PIECE_FOAM:
		m_screen.gotoXY(17, 5);
		m_screen.printChar('#');
		return;
	case PIECE_VAPOR:
		m_screen.gotoXY(17, 4);
		m_screen.printChar('#');
		m_screen.gotoXY(18, 4);
		m_screen.printChar('#');
		return;
	default:
		return;
	}

}

//Follows the chronology of the spec, initalizes a level, then adds a piece and lets the player interact with piece until it comes to rest
//Repeat the piece adding/player interaction until finally, the player reaches the # of needed lines or they lose
bool Game::playOneLevel()
{

	//Initialize a timer, and use the specification's formula to determine the appropriate speed/level, set the number of rows left to 5*level
	Timer timer;
	int T = std::max(1000 - (100 * (m_level - 1)), 100);
	m_rows_left = 5 * m_level;
	
	//Clears out the last prompt and clears out any pending keys to be processed.
	m_screen.gotoXY(PROMPT_X, PROMPT_Y);
	m_screen.printStringClearLine("");
	discardPendingKeys();
	displayStatus();
	
	//Create the first random piece, and create a storage pointer.
	Piece * p =  new Piece(chooseRandomPieceType());
	Piece * q = nullptr;

	//Keep adding pieces until the level is cleared (return true) or player loses (return false)
	while (true) {

		//If reached number of vaporized lines return true; then you can go the next level, 
		//should clean out the well to prep for the next level.
		if (m_rows_left <= 0) {
			m_rows_left = 0;
			displayStatus();
			m_well.cleanWell();
			m_well.display(m_screen, WELL_X, WELL_Y);
			delete p;
			return true;
		}

		//Initialize the next random piece.
		q = new Piece(chooseRandomPieceType());
		displayNextPiece(q);

		//Need this in case user is  mashing keys while piece is coming to rest.
		discardPendingKeys();

		//If you can't add a piece you've reached the top of the stack and have lost. Otherwise teh piece is added and play continues.
		if (!m_well.addPiece(p)) {
			delete p;
			delete q;
			return false;
		}

		//Give player time react right after a piece is added before moving it down.
		m_well.display(m_screen, WELL_X, WELL_Y);
		displayStatus();
		while (timer.elapsed() < T) {
			if (keyboardInput(p,q, timer, T) == false)
				return false;
		}
		timer.start();

		//Keep moving down the piece until it comes to rest, give the player time to input commands w/keyboard.
		while (m_well.move_down(p)) {
			m_well.display(m_screen, WELL_X, WELL_Y);
			while (timer.elapsed() < T)
				if (keyboardInput(p,q, timer, T) == false) {
					return false;
				}
			timer.start();
		}

		//If p is one of the exploding types, execute the explosion
		if (p->get_type() == PIECE_VAPOR) {
			m_well.blowUpVaporBomb(p);
			m_well.display(m_screen, WELL_X, WELL_Y);
		}
		else if (p->get_type() == PIECE_FOAM) {
			m_well.blowUpFoamBomb(p, p->get_x() + 1, p->get_y() + 1);
			m_well.display(m_screen, WELL_X, WELL_Y);
		}

		//If it's not one of the exploding pieces, convert its resting spot to '$'
		if (p->get_type() != PIECE_VAPOR && p->get_type() != PIECE_FOAM) {
			m_well.print_to_well(p, '$');
			m_well.display(m_screen, WELL_X, WELL_Y);
		}

		//Check for vaporized row, and update the score and # of rows left.
		int score_counter = 0;
		for (int y = 0; y < 18; y++) {
			if (m_well.isRowFull(y)) {
				m_well.removeRow(y);
				m_rows_left--;
				score_counter++;
			}
		}
		
		if (score_counter == 1) {
			m_score += 100;
		}
		else if (score_counter == 2) {
			m_score += 200;
		}
		else if (score_counter == 3) {
			m_score += 400;
		}
		else if (score_counter == 4) {
			m_score += 800;
		}
		else if (score_counter == 5) {
			m_score += 1600;
		}
		
		//Delete the piece used for this iteration and assign the pointer to the next piece.
		delete p;
		p = q;
	}
    return false;  // [Replace this with the code to play a level.]
}
