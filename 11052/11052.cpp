#include <iostream>
#include <vector>		//pack과 dp를 vector로 선언하기 위한 라이브러리
#include <algorithm>	//max알고리즘을 사용하기 위한 라이브러리
using namespace std;

int main() {
	int num_pack;		//카드 팩의 수 
	cin >> num_pack;

	vector<int> pack(num_pack + 1);		//각 카드 팩의 가격을 저장합니다.
	vector<int> dp(num_pack + 1, 0);	//각 개수의 카드를 살 때 가장 돈이 많이 드는 경우를 저장합니다.

	for (int i = 1; i <= num_pack; i++) {	//카드 팩의 가격을 저장하는 과정입니다.
		cin >> pack[i];
	}

	for (int i = 1; i <= num_pack; i++) {	//다이나믹 프로그래밍을 이용하여 가장 돈이 많이 드는 경우를 저장합니다.
		for(int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + pack[j]);	//이전의 경우를 사용하여 구하는것이 핵심입니다.
		}
	}

	cout << dp[num_pack] << '\n';			//결과를 출력하는 과정입니다.

	return 0;
}