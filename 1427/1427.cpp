#include <iostream>
#include <algorithm>	//swap�˰����� ����ϱ� ���� ��� �Դϴ�.
using namespace std;

int main() {
	string N;	//�Է��� �� �Դϴ�.
	cin >> N;

	for (int i = 0; i < N.length(); i++) {	//���� ������ ���� �˰����� ����Ͽ����ϴ�.
		for (int j = 0; j < N.length()-1; j++) {
			if (N[j] < N[j + 1]) {
				swap(N[j], N[j + 1]);
			}
		}
	}

	cout << N << '\n';	//������������ ���� �� ���� ����մϴ�.

	return 0;
}