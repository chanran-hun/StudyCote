#include <iostream>
using namespace std;
int factorial(int n) {	//n!���� ��ȯ
	if (n == 0) {
		return 1;	//0!�� 1��
	} else {
		return n * factorial(n - 1);	//��������� ���丮�� �� ���ϱ�
	}
}
int main() {
	int n, k;	

	cin >> n >> k;	
	//������ ���Ͽ� �� ���ϱ� : n!/(k!(n-k)!)
	cout << factorial(n) / (factorial(k) * factorial(n - k)) << endl;
	
	return 0;
}