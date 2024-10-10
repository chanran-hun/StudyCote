#include <iostream>
#include <cmath>
using namespace std;
string converseToBase(int N, int B) {	//N�� B������ �ٲٱ�
	string result = "";

	while (N > 0) {
		int remainder = N % B;
		if (remainder >= 10) {
			result = char(remainder - 10 + 'A') + result;
		} else {
			result = char(remainder + '0') + result;
		}
		N /= B;
	}
	return result.empty() ? "0" : result;	//��������� 0 ���
}

int main() {
	int value = 0, base = 0;	//10������ ��ȯ�� ����
	
	cin >> value >> base;

	cout << converseToBase(value, base);

	return 0;
		
}