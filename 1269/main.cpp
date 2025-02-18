#include <iostream>
#include <unordered_set>	//�� ������ ������ �� �ʿ��� ����Դϴ�.
using namespace std;
int main() {
	int n, m;	//�� ���� A, B�� ������ �����Դϴ�.
	cin >> n >> m;

	int result = 0;	//����� �Դϴ�.

	unordered_set<int> A, B;	//�� ���� �Դϴ�.
	int num;

	for (int i = 0; i < n; i++) {
		cin >> num;
		A.insert(num);
	}

	for (int i = 0; i < m; i++) {
		cin >> num;
		B.insert(num);
	}

	for (int x : A) {	//��Ī �������� ���ϴ� �����Դϴ�. A���� �ְ� B���� ���� ������ ���� ���մϴ�.
		if (B.find(x) == B.end()) {
			result++;
		}
	}

	for (int x : B) {	//��Ī �������� ���ϴ� �����Դϴ�. B���� �ְ� A���� ���� ������ ���� ���մϴ�.
		if (A.find(x) == A.end()) {
			result++;
		}
	}

	cout << result << endl;	

	return 0;
}