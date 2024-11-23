#include <iostream>
#include <vector>		//arr, result, visited�� vector�� �����ϱ� ���� ���̺귯��
#include <algorithm>	//sort�� ����ϱ� ���� �˰���
using namespace std;

int N, M;
vector<int> arr;		//������ �Է��� vector
vector<int> result;		//������ ����� vector
vector<bool> visited;	//�ε����� �湮 ���θ� ������ vector

void N_M(int depth) {	
	if (depth == M) {	//depth�� M�� ���� �� result�� ���빰�� ����� �� �Լ��� �����մϴ�.
		for (int n : result) {
			cout << n << " ";
		}
		cout << '\n';
		return;
	}
	int lastUsed = -1;	//���� �ֱٿ� �߰��� ���� �����մϴ�.
	for (int i = 0; i < N; i++) {
		if ((!result.empty() && result.back() > arr[i]) || lastUsed == arr[i] || visited[i]) {
			continue;	//���� ������ ������ �߰����� �ʵ��� �ϰ�, �񳻸������� �ǵ��� ���ݴϴ�.
		}
		result.push_back(arr[i]);	//���� �߰��� ���Ŀ� �湮���θ� ������ �ٲ��ְ� ���� �ֱٿ� �߰��� ���� �ʱ�ȭ ���ݴϴ�.
		visited[i] = true;
		lastUsed = arr[i];

		N_M(depth + 1);	//�Լ��� ��������� ȣ���մϴ�.

		result.pop_back();	//���� ���� ��Ҹ� �����ϰ� �湮���ε� �������� �ٲ��ݴϴ�.
		visited[i] = false;
	}
}

int main() {
	cin >> N >> M;	
	arr.resize(N);	
	visited.resize(N, false);
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	N_M(0);

	return 0;
}