#include <iostream>
using namespace std;

int main() {
	int num_stone;	//���� ���� �Դϴ�.
	cin >> num_stone;

	if (num_stone % 2 == 0) {	
		cout << "CY" << '\n';	//���� ������ ¦�� �϶��� 2�� �÷��̾ �̱�ϴ�.
	} else {
		cout << "SK" << '\n';	//���� ������ Ȧ�� �϶��� 1�� �÷��̾ �̱�ϴ�.
	}

	return 0;
}