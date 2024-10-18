#include <iostream>
using namespace std;

int main() {
	int N, k;	//응시자와 수상자
	cin >> N >> k;

	int x[1000];
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (x[i] < x[j]) {
				int temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}

	cout << x[k - 1];

	return 0;
}