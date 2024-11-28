#include <iostream>
using namespace std;

int main() {
	int numCase;	//������ ���̽��� ��.
	cin >> numCase;

	int dp[11];		//11������ ��츦 ��� �����صα� ���� �ʿ��� �迭.
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 11; i++) {	//�ݺ����� ���Ͽ� 11������ ��츦 ��� �����صӴϴ�.
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	while (numCase--) {	//�ݺ����� ���Ͽ� ������ ���̽���ŭ�� �ε����� ����մϴ�.
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}