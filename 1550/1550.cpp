#include <iostream>
using namespace std;
int HexToDec(string target) {
	int result = 0;

	for (int i = 0; i < target.length(); i++) {
		if ('0' <= target[i] && target[i] <= '9') {
			int temp = target[i] - '0';
			for (int j = 0; j < target.length() - 1 - i; j++) {
				temp *= 16;
			}
			result += temp;
		}

		if ('A' <= target[i] && target[i] <= 'F') {
			int temp = target[i] - 'A' + 10;
			for (int j = 0; j < target.length() - 1 - i; j++) {
				temp *= 16;
			}
			result += temp;
		}
	}
	return result;
}

int main() {
	string hexa;	
	cin >> hexa;

	cout << HexToDec(hexa) << '\n';

	return 0;
}