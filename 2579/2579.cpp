#include <iostream>
#include <vector>
#include <algorithm>	//max�˰����� ����ϱ� ���� ���̺귯�� �Դϴ�.
using namespace std;

int main() {
	int num_stairs;	//����� �� �Դϴ�.
	cin >> num_stairs;

	vector<int> stairs(num_stairs+1);	//�� ����� ������ �����մϴ�.
	for (int i = 1; i <= num_stairs; i++) {
		cin >> stairs[i];
	}

	vector<int> dp(num_stairs + 1);	//�� ��ܱ����� ���� �ִ밪�� �����մϴ�.
	dp[0] = 0;	//0��° ����� ���� ���� ���� ������ 0���� �ʱ�ȭ �մϴ�.
	dp[1] = stairs[1];	//����� �� ���� ��� ù ��° ����� ������ �ִ밪�Դϴ�.
	if (num_stairs >= 2) {	//����� �� ���� ��� ù ��° ����� ������ �� ��° ����� ������ ���� �ִ밪�Դϴ�.
		dp[2] = stairs[1] + stairs[2];
	}

	for (int i = 3; i <= num_stairs; i++) {	//�� ��° ��� ���ʹ� max�˰����� �̿��Ͽ� �ΰ��� ����� �� �� �� ������ ���� ���� �����մϴ�.
		dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
	}
	//�� ���� ����� ���� ���� i-2 ��° ���� ��ĭ�� �ö�� ���, �׸��� i-3��°���� ��ĭ�� �ö� i-1 ��°�� ���� �ű⼭ i��°�� �ö���� ��� �Դϴ�.
	cout << dp[num_stairs] << '\n';	//��ǥ�� ��ܱ��� ���� �ִ������� �� ��츦 ����մϴ�.

	return 0;
}