#include <iostream>
using namespace std;

int main() {
	int num_stone;	//돌의 개수 입니다.
	cin >> num_stone;

	if (num_stone % 2 == 0) {	
		cout << "CY" << '\n';	//돌의 개수가 짝수 일때는 2번 플레이어가 이깁니다.
	} else {
		cout << "SK" << '\n';	//돌의 개수가 홀수 일때는 1번 플레이어가 이깁니다.
	}

	return 0;
}