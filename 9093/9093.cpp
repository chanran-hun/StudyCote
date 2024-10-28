#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	int num;
	cin >> num;		//�ݺ�Ƚ�� �Է�
	cin.ignore();	//num �Է� ������ �ٹٲ��� ����

	while (num--) {				//num�� 0�� �� �� ���� 1�� ���ҽ�Ű�� �ݺ�
		string sentence;		//��ü ����
		getline(cin, sentence);	//�� ���� �Է�(string ���̺귯�� �ʿ�)

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