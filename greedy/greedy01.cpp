#include <iostream>
using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// sorting
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}

	int first = arr[n - 1]; // biggest number
	int second = arr[n - 2]; // second big number

	int repeatN = m / (k + 1); // repeat number
	int remain = m % (k + 1); 

	int result;

	result = (first * k + second) * repeatN + remain * first;
	cout << result;
}

