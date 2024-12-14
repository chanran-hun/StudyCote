#include <iostream>
using namespace std;
int combination(int a, int b) {	//bCa값을 반환합니다.
	if (a > b - a) {	//bCa와 bC(b-a)값은 같기 때문에 최대한 연산의 횟수를 줄여줍니다.
		a = b - a;
	}

	int result = 1;

	for (int i = 0; i < a; i++) {
		result *= (b-i);	//곱하는 동시에 나눗셈을 같이 해줘 숫자가 커지는것을 방지합니다.
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