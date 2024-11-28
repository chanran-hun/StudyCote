#include <iostream>
using namespace std;

int main() {
	int numCase;	//데이터 케이스의 수.
	cin >> numCase;

	int dp[11];		//11까지의 경우를 모두 정리해두기 위해 필요한 배열.
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 11; i++) {	//반복문을 통하여 11까지의 경우를 모두 정리해둡니다.
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	while (numCase--) {	//반복문을 통하여 데이터 케이스만큼의 인덱스를 출력합니다.
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}