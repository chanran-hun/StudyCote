#include <iostream>
using namespace std;
bool classifyTriangle(int a,int b, int c) {	//세변의 길이로 삼각형의 종류 분류
	if (a == 0 && b == 0 && c == 0) {
		return false;
	}

	if ((a + b > c) && (a + c > b) && (b + c > a)) {
	} else {
		cout << "Invalid" << endl;
		return true;
	}

	if (a == b) {
		if (b == c) {
			cout << "Equilateral" << endl;
			return true;
		} else {
			cout << "Isosceles" << endl;
			return true;
		}
	} else {
		if (b == c) {
			cout << "Isosceles" << endl;
			return true;
		} else {
			if (a == c) {
				cout << "Isosceles" << endl;
				return true;
			} else {
				cout << "Scalene" << endl;
				return true;
			}
		}
	}

}
int main() {
	int a, b, c;

	
	while (1) {
		cin >> a >> b >> c;
		if (!classifyTriangle(a, b, c)) {
			break;
		}
	}

	return 0;
}