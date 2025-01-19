#include <iostream>
using namespace std;

int main() {
	const int size = 100;	//��ȭ���� ����, ���� ������ �Դϴ�.
	int canvas[size][size] = { 0 };	//��ȭ���� �ʱⰪ�� ��� 0���� �ʱ�ȭ �� �Ӵϴ�.

	int num_paper;	//���� �������� ���� �Դϴ�.
	cin >> num_paper;

	for (int i = 0; i < num_paper; i++) {	
		int x;	//�� �������� ���� ������ġ �Դϴ�.
		int y;	//�� �������� ���� ������ġ �Դϴ�.
		cin >> x >> y;

		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				canvas[j][k] = 1;	//��ȭ������ �����̰� ���� ��ġ�� ��� 1�� �ٲپ��ݴϴ�.
			}
		}
	}
	
	int area = 0;	//�����̰� ���� ������ ������ ������ ���� �Դϴ�.
	for (int i = 0; i < size; i++) {	//��ȭ������ 1�� �κ��� �߰ߵ� �� ���� area������ ũ�⸦ 1�� �÷��ݴϴ�.
		for (int j = 0; j < size; j++) {
			if (canvas[i][j] == 1) {
				area++;
			}
		}
	}

	cout << area << '\n';	//���� ������ ������ area�� ����մϴ�.
	
	return 0;
}