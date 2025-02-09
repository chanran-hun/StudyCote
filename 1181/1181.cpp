#include <iostream>
#include <algorithm>
using namespace std;
bool compare(const string& a, const string& b) {
	int length = min(a.length(), b.length());	//�� ª�� ���ڿ��� ���̸� �����մϴ�.

	if (a.length() < b.length()) {	//���ڿ��� ���̸� ���մϴ�.
		return true;				//ª������ �տ� ������ �մϴ�.
	} else if (a.length() > b.length()) {
		return false;
	} else {						//���ڿ��� ���̰� ���� ����Դϴ�.
		for (int i = 0; i < length; i++) {	//������ �񱳽ÿ� ª�� ���ڿ��� ���̿� ���� ���մϴ�.
			if (a[i] < b[i]) return true;	//���̰� ���� ���� ���������� �����մϴ�.
			if (a[i] > b[i]) return false;
		}
	}

	return a.length() < b.length();
}
int main() {
	int N;	//���ڿ��� ���� �Դϴ�.
	cin >> N;

	string* array = new string[N];	//���ڿ��� ������ŭ �迭�� �Ҵ��մϴ�.

	for (int i = 0; i < N; i++) {	//���ڿ����� �Է��մϴ�.
		cin >> array[i];
	}

	sort(array, array + N, compare);	//���ڿ��� compare��� �������� �����մϴ�.

	cout << array[0] << endl;	//���ĵ� ���ڿ��� ����մϴ�.
	for (int i = 1; i < N; i++) {
		if (array[i] != array[i - 1]) {	//�� ��, �ߺ��Ǵ� ���ڿ��� �ϳ��� ����մϴ�.
			cout << array[i] << '\n';
		}
	}

	return 0;
}