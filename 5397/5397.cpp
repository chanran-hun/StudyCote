#include <iostream>
#include <list>
using namespace std;

class keyLoger {
	list<char> target;				//��ǥ ���ڿ�
	list<char>::iterator cursor;	//Ŀ����ġ
public:
	keyLoger() {
		target = {};
		cursor = target.end();
	}

	void move_left() {					//Ŀ���� �������� ��ĭ �ű�
		if (cursor != target.begin()) {	//���� ���ʿ� ������ �ƹ� �ϵ� �Ͼ�� ����
			cursor--;
		}
	}

	void move_right() {					//Ŀ���� ���������� ��ĭ �ű�
		if (cursor != target.end()) {	//���� �����ʿ� ������ �ƹ� �ϵ� �Ͼ�� ����
			cursor++;
		}
	}

	void delete_left() {				//Ŀ�� ������ �� ���ڸ� ����
		if (cursor != target.begin()) {	//Ŀ���� ���� ���ʿ� ������ �ƹ� �ϵ� �Ͼ�� ����
			auto temp = cursor;
			temp--;
			target.erase(temp);
		}
	}

	void push_left(char letter) {		//Ŀ���� ���ʿ� �� ���ڸ� ������
		target.insert(cursor, letter);
	}	

	void show_target() {				//Ÿ�� ���ڿ��� ������
		for (char letter : target) {
			cout << letter;
		}
		cout << '\n';
	}
};

int main() {
	std::ios::sync_with_stdio(false);	//��, ��� ����ȭ
	std::cin.tie(nullptr);

	int num;
	cin >> num;							//�ݺ�Ƚ���Է�

	while (num--) {
		string password;				//��й�ȣ �Է� ����
		cin >> password;

		keyLoger myLoger = keyLoger();	//�ΰ� ����
		for (char c : password) {
			if (c == '<') {				//���� ����Ű�� �Է����� ��
				myLoger.move_left();
			} else if (c == '>') {		//���� ����Ű�� �Է����� ��
				myLoger.move_right();
			} else if (c == '-') {		//�齺���̽��� �Է����� ��
				myLoger.delete_left();
			} else{						//�� ���� �ٸ� Ű�� �Է����� ��
				myLoger.push_left(c);
			}
		}
		myLoger.show_target();			//��� �н����� ���
	}

	return 0;
}