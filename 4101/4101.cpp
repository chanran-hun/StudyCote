#include <iostream>
using namespace std;

int main() {
	int first;	//첫 번째 정수
	int second;	//두 번째 정수

	while (1) {	
		cin >> first >> second;	//첫 번째 수와 두 번째 수를 입력합니다.
		if (first == 0 && second == 0) {	//반복문의 탈출 조건입니다. 두 정수가 모두 0 일때 탈출합니다.
			break;
		}

		if (first > second) {	//첫 번째 정수가 두 번째 정수보다 크면 "Yes"를, 그 이외의 경우에는 "No"를 출력합니다.
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
	}

	return 0;
}