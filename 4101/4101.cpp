#include <iostream>
using namespace std;

int main() {
	int first;	//ù ��° ����
	int second;	//�� ��° ����

	while (1) {	
		cin >> first >> second;	//ù ��° ���� �� ��° ���� �Է��մϴ�.
		if (first == 0 && second == 0) {	//�ݺ����� Ż�� �����Դϴ�. �� ������ ��� 0 �϶� Ż���մϴ�.
			break;
		}

		if (first > second) {	//ù ��° ������ �� ��° �������� ũ�� "Yes"��, �� �̿��� ��쿡�� "No"�� ����մϴ�.
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
	}

	return 0;
}