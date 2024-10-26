#include <iostream>
using namespace std;
long long count_factors(long long x, long long n) { //n!�� x�� ����̳� ���������� ��ȯ
	long long result = 0;

	for (long long i = x; i <= n; i *= x) {
		result += n / i;
	}

	return result;
}

int main() {
	long long m, n;
	cin >> n >> m;	//nCm�� ���ϴ� ���̱� ������ n->m������ �Է�

	long long result_2;	//2�� ������ Ƚ��
	long long result_5;	//5�� ������ Ƚ��

	result_2 = count_factors(2, n) - count_factors(2, n - m) - count_factors(2, m);
	result_5 = count_factors(5, n) - count_factors(5, n - m) - count_factors(5, m);

	if (result_2 <= result_5) {	//�� �������� ���(�� �������� ������ŭ 10�� �������°��̱� ������
		cout << result_2 << endl;
	} else {
		cout << result_5 << endl;
	}

	return 0;
}