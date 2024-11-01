#include <iostream>
#include <list>
using namespace std;

class editor {
	list<char> target;				//��ǥ ���ڿ�
	list<char>::iterator cursor;	//Ŀ����ġ
public:
	editor(const string& str) {		//��ǥ ���ڿ��� �Է��� �޾� �ʱ�ȭ
		for (char letter : str) {
			target.push_back(letter);
		}

		cursor = target.end();		//Ŀ�� ��ġ�� ���ڿ��� ���������� �ʱ�ȭ
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

	string target;	//���ڿ� �Է�
	cin >> target;

	editor myeditor = editor(target);	//�ش� ���ڿ��� ������ ����

	int num;
	cin >> num;							//�ݺ�Ƚ�� �Է�
	for (int i = 0; i < num; i++) {		
		char command;
		cin >> command;					//��ɾ� �Է�
		if (command == 'L') {
			myeditor.move_left();
		} else if (command == 'D') {	//��ɾ �´� �޼��� ��ȯ/����
			myeditor.move_right();
		} else if (command == 'B') {
			myeditor.delete_left();
		} else if (command == 'P') {
			cin >> command;
			myeditor.push_left(command);
		}
	}

	myeditor.show_target();				//���� ���ڿ� ���

	return 0;
}