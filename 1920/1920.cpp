#include <iostream>
#include <algorithm>
using namespace std;
int binarySearch(int finder, int* numbers, int low, int high) {	//����Ž��

	while ( low <= high ) {	//��������
		int mid = (low + high) / 2;

		if (finder < numbers[mid]) {	//�߰������� �������
			high = mid - 1;					
		} else if (finder == numbers[mid]) {	//�������
			return 1;
		} else {						//�߰������� Ŭ ���
			low = mid + 1;
		}
	}
	
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);  // ����� �ӵ� ����ȭ
	cin.tie(nullptr);  // cin�� cout�� ���� ����

	int* numbers;	//��� �迭
	int size;

	cin >> size;	//���迭�� ũ��
	numbers = new int[size];

	for (int i = 0; i < size; i++) {	//���迭 �Է�
		cin >> numbers[i];
	}

	sort(numbers, numbers + size);		//������������ ����

	int size2;
	int* finders;	//Ž���迭

	cin >> size2;
	finders = new int[size2];

	for (int i = 0; i < size2; i++) {	//Ž���迭 �Է�
		cin >> finders[i];
		cout << binarySearch(finders[i], numbers, 0, size - 1) << '\n';	//������
	}

	return 0;
}