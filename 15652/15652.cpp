#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> result;		//����� ���� ����.
void N_M(int depth) {	//���̸� �Է¹޾Ƽ� ���������� ����ϴ�.
	if (depth == M) {	//���̰� M�� ���� �� ���
		for (int n : result) {
			cout << n << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {					//1���� �����Ͽ� N���� �ݺ�
		if (!result.empty() && i < result.back()) {	//���� ������ ũ�ų� ���ƾ� ��.
			continue;
		}
		result.push_back(i);						//���ǿ� �����Ѵٸ� ��� ������ �� �߰�
		N_M(depth + 1);								//depth ������Ű��
		result.pop_back();							//��� �� �Ŀ� ���� �ڿ� �ִ� �� ����
	}
}

int main() {
	cin >> N >> M;
	N_M(0);

	return 0;
}