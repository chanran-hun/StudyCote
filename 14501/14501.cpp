#include <iostream>
#include <vector>		//�ɸ��� �Ⱓ, �޴� ����, �׸��� dp�� vector�� �����ϱ� ���� �ʿ��մϴ�.
#include <algorithm>	//max������ ���ؼ� �ʿ��մϴ�.
using namespace std;

int main() {
	int remainDays;	//���� �ٹ� �ϼ�
	cin >> remainDays;

	vector<int> T(remainDays + 1), P(remainDays + 1), dp(remainDays + 2, 0);

	for (int i = 1; i <= remainDays; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = remainDays; i >= 1; i--) {	//�������ϼ� ���� ����Ͽ� ���� �����ϴ� ������� �����մϴ�.
		if (i + T[i] - 1 <= remainDays) {	//����� ���� �� �� ���� ����� �����Դϴ�.
			dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
		} else {							//��� ������ �Ұ����� ����� �����Դϴ�.
			dp[i] = dp[i + 1];
		}
	}

	cout << dp[1] << '\n';					//�ִ밪�� ����մϴ�.

	return 0;
}