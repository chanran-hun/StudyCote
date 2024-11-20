#include <iostream>
#include <vector>		//result, arr, visited ��� vector�ڷᱸ���� �����.
#include <algorithm>	//sort�� ����ϱ� ���� �ʿ��� ���̺귯��
using namespace std;

int N, M;				
vector<int> arr;		//�Է��� ���� ������ �� ����
vector<int> result;		//������� ����ϴµ� ����� ����
vector<bool> visited;	//������ �湮���θ� ǥ���� ����

void N_M(int depth) {	//���̿� �����ϰ� �� �� ����ϴ� �Լ�
	if (depth == M) {
		for (int n : result) {
			cout << n << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) {	//�̹� �湮�� ���� �ǳʶٱ�
			continue;
		}

		result.push_back(arr[i]);	//���� �߰��ϰ� �湮���θ� ������ ����
		visited[i] = true;

		N_M(depth + 1);		//�Լ� ��������� ȣ��

		result.pop_back();	//���� �����ϰ� �湮���θ� �������� ����
		visited[i] = false;
	}
}

int main() {
	cin >> N >> M;

	arr.resize(N);
	visited.resize(N, false);	//arr�� visited�� �ùٸ� ���� ũ��� ����

	for (int i = 0; i < N; i++) {	//arr�� ������ ������ �Է�
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());	//arr�� ��ҵ��� ������������ ����
	N_M(0);

	return 0;
}