#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int value) {	//�Ҽ��Ǻ�
	if (value < 2) {		//�Ҽ��� 2���� ���ǵ�
		return false; 
	}
	//2�� 2�� ������ ���������� �Ҽ��̴�
	if (value == 2) {		
		return true;
	}	
	//¦���� ��� 2�� ���������� ������ �Ҽ��� �ƴ�
	if (value % 2 == 0) {	
		return false;
	}
	//3�����ٱ��� Ȯ���ϸ� �Ǹ� Ȧ���� Ȯ���ϸ� �ȴ�.
	for (int i = 3; i*i <= value; i += 2) {		
		if (value % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	int M, N;
	cin >> M >> N;
	//������ ���� �Ҽ����� Ȯ���ϰ� �Ҽ��϶� ���
	for (int i = M; i <= N; i++) {	
		if (isPrime(i)) {
			cout << i << endl;
		}
	}

	return 0;
}