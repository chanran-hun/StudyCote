#include <iostream>
#include <algorithm>
using namespace std;

class spot {	//��ǥ���� ����ü �Դϴ�.
public:
	int x;	//x��ǥ	�Դϴ�.
	int y;	//y��ǥ �Դϴ�.
};

bool compare(const spot& a, const spot& b) {
	if (a.x == b.x) return a.y < b.y; // x�� ������ y ���� ����
	return a.x < b.x; // �⺻������ x ���� ����
}

int main() {
	int n;	//��ǥ���� ���� �Դϴ�.
	cin >> n;
	spot* array = new spot[n];	//������ŭ ����ü �迭�� �Ҵ��մϴ�.
	
	for (int i = 0; i < n; i++) {
		cin >> array[i].x >> array[i].y;
	}

	sort(array, array + n, compare);	//���� ���� compare�� ��Ģ���� �Ͽ� �迭�� �����մϴ�.

	for (int i = 0; i < n; i++) {
		cout << array[i].x << " " << array[i].y << '\n';	//���ĵ� ��ǥ���� ����մϴ�.
	}

	return 0;
}