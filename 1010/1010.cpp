#include <iostream>
using namespace std;
int combination(int a, int b) {	//bCa���� ��ȯ�մϴ�.
	if (a > b - a) {	//bCa�� bC(b-a)���� ���� ������ �ִ��� ������ Ƚ���� �ٿ��ݴϴ�.
		a = b - a;
	}

	int result = 1;

	for (int i = 0; i < a; i++) {
		result *= (b-i);	//���ϴ� ���ÿ� �������� ���� ���� ���ڰ� Ŀ���°��� �����մϴ�.
		result /= (i + 1);
	}

	return result;
}

int main() {
	int test_case;
	cin >> test_case;

	while (test_case--) {
		int west_spot;
		int east_spot;

		cin >> west_spot >> east_spot;
		cout << combination(west_spot, east_spot) << '\n';
	}

	return 0;
}