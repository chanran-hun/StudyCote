#include <iostream>
#include <vector>
using namespace std;

int result(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    return dp[n];

}
int main() {
	int n;
	cin >> n;

    cout << result(n) << endl;

	return 0;
}