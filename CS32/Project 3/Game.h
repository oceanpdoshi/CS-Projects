#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "Well.h"
#include "UserInterface.h"
#include <string>
// [Add other #include directives as necessary.]

//Game object. Game uses Piece and Well to actually run the game. In other words, this class handles the chonology
//and user input of Chetyris.
class Game
{
  public:
    Game(int width, int height);
	//Play the entirety of the Chetyris game
    void play();
	//plays one level of the chetyris game, returns true if user can move to next level, returns false if user lost
    bool playOneLevel();
	//Functions used to print prompts and the game status to the screen
    void displayPrompt(std::string s);
    void displayStatus();
	//Handles all user keyboard inputs, only returns false if user hits 'q' or 'Q' to quit out.
	//Has to delete p and q when the user quits out to prevent a memory leak.
	bool keyboardInput(Piece* p, Piece * q, Timer &t, int time);
	//Displays the next piece with it's bounding box at (16,4) on the screen coordinate system.
	void displayNextPiece(Piece* p);
	//Make a display next piece function *******
    // [Add other members as necessary.]

  private:
    Well    m_well;
    Screen  m_screen;
    int     m_level;
	int		m_score;
	int		m_rows_left;
    // [Add other members as necessary.]
};

#endif // GAME_INCLUDED
