#include <iostream>
#include <algorithm>	//sort�� ����ϱ� ���� ���̺귯��
using namespace std;

int main() {
	int array[3];		//ũ�Ⱑ 3�� ������ �迭�Դϴ�.
	for (int i = 0; i < 3; i++) {	//���� �� ���� �Է��մϴ�.
		cin >> array[i];
	}

	sort(array, array+3);	//sort�� ����Ͽ� ������������ �����մϴ�.
		
	for (int i = 0; i < 3; i++) {	//���ĵ� �������� ������� ����մϴ�.
		cout << array[i] << ' ';
	}

	return 0;
}