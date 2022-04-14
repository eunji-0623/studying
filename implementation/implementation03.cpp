// page 115 knight

#include <iostream>
using namespace std;

int main()
{
	char c;
	int row;
	int col;
	cin >> c >> row;
	col = c - 'a' + 1;

	// all cases can go
	int step_row[8] = {-2,-2,2,2,1,-1,1,-1};
	int step_col[8] = {1,-1,1,-1,-2,-2,2,2};

	int next_row;
	int next_col;

	int cnt = 0; // count if knight can move

	for (int i = 0; i < 8; i++) {
		next_row = row + step_row[i];
		next_col = col + step_col[i];
		// is knight in the garden? check
		if (next_row >= 1 && next_row <= 8 && next_col >= 1 && next_col <= 8) {
			cnt++;
		}
	}

	// print output
	cout << cnt;

	return 0;
}
