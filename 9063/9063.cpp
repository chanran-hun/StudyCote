#include <iostream>
#include <algorithm>	//max�� min�� ����ϱ� ���� ���̺귯�� �Դϴ�.
using namespace std;
int main() {
	int num_marvel;	//������ ���� �Դϴ�.
	cin >> num_marvel;

	int max_x = -10000, max_y = -10000;	//�������� ���� ū x���� y�� �Դϴ�.
	int	min_x = 10000, min_y = 10000;	//�������� ���� ���� x���� y�� �Դϴ�.

	for (int i = 0; i < num_marvel; i++) {
		int x;
		int y;
		cin >> x >> y;
		max_x = max(max_x, x);	//�������� x���� y���� �Է��԰� ���ÿ� x���� �ִ�ġ�� �ּ�ġ, y���� �ִ�ġ�� �ּ�ġ�� ���������� �ʱ�ȭ �մϴ�.
		max_y = max(max_y, y);
		min_x = min(min_x, x);
		min_y = min(min_y, y);
	}	

	if (num_marvel == 1) {
		cout << 0 << '\n';	//������ ������ �� �� �϶��� ���̴� 0�� �˴ϴ�.
	} else {
		cout << (max_x - min_x) * (max_y - min_y) << '\n';	//���� ū x���� ���� ���� x���� ���� ������ ���̰� �ǰ�,
															//���� ū y���� ���� ���� y���� ���� ������ ���̰� �˴ϴ�.
	}														//�� �� ���� ���ϸ� ���簢���� ���̰� �˴ϴ�.

	return 0;
}