// page 118 game development

#include <iostream>
using namespace std;

int dir; // character's direction.   0->N   1->E   2->S   3->W

void turn_left()
{
	dir -= 1;
	if (dir == -1)
		dir = 3;
}

int main()
{
	int h, w; // height, width
	cin >> h >> w;

	// pos[h][w]. for character's visit history
	int** pos = new int*[h]; 
	for (int i = 0; i < h; i++)
		pos[i] = new int[w];

	// pos array initialize
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			pos[i][j] = 0;

	// map[h][w]. for map information
	int** map = new int* [h]; 
	for (int i = 0; i < h; i++)
		map[i] = new int[w];

	int x, y; // character's start position
	cin >> x >> y >> dir;

	pos[x][y] = 1; // start position -> visited
	
	// read input for map info
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> map[i][j];

	// direction  N,E,S,W
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };

	int cnt = 1; // count visited block
	int turn = 0;
	int nx, ny; // next x, next y
	while (true) {
		turn_left();
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (pos[nx][ny] == 0 && map[nx][ny] == 0) { // if (nx,ny) is not visited & not ocean
			x = nx;
			y = ny;
			pos[nx][ny] = 1;
			cnt++;
			turn = 0;
			continue;
		}
		else { // if (nx,ny) is visited or ocean
			turn++;
		}

		if (turn == 4) { // can't go all direction
			nx = x - dx[dir];
			ny = y - dy[dir];
			if (map[nx][ny] == 0) { // back is not ocean
				x = nx;
				y = ny;
			}
			else { // back is ocean -> stop
				break;
			}
			turn = 0;
		}
	}

	// print output
	cout << cnt;

	return 0;
}
