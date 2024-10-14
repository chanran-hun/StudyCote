#include <iostream>
#include <string>
using namespace std;

int main() {

	while (1) {
		int num;
		cin >> num;

		if (num == 0) {
			break;
		}

		string isPelindrom = to_string(num);
		string reverse = string(isPelindrom.rbegin(), isPelindrom.rend());

		if (isPelindrom == reverse) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}

	return 0;
}