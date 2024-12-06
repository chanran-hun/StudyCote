#include <iostream>
#include <vector>		//걸리는 기간, 받는 보수, 그리고 dp를 vector로 정리하기 위해 필요합니다.
#include <algorithm>	//max연산을 위해서 필요합니다.
using namespace std;

int main() {
	int remainDays;	//남은 근무 일수
	cin >> remainDays;

	vector<int> T(remainDays + 1), P(remainDays + 1), dp(remainDays + 2, 0);

	for (int i = 1; i <= remainDays; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = remainDays; i >= 1; i--) {	//마지막일수 부터 고력하여 점점 감소하는 방식으로 진행합니다.
		if (i + T[i] - 1 <= remainDays) {	//상담을 진행 할 수 있을 경우의 연산입니다.
			dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
		} else {							//상담 진행이 불가능할 경우의 연산입니다.
			dp[i] = dp[i + 1];
		}
	}

	cout << dp[1] << '\n';					//최대값을 출력합니다.

	return 0;
}