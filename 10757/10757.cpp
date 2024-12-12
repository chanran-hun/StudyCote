#include <iostream>
#include <algorithm>	//reverse ������ �ϱ� ���� �ʿ��մϴ�.
using namespace std;
string addLargeNum(string A, string B) {	//ū ���� ���� ���ڿ� ���·� ��ȯ�մϴ�
	string result = "";		//������� �����ϱ� ���� ���ڿ� �����Դϴ�.

	while (A.length() < B.length()) {	//�� ���ڿ��� ���̸� �����ִ� �����Դϴ�.
		A = "0" + A;
	}
	while (B.length() < A.length()) {
		B = "0" + B;
	}

	int carry = 0;	//�޾ƿø��� �̿��� ������ ����
	for (int i = A.length() - 1; i >= 0; i--) {		//������ �ڸ����� �� ������ �����մϴ�.
		int sum = (A[i] - '0') + (B[i] - '0') + carry;	//���� �ڸ����� �޾ƿø���, �׸��� �� ���� �� �ڸ����� �� �Դϴ�.
		carry = sum / 10;	//�޾ƿø� ���� �����մϴ�.
		result += (sum % 10) + '0';	//��������δ� �� ���� ���� 10���� ���� �������� �����մϴ�.
	}

	if (carry) {	//ù ��° �ڸ��� ���� ���� ������� 10 �̻��� ���Ӵٸ� �޾ƿ÷��� ���� ���ڿ��� �߰����ݴϴ�.
		result += carry + '0';
	}

	reverse(result.begin(), result.end());	//���� ���� �Ųٷ� ����Ǿ������Ƿ� �Ųٷ� ������ ������ ���Ͽ� ����ȭ�� ���ݴϴ�.

	return result;	//��� ���ڿ��� ��ȯ�մϴ�.
}

int main() {
	string A;
	string B;

	cin >> A >> B;
	
	cout << addLargeNum(A, B) << '\n';

	return 0;
}