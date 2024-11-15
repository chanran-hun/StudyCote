#include <iostream>
#include <vector>	//���͸� ����ϱ� ���� ���̺귯��
using namespace std;
int N, M;			//�������� �־��� N�� M�Դϴ�.
vector<int> result;	//���䰪�� ���� �Ŀ� �� ����Ŭ ���� ��� �� ���Դϴ�.

void N_M(int depth) {	//�������� �־��� ������ ������ ����ϴ� �Լ�
	if (depth == M) {	//������ ���̰� ��ǥġ�� �����ϰ� �Ǹ� ������ ����� �Բ� ����� �� �ٹٲ��� �մϴ�.
		for (int n : result) {	//������ ��Ҹ� ��� ����ϴ� �����Դϴ�.
			cout << n << " ";
		}
		cout << '\n';
		return;			//����� �� �Լ��� �����մϴ�.
	}

	for (int i = 1; i <= N; i++) {	//1���� N������ ���� ��Ģ�� ���� ����ϴ� ���̹Ƿ� �ش� ���ǿ� �����ϴ� �ݺ����� ����ϴ�.
		result.push_back(i);		//��� ������ ������������ ���� ����ǰ� �մϴ�.
		N_M(depth + 1);		//������ ���� �� �� ����Ǿ��� ������ ���� ������ ���̸� 1 �ø� �� ��������� �Լ��� �����մϴ�.
		result.pop_back();			//���� �Լ��� ȣ��Ǿ� ����� �� �� ��� ���� ���� ��Ҹ� ��� �������� �����մϴ�.
	}
}

int main() {
	cin >> N >> M;			//N�� M�� �Է��մϴ�.
	N_M(0);					//����� ���� �Լ��� ������ ���̸� 0���� �Ͽ� �����մϴ�.

	return 0;
}