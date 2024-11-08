#include <iostream>
#include <vector>
using namespace std;
int N, M;	

vector<int> result;	//������� �����ص״ٰ� ��� �� ����
bool visited[9];	//�湮����

void N_M(int depth) {	
	if (depth == M) {	//���̸�ŭ �����ߴٸ� �׵��� ����� ������ ����� �Բ� ����Ѵ�.
		for (int n : result) {
			cout << n << " ";
		}
		cout << '\n';	//�ٹٲ� ���� ���� �������� �Ѿ��.
		return;
	}

	for (int i = 1; i <= N; i++) {	
		if (!visited[i]) {	//�̹� �湮�� ���� �ִٸ� �ߺ��� ������� �����Ƿ� �ǳʶٱ�
			visited[i] = true;	//�湮�� ���� ���ٸ� �ش� �ε����� �湮���θ� ������ �ٲ���.
			result.push_back(i);	//����� ����ĺ��� ���� �ڿ� �����Ѵ�.
			N_M(depth + 1);			//��������� �����Ѵ�.
			result.pop_back();		//����� ������ �� ���� ���� ���� �����Ѵ�.
			visited[i] = false;		//���� ���� ���� �湮���θ� �ٽ� �������� �ٲ��ش�.
		}
	}
}

int main() {
	cin >> N >> M;

	N_M(0);

	return 0;
}