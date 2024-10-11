#include <iostream>
using namespace std;

void classifyTriangle(int a, int b, int c) {
	if (a + b + c != 180) {
		cout << "Error" << endl;
		return;
	}

	if (a == b) {
		if (b == c) {
			cout << "Equilateral" << endl;
		} else {
			cout << "Isosceles" << endl;
		}
	} else {
		if (b == c) {
			cout << "Isosceles" << endl;
		} else {
			if (a == c) {
				cout << "Isosceles" << endl;
			} else {
				cout << "Scalene" << endl;
			}
		}
	}
}

int main() {
	int a = 0, b = 0, c = 0;

	cin >> a >> b >> c;
	classifyTriangle(a, b, c);

	return 0;
}