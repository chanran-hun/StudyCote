#include <iostream>
#include <vector>
#include <algorithm>	//max알고리즘을 사용하기 위한 라이브러리 입니다.
using namespace std;

int main() {
	int num_stairs;	//계단의 수 입니다.
	cin >> num_stairs;

	vector<int> stairs(num_stairs+1);	//각 계단의 점수를 저장합니다.
	for (int i = 1; i <= num_stairs; i++) {
		cin >> stairs[i];
	}

	vector<int> dp(num_stairs + 1);	//각 계단까지의 점수 최대값을 저장합니다.
	dp[0] = 0;	//0번째 계단을 밟을 일은 없기 때문에 0으로 초기화 합니다.
	dp[1] = stairs[1];	//계단이 한 개일 경우 첫 번째 계단의 점수가 최대값입니다.
	if (num_stairs >= 2) {	//계단이 두 개일 경우 첫 번째 계단의 점수와 두 번째 계단의 점수의 합이 최대값입니다.
		dp[2] = stairs[1] + stairs[2];
	}

	for (int i = 3; i <= num_stairs; i++) {	//세 번째 계산 부터는 max알고리즘을 이용하여 두가지 경우의 수 중 더 점수가 높은 쪽을 저장합니다.
		dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
	}
	//두 가지 경우의 수는 각각 i-2 번째 에서 두칸을 올라온 경우, 그리고 i-3번째에서 두칸을 올라가 i-1 번째로 가고 거기서 i번째로 올라오는 경우 입니다.
	cout << dp[num_stairs] << '\n';	//목표한 계단까지 가장 최대점수로 온 경우를 출력합니다.

	return 0;
}