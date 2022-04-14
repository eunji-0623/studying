#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int cnt = 0; // count number of repetitions

	while (true)
	{
		if (n == 1) // escape condition
			break;

		// is divisible ? check
		if (n % k == 0) { // CAN division
			n = n / k; 
		}
		else { // CAN NOT division
			n = n - 1;
		}
		cnt++;
	}

	// print output
	cout << cnt;

	return 0;
}