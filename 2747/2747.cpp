#include <iostream>
using namespace std;
int Fibonachi(int index) {	//index번째의 피보나치 수 반환
	if (index <= 1) {
		return index;
	} else {
		int pre = 0, cur = 1, next;
		for (int i = 2; i <= index; i++) {
			next = pre + cur;
			pre = cur;
			cur = next;
		}
		return cur;
	}
}

int main() {
	int index;		//피보나치의 인덱스
	cin >> index;	//인덱스 입력
	//인덱스에 해당하는 피보나치 수 출력
	cout << Fibonachi(index) << endl;

	return 0;
}