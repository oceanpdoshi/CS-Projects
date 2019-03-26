#include <queue>
#include <iostream>
using namespace std;

class Coord
{
public:
	Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
	int r() const { return m_r; }
	int c() const { return m_c; }
private:
	int m_r;
	int m_c;
};

bool pathExists(char maze[][10], int sr, int sc, int er, int ec) {
	queue<Coord> coordQueue;
	Coord start(sr, sc);
	Coord end(er, ec);

	//Push coordinate onto start and update maze
	coordQueue.push(start);
	maze[sr][sc] = 'E'; //E for encountered

	while (!coordQueue.empty()) {

		//Get the current coord
		Coord curr = coordQueue.front();
		coordQueue.pop();

		//if curr == end return true
		if (curr.r() == end.r() && curr.c() == end.c()) return true;

		//Check North
		if (maze[curr.r() - 1][curr.c()] == '.') {
			Coord next(curr.r() - 1, curr.c());
			coordQueue.push(next);
			maze[curr.r() - 1][curr.c()] = 'E';
		}
		//Check West
		if (maze[curr.r()][curr.c() - 1] == '.') {
			Coord next(curr.r(), curr.c() - 1);
			coordQueue.push(next);
			maze[curr.r()][curr.c() - 1] = 'E';
		}
		//Check South
		if (maze[curr.r() + 1][curr.c()] == '.') {
			Coord next(curr.r() + 1, curr.c());
			coordQueue.push(next);
			maze[curr.r() + 1][curr.c()] = 'E';
		}
		//Check East
		if (maze[curr.r()][curr.c() + 1] == '.') {
			Coord next(curr.r(), curr.c() + 1);
			coordQueue.push(next);
			maze[curr.r()][curr.c() + 1] = 'E';
		}

		//	For Testing purposes
		/*for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
		cout << maze[i][j] << ", ";
		}
		cout << endl;
		}
		cout << endl << endl << endl;
		*/
	}

	return false;
}
// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise

