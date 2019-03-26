//
//  main.cpp
//  SudokuGame
//
//  Created by Howard Stahl on 11/5/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "Cell.h"
#include "Board.h"
#include "NumberSet.h"
#include "Game.h"
using namespace cs31;
using namespace std;

void clearScreen( );
void beep();

int main()
{
	//To run the Game
    using namespace cs31;
    using namespace std;
    
    clearScreen();
    
    Game game;
    game.buildRandomBoard();

    int row, column, value;
    bool result = true;
    std::string action, message = "(s)et (e)valuate (q)uit: ";
    cout << game.display( message ) << endl;
    
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                beep( );  // beep
                continue;
            case 'Q':
            case 'q':
                return 0;
            case 'S':
            case 's':
                cout << "row:";
                cin >> row;
                cout << "column:";
                cin >> column;
                cout << "value:";
                cin >> value;
                cout << endl;
                
                result = game.acceptValue( value, row, column );
                if (!result)
                    beep();  // beep
                cout << game.display( message ) << endl;
                break;
            case 'E':
            case 'e':
                cout << "evaluate:" << game.evaluate() << endl;
                cout << game.display( message ) << endl;
                break;
        }
        
    } while( !game.completed()  );
    
    return( 0 );
	
	/*
	using namespace std;
	using namespace cs31;

	// test code
	NumberSet ns(1, 2, 3, 4, 5, 6, 7, 8);

	assert(ns.notFound(0));
	assert(!ns.notFound(1));
	assert(!ns.notFound(2));
	assert(!ns.notFound(3));
	assert(!ns.notFound(4));
	assert(!ns.notFound(5));
	assert(!ns.notFound(6));
	assert(!ns.notFound(7));
	assert(!ns.notFound(8));
	assert(ns.notFound(9));



	Cell c;


	c.setValue(1);
	assert(c.getValue() == 1);
	assert(!c.isImmutable());
	c.setValue(2);
	c.setImmutable(true);
	assert(c.getValue() == 2);
	assert(c.isImmutable());

	// isValueOK does not check immutability
	assert(c.isValueOK(0, ns, ns, ns));
	assert(!c.isValueOK(1, ns, ns, ns));
	assert(!c.isValueOK(2, ns, ns, ns));
	assert(!c.isValueOK(3, ns, ns, ns));
	assert(!c.isValueOK(4, ns, ns, ns));
	assert(!c.isValueOK(5, ns, ns, ns));
	assert(!c.isValueOK(6, ns, ns, ns));
	assert(!c.isValueOK(7, ns, ns, ns));
	assert(!c.isValueOK(8, ns, ns, ns));
	assert(c.isValueOK(9, ns, ns, ns));

	// isOKToSetValue does check immutability
	assert(!c.isOKToSetValue(0, ns, ns, ns));
	assert(!c.isOKToSetValue(1, ns, ns, ns));
	assert(!c.isOKToSetValue(2, ns, ns, ns));
	assert(!c.isOKToSetValue(3, ns, ns, ns));
	assert(!c.isOKToSetValue(4, ns, ns, ns));
	assert(!c.isOKToSetValue(5, ns, ns, ns));
	assert(!c.isOKToSetValue(6, ns, ns, ns));
	assert(!c.isOKToSetValue(7, ns, ns, ns));
	assert(!c.isOKToSetValue(8, ns, ns, ns));
	assert(!c.isOKToSetValue(9, ns, ns, ns));

	Game g;
	g.cheat("123456789|.........|987321456|456987123|.........|312645978|.........|.........|.........");

	assert(g.display() == "123|456|789\n...|...|...\n987|321|456\n-----------\n456|987|123\n...|...|...\n312|645|978\n-----------\n...|...|...\n...|...|...\n...|...|...\n");
	assert(g.evaluate() == 36);
	assert(!g.completed());
	// all the cheated values are immutable
	assert(!g.acceptValue(0, 1, 1));
	assert(!g.acceptValue(7, 1, 1));
	assert(g.display() == "123|456|789\n...|...|...\n987|321|456\n-----------\n456|987|123\n...|...|...\n312|645|978\n-----------\n...|...|...\n...|...|...\n...|...|...\n");
	assert(g.evaluate() == 36);
	assert(!g.completed());
	*/
}



///////////////////////////////////////////////////////////////////////////
//  clearScreen and beep implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

// #include <windows.h>

void clearScreen()

{

	cout << endl << endl << endl << endl << endl << endl;

}

void beep()
{
    cout << '\a' << endl;
}

#endif

#ifdef __APPLE__

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

void beep()
{
    // system( "/usr/bin/osascript -e  \"beep 1\"" );
    // printf("%c", 7);
    // system( "echo $'\\a'" );
    // NSBeep();
}

#endif

#if __unix__ // not Microsoft Visual C++, not Mac, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

void beep()
{
    cout << '\a' << endl;
}

#endif

