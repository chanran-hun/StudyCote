#include <iostream>
using namespace std;

int main() {
	int scores[5];	//���� 5���� ������ ������ �迭�Դϴ�.
	int sum = 0;	//������ ������ ������ �����Դϴ�. 

	for (int i = 0; i < 5; i++) {	
		cin >> scores[i];	

		if (scores[i] < 40) {	//�Է��� ������ 40���� ���� ���, 40������ �������ִ� �۾��Դϴ�.
			scores[i] = 40;	
		}

		sum += scores[i];		//������ �����ϴ� �����Դϴ�.
	}

	cout << sum / 5 << '\n';	//������ 5�� ������ ��� ������ ����մϴ�.

	return 0;
}