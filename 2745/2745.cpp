#include <iostream>
#include <string>
using namespace std;

int power(char base, int exponent) { //base^exponent반환
	if (exponent == 0) {
		return 1;
	}
	else {
		return base * power(base, exponent - 1);
	}
}

int main() {
	string num;		//N진수의 수
	int base = 0;	//N진수의 N
	int result = 0;	//10진수로 표현한 결과값

	cin >> num >> base;	//N진수로 표현된 수와 N을 입력한다

	for (int i = 0; i < num.length(); i++) {	
		if ('0' <= num[i] && num[i] <= '9') {	//string안의 한글자 한글자를 10진수의 어느정도에 해당하는지를 변환해야함
			num[i] -= '0';
			result += num[i] * power(base, num.length() - 1 - i);	//자릿수에 맞게 곱해서 결과값에 합치기
			continue;
		}

		if ('A' << num[i] && num[i] <= 'Z') {
			num[i] -= 55;
			result += num[i] * power(base, num.length() - 1 - i);
		}
	}

	cout << result << endl; //결과값 출력

	return 0;
}