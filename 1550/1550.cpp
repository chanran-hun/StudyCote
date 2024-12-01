#include <iostream>
using namespace std;
int HexToDec(string target) {
	int result = 0;	//반환 할 결과값

	for (int i = 0; i < target.length(); i++) {
		if ('0' <= target[i] && target[i] <= '9') {	//자리의 수가 0~9일 경우
			int temp = target[i] - '0';				//자리의 수를 구합니다.
			for (int j = 0; j < target.length() - 1 - i; j++) {
				temp *= 16;							//그 수가 10진수로 어떤 수에 해당하는지 구합니다.
			}
			result += temp;							//결과값에 그 값을 합해줍니다.
		}

		if ('A' <= target[i] && target[i] <= 'F') {	//자리의 수가 A~F일 때의 경우로, 위의 과정과 동일합니다.
			int temp = target[i] - 'A' + 10;
			for (int j = 0; j < target.length() - 1 - i; j++) {
				temp *= 16;
			}
			result += temp;
		}
	}
	return result;	//결과값을 반환합니다.
}

int main() {
	string hexa;	
	cin >> hexa;

	cout << HexToDec(hexa) << '\n';

	return 0;
}