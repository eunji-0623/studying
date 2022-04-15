// page 149 음료수 얼려 먹기

#include <iostream>
#include <stack>
using namespace std;

int N, M;

bool DFS(int x, int y, int** arr)
{
	if (x < 0 || x >= N || y < 0 || y >= M) { // outside the range
		return false;
	}
	// if (x, y) not visited
	if (arr[x][y] == 0) {
		// (x, y) -> visited
		arr[x][y] = 1;
		DFS(x - 1, y, arr); // left
		DFS(x + 1, y, arr); // right
		DFS(x, y - 1, arr); // down
		DFS(x, y + 1, arr); // up
		return true;
	}
	return false;
}

int main()
{
	cin >> N >> M;

	// create arr[N][M]
	int** arr = new int* [N];
	for (int i = 0; i < N; i++)
		arr[i] = new int[M];

	// read input
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	int res = 0; // number of icecream

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (DFS(i, j, arr) == true) {
				res++;
			}
		}
	}

	// print output
	cout << res;

	return 0;                                                                              
}
