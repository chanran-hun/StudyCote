#include <iostream>
#include <list>
using namespace std;

class keyLoger {
	list<char> target;				//목표 문자열
	list<char>::iterator cursor;	//커서위치
public:
	keyLoger() {
		target = {};
		cursor = target.end();
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

	int num;
	cin >> num;							//반복횟수입력

	while (num--) {
		string password;				//비밀번호 입력 과정
		cin >> password;

		keyLoger myLoger = keyLoger();	//로거 생성
		for (char c : password) {
			if (c == '<') {				//좌측 방향키를 입력했을 때
				myLoger.move_left();
			} else if (c == '>') {		//우측 방향키를 입력했을 때
				myLoger.move_right();
			} else if (c == '-') {		//백스페이스를 입력했을 때
				myLoger.delete_left();
			} else{						//그 외의 다른 키를 입력했을 때
				myLoger.push_left(c);
			}
		}
		myLoger.show_target();			//결과 패스워드 출력
	}

	return 0;
}