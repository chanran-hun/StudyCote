#include <iostream>
#include <algorithm>	//reverse 연산을 하기 위해 필요합니다.
using namespace std;
string addLargeNum(string A, string B) {	//큰 수의 합을 문자열 형태로 반환합니다
	string result = "";		//결과값을 저장하기 위한 문자열 변수입니다.

	while (A.length() < B.length()) {	//두 문자열의 길이를 맞춰주는 과정입니다.
		A = "0" + A;
	}
	while (B.length() < A.length()) {
		B = "0" + B;
	}

	int carry = 0;	//받아올림에 이용할 정수형 변수
	for (int i = A.length() - 1; i >= 0; i--) {		//마지막 자리부터 합 연산을 진행합니다.
		int sum = (A[i] - '0') + (B[i] - '0') + carry;	//지난 자리에서 받아올린수, 그리고 두 수의 각 자리수의 합 입니다.
		carry = sum / 10;	//받아올림 수를 연산합니다.
		result += (sum % 10) + '0';	//결과값으로는 두 수의 합을 10으로 나눈 나머지를 저장합니다.
	}

	if (carry) {	//첫 번째 자리의 수를 합한 결과값이 10 이상이 나왓다면 받아올려진 수를 문자열에 추가해줍니다.
		result += carry + '0';
	}

	reverse(result.begin(), result.end());	//현재 수가 거꾸로 저장되어있으므로 거꾸로 뒤집는 연산을 통하여 정상화를 해줍니다.

	return result;	//결과 문자열을 반환합니다.
}

int main() {
	string A;
	string B;

	cin >> A >> B;
	
	cout << addLargeNum(A, B) << '\n';

	return 0;
}