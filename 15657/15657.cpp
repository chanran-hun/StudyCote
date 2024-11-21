#include <iostream>
#include <vector>		//arr�� result�� vector�� �����ϱ� ���� ���̺귯��
#include <algorithm>	//sort�� ����ϱ� ���� ���̺귯��
using namespace std;

int N, M;		
vector<int> arr;	//������ �Է� �� vector
vector<int> result;	//������ ��� �� vector

void N_M(int depth) {
	if (depth == M) {	//depth�� M�� �������� ������ ���
		for (int n : result) {
			cout << n << " ";
		}
		cout << '\n';
		return;			//��� �� �Լ�����
	}

	for (int i = 0; i < N; i++) {
		if (!result.empty() && result.back() > arr[i]) {	//���� ��Һ��� ������ ��Ұ� �۴ٸ� �ǳʶٱ�
			continue;
		}

		result.push_back(arr[i]);	//���� �ε����� ��Ҹ� ��� ������ ����

		N_M(depth + 1);				//�Լ� ��������� ȣ��

		result.pop_back();			//ȣ�� �� ������ ��� ����
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