#include <iostream>
#include <string>
using namespace std;

int power(char base, int exponent) { //base^exponent��ȯ
	if (exponent == 0) {
		return 1;
	}
	else {
		return base * power(base, exponent - 1);
	}
}

int main() {
	string num;		//N������ ��
	int base = 0;	//N������ N
	int result = 0;	//10������ ǥ���� �����

	cin >> num >> base;	//N������ ǥ���� ���� N�� �Է��Ѵ�

	for (int i = 0; i < num.length(); i++) {	
		if ('0' <= num[i] && num[i] <= '9') {	//string���� �ѱ��� �ѱ��ڸ� 10������ ��������� �ش��ϴ����� ��ȯ�ؾ���
			num[i] -= '0';
			result += num[i] * power(base, num.length() - 1 - i);	//�ڸ����� �°� ���ؼ� ������� ��ġ��
			continue;
		}

		if ('A' << num[i] && num[i] <= 'Z') {
			num[i] -= 55;
			result += num[i] * power(base, num.length() - 1 - i);
		}
	}

	cout << result << endl; //����� ���

	return 0;
}