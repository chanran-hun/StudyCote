#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	int num;
	cin >> num;		//반복횟수 입력
	cin.ignore();	//num 입력 이후의 줄바꿈을 무시

	while (num--) {				//num이 0이 될 때 까지 1씩 감소시키며 반복
		string sentence;		//전체 문장
		getline(cin, sentence);	//줄 단위 입력(string 라이브러리 필요)

		stack<char> word;
		for (char letter : sentence) {
			if (letter == ' ') {
				while (!word.empty()) {
					cout << word.top();
					word.pop();
				}
				cout << " ";
			} else {
				word.push(letter);
			}
		}

		while (!word.empty()) {
			cout << word.top();  
			word.pop();
		}
		cout << endl;
	}

	return 0;
}