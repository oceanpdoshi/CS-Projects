/* Test Cases - ALL PASSED :D
#include "city.h"
int main()
{}
#include "flatulan.h"
int main()
{}
#include "game.h"
int main()
{}

#include "globals.h"
int main()
{}

#include "history.h"
int main()
{}

#include "player.h"
int main()
{}

#include "game.h"
#include "game.h"
#include "city.h"
#include "city.h"
#include "history.h"
#include "history.h"
#include "player.h"
#include "player.h"
#include "flatulan.h"
#include "flatulan.h"
#include "globals.h"
#include "globals.h"
int main()
{}

#include "history.h"
int main()
{
	history h(2, 2);
	h.record(1, 1);
	h.display();
}

#include "flatulan.h"
int main()
{
	flatulan f(nullptr, 1, 1);
}

#include "player.h"
int main()
{
	player p(nullptr, 1, 1);
}

#include "city.h"
int main()
{
	city c(10, 18);
	c.addplayer(2, 2);
}

#include "globals.h"
#include "player.h"
#include "city.h"
int main()
{
	city c(10, 20);
	player p(&c, 2, 3);
}

#include "city.h"
#include "player.h"
int main()
{
	city c(10, 20);
	player p(&c, 2, 3);
}

#include "player.h"
#include "city.h"
int main()
{
	city c(10, 20);
	player p(&c, 2, 3);
}

#include "city.h"
#include "history.h"
#include <iostream>
using namespace std;

int main()
{
	city c(2, 3);
	c.addplayer(1, 2);
	c.addflatulan(2, 1);
	c.addflatulan(2, 1);
	c.addflatulan(2, 3);
	while (c.flatulancount() != 0)
		c.preachtoflatulansaroundplayer();
	c.history().display();
	cout << "===" << endl;
}


#include "flatulan.h"
#include "city.h"
int main()
{
	city a(10, 20);
	player p(&a, 2, 3);
	flatulan f(&a, 1, 1);
}

#include "player.h"
#include "city.h"
int main()
{
	city a(10, 20);
	player p(&a, 2, 3);
	flatulan f(&a, 1, 1);
}

#include "globals.h"
#include "flatulan.h"
#include "player.h"
int main()
{
	city a(10, 10);
}

#include "history.h"
int main()
{
	history h;
}
*/

#include "Game.h"
int main()
{
	// Create a game
	// Use this instead to create a mini-game:   Game g(3, 4, 2);
	Game g(7, 8, 25);

	// Play the game
	g.play();
}