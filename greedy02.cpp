#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	
	int* cardData = new int[m]; // save one line of data
	int* minValue = new int[n]; // save min values in cardData arrays

	int minV = 10000;
	int maxV = 0;
	int idx = 0; // index of minValue array

	// find min values in cardData arrays
	while (n > 0) {
		// read data
		for (int i = 0; i < m; i++)
			cin >> cardData[i];

		// find min value in cardData
		for (int i = 0; i < m; i++) {
			if (cardData[i] < minV) { // if min value
				minV = cardData[i];
			}
		}
		minValue[idx++] = minV; // save min value
		minV = 10000;
		n--;
	}

	// find max value in minValue array
	for (int i = 0; i < idx; i++) {
		if (minValue[i] > maxV) { // if max value
			maxV = minValue[i];
		}
	}

	// print final output
	cout << maxV;

	return 0;
}