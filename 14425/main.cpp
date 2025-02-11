#include <iostream>
#include <algorithm>	//sort�� binary_search�� ����ϱ� ���� ��� �Դϴ�.
using namespace std;

int main() {
	int N, M;	//���� ������ ���ڿ� ���� N�� �˻縦 �ǽ��� ���ڿ� ���� M �Դϴ�.
	int result = 0;	//������� ������ ���� result�Դϴ�.
	cin >> N >> M;


	string* S = new string[N];	//������ �迭�� �����ϴ� �����Դϴ�.

	for (int i = 0; i < N; i++) {	
		cin >> S[i];
	}

	sort(S, S + N);	//���� ������ ���ڿ��� �����ϴ� ���� �Դϴ�.
	string input;
	for (int i = 0; i < M; i++) {
		cin >> input;
		if (binary_search(S, S + N, input)) {	//����Ž�� ������ ���Ͽ� ���ڿ��� �˻��ϴ� ���� �Դϴ�.
			result++;
		}
	}

	cout << result << endl;	

	return 0;
}