#include <iostream>
using namespace std;

long int absDifference(long int a, long int b) {
	if (a - b > 0) {
		return a - b;
	} else {
		return -(a - b);
	}
}

int main() {
	long int a = 0, b = 0;
	
	cin >> a >> b;
	cout << absDifference(a, b);

	return 0;
}