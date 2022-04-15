// page 152 미로 탈출

#include <iostream>
#include <queue>>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	// declare arr[N][M]
	int** arr = new int* [N];
	for (int i = 0; i < N; i++)
		arr[i] = new int [M];

	// read input
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	int x = 0;
	int y = 0; // position
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = { 0, 0, -1, 1 }; // direction  U, D, L, R
	int nx, ny; // next_x, next_y
	queue<pair<int,int>> q; // queue that can store (x, y)

	q.push(pair<int,int>(x, y)); // initial position (0, 0) 

	// bfs
	while (q.empty() == false) { // repeat until queue is empty
		x = q.front().first;
		y = q.front().second;
		q.pop();

		// check U,D,L,R
		for (int i = 0; i < 4; i++) { 
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) { // range over
				continue;
			}
			if (arr[nx][ny] == 0) { // monster block
				continue;
			}
			if (arr[nx][ny] == 1) { // can move			
				arr[nx][ny] = arr[x][y] + 1;
				q.push(pair<int,int>(nx, ny));
			}
		}
	}

	// print output
	cout << arr[N - 1][M - 1];

	return 0;

}
