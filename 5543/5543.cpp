#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int b1, b2, b3, c, s;	//3���� ���ſ� �ݶ�, ���̴� �Դϴ�
	int cheap_b, cheap_d;	//���� �� ����, ������Դϴ�.

	cin >> b1 >> b2 >> b3 >> c >> s;	

	cheap_b = min(b1, b2);	
	cheap_b = min(b3, cheap_b);	//cheap_b�� ���� �� ������ ������ �����ϴ� �����Դϴ�.
	cheap_d = min(c, s);		//cheap_d�� ���� �� ������ ������ �����ϴ� �����Դϴ�.

	cout << cheap_b + cheap_d - 50 << '\n';	//���� �� ���ſ� ���� �� ����� ���� �� ��Ʈ�� ������ ���ϴ� �����Դϴ�.

	return 0;
}