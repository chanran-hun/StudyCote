#include <iostream>
#include <vector>		//arr�� result�� vector�� �����ϱ� ���� �ʿ��� ���̺귯��.
#include <algorithm>	//sort�� ����ϱ� ���� �ʿ��� ���̺귯��.
using namespace std;

int N, M;
vector<int> arr;		//������ �Է��ϴµ� ���Ǵ� vector.
vector<int> result;		//������ ����ϴµ� ���Ǵ� vector.

void N_M(int depth) {
	if (depth == M) {	//depth�� M�� ���� ��쿡�� ����� ������ ����ϰ� �Լ��� �����մϴ�.
		for (int n : result) {
			cout << n << " ";
		}
		cout << '\n';
		return;
	}

	int lastUsed = -1;	//���� ������ ������ ��µǴ°��� �����ϴ� �����Դϴ�.
	for (int i = 0; i < N; i++) {	
		if (lastUsed == arr[i]) {	//�̹� ��µ� �����ΰ�� �ǳʶٱ� �մϴ�.
			continue;
		}
		result.push_back(arr[i]);	//result�� arr�� ���� �ε����� result�� �����ϰ� lastUsed�� ���� ���� �ε����� �ʱ�ȭ �մϴ�.
		lastUsed = arr[i];

		N_M(depth+1);	//��������� �Լ��� ȣ���մϴ�. �̶�, depth�� ���� 1 �÷��� ȣ���մϴ�.

		result.pop_back();			//���� ��� ���� ���� ������ ���� �����մϴ�.
	}
}

int main() {
	cin >> N >> M;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	N_M(0);

	return 0;
}