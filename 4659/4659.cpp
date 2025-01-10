#include <iostream>
#include <string>
using namespace std;
bool is_vowel(char letter) {
	return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u';
}

bool condition1(const string& pw) {
	for (char ch : pw) {
		if (is_vowel(ch)) {
			return true;
		}
	}
	return false;
}

bool condition2(const string& pw) {
	int count = 0;
	bool previous = is_vowel(pw[0]);

	for (char ch : pw) {
		bool current = is_vowel(ch);
		if (previous == current) {
			count++;
			if (count >= 3) {
				return false;
			}
		} else {
			count = 1;
			previous = current;
		}
	}

	return true;
}

bool condition3(const string& pw) {
	for (int i = 1; i < pw.length(); i++) {
		if (pw[i] == pw[i - 1] && pw[i] != 'o' && pw[i] != 'e') {
			return false;
		}
	}
	return true;
}

bool is_acceptable(const string& pw) {
	return condition1(pw) && condition2(pw) && condition3(pw);
}

int main() {
	string password;

	while (true) {
		cin >> password;
		if (password == "end") {
			break;
		}
			
		if (is_acceptable(password)) {
			cout << "<" << password << ">" << " is acceptable." << '\n';
		} else {
			cout << "<" << password << ">" << " is not acceptable." << '\n';
		}
	}

	return 0;
}