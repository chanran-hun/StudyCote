#include <iostream>
using namespace std;
int Fibonachi(int index) {	//index��°�� �Ǻ���ġ �� ��ȯ
	if (index <= 1) {
		return index;
	} else {
		int pre = 0, cur = 1, next;
		for (int i = 2; i <= index; i++) {
			next = pre + cur;
			pre = cur;
			cur = next;
		}
		return cur;
	}
}

int main() {
	int index;		//�Ǻ���ġ�� �ε���
	cin >> index;	//�ε��� �Է�
	//�ε����� �ش��ϴ� �Ǻ���ġ �� ���
	cout << Fibonachi(index) << endl;

	return 0;
}