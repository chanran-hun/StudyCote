#include <iostream>
#include <vector>		//pack�� dp�� vector�� �����ϱ� ���� ���̺귯��
#include <algorithm>	//max�˰����� ����ϱ� ���� ���̺귯��
using namespace std;

int main() {
	int num_pack;		//ī�� ���� �� 
	cin >> num_pack;

	vector<int> pack(num_pack + 1);		//�� ī�� ���� ������ �����մϴ�.
	vector<int> dp(num_pack + 1, 0);	//�� ������ ī�带 �� �� ���� ���� ���� ��� ��츦 �����մϴ�.

	for (int i = 1; i <= num_pack; i++) {	//ī�� ���� ������ �����ϴ� �����Դϴ�.
		cin >> pack[i];
	}

	for (int i = 1; i <= num_pack; i++) {	//���̳��� ���α׷����� �̿��Ͽ� ���� ���� ���� ��� ��츦 �����մϴ�.
		for(int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + pack[j]);	//������ ��츦 ����Ͽ� ���ϴ°��� �ٽ��Դϴ�.
		}
	}

	cout << dp[num_pack] << '\n';			//����� ����ϴ� �����Դϴ�.

	return 0;
}