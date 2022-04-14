// page 110 UDLR

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	string moves; // save route

	// read input
	cin >> N;
	cin.ignore();
	getline(cin, moves);

	// coordinate. start at (1,1)
	int x = 1;
	int y = 1; 

	// start moving
	for (int i = 0; i < moves.length(); i++) {
		if (moves[i] == 'L' && y > 1) {
			y--;
		}
		else if (moves[i] == 'R' && y < N) {
			y++;
		}
		else if (moves[i] == 'U' && x > 1) {
			x--;
		}
		else if (moves[i] == 'D' && x < N) {
			x++;
		}
	}

	cout << x << " " << y;

	return 0;
}
