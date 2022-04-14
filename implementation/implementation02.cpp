// page 113 ½Ã°¢

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int cnt = 0; // count if 3 is included
	string s; // convert int to string
	
	for (int i = 0; i <= N; i++) { // hour
		for (int j = 0; j < 60; j++) { // min
			for (int k = 0; k < 60; k++) { // sec
				s = to_string(i * 10000 + j * 100 + k); // int -> string
				for (int q = 0; q < s.length(); q++) {
					if (s[q] == '3') {// if 3 is included
						cnt++;
						break; // avoid duplication
					}
				}
			}
		}
	}

	// print output
	cout << cnt;

	return 0;
}
