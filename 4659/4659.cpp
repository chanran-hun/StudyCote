#include <iostream>
#include <string>
using namespace std;
void check_password(string pw) {
	for (int i = 0; i < pw.length(); i++) {
		if (pw[i] == 'a') {
			cout << "찾았다" << '\n';
		} else if (pw[i] == 'e') {
			cout << "찾았다" << '\n';
		} else if (pw[i] == 'i') {
			cout << "찾았다" << '\n';
		} else if (pw[i] == 'o') {
			cout << "찾았다" << '\n';
		} else if (pw[i] == 'u') {
			cout << "찾았다" << '\n';
		}
	}
}

int main() {
	string password;

	while (true) {
		cin >> password;
		if (password == "end") {
			break;
		} else {
			check_password(password);
		}
	}

	return 0;
}