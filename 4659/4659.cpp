#include <iostream>
#include <string>
using namespace std;
void check_password(string pw) {
	for (int i = 0; i < pw.length(); i++) {
		if (pw[i] == 'a') {
			cout << "ã�Ҵ�" << '\n';
		} else if (pw[i] == 'e') {
			cout << "ã�Ҵ�" << '\n';
		} else if (pw[i] == 'i') {
			cout << "ã�Ҵ�" << '\n';
		} else if (pw[i] == 'o') {
			cout << "ã�Ҵ�" << '\n';
		} else if (pw[i] == 'u') {
			cout << "ã�Ҵ�" << '\n';
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