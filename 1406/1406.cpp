#include <iostream>
#include <list>
using namespace std;

class editor {
	list<char> target;				//목표 문자열
	list<char>::iterator cursor;	//커서위치
public:
	editor(const string& str) {		//목표 문자열은 입력을 받아 초기화
		for (char letter : str) {
			target.push_back(letter);
		}

		cursor = target.end();		//커서 위치는 문자열의 마지막으로 초기화
	}

	void move_left() {					//커서를 왼쪽으로 한칸 옮김
		if (cursor != target.begin()) {	//가장 왼쪽에 있으면 아무 일도 일어나지 않음
			cursor--;
		}
	}

	void move_right() {					//커서를 오른쪽으로 한칸 옮김
		if (cursor != target.end()) {	//가장 오른쪽에 있으면 아무 일도 일어나지 않음
			cursor++;
		}
	}

	void delete_left() {				//커서 왼쪽의 한 글자를 지움
		if (cursor != target.begin()) {	//커서가 가장 왼쪽에 있으면 아무 일도 일어나지 않음
			auto temp = cursor;
			temp--;
			target.erase(temp);
		}
	}

	void push_left(char letter) {		//커서의 왼쪽에 한 글자를 삽입함
		target.insert(cursor, letter);	
	}

	void show_target() {				//타켓 문자열을 보여줌
		for (char letter : target) {
			cout << letter;
		}
		cout << '\n';
	}
};

int main() {
	std::ios::sync_with_stdio(false);	//입, 출력 최적화
	std::cin.tie(nullptr);

	string target;	//문자열 입력
	cin >> target;

	editor myeditor = editor(target);	//해당 문자열로 에디터 생성

	int num;
	cin >> num;							//반복횟수 입력
	for (int i = 0; i < num; i++) {		
		char command;
		cin >> command;					//명령어 입력
		if (command == 'L') {
			myeditor.move_left();
		} else if (command == 'D') {	//명령어에 맞는 메서드 소환/실행
			myeditor.move_right();
		} else if (command == 'B') {
			myeditor.delete_left();
		} else if (command == 'P') {
			cin >> command;
			myeditor.push_left(command);
		}
	}

	myeditor.show_target();				//변한 문자열 출력

	return 0;
}