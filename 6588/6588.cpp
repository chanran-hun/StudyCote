#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
//���� ���� �Ҽ����� �̸� �����صΰ� ����
vector<bool> sieve(int max) {	
	vector<bool> primes(max + 1, true);
	primes[0] = primes[1] = false;

	for (int i = 2; i * i <= max; i++) {
		if (primes[i] == true) {
			for (int j = i * i; j <= max; j += i) {
				primes[j] = false;
			}
		}
	}

	return primes;
}
//4�̻��� ¦���� �� Ȧ�� �Ҽ��� ������ ǥ��
void Goldbach(int value, const vector<bool>& primes, stringstream& result) {	 
	if (value < 4 || value % 2 != 0) {
		return;
	}

	for (int i = 2; i <= value/2; i++) {
		if (primes[i] && primes[value - i]) {
			result << value << " = " << i << " + " << value - i << endl;
			return;
		}
	}

	result << "Goldbach's conjecture is wrong." << endl;
}

int main() {
	ios::sync_with_stdio(false); // C++�� ����� �ӵ� ���
	cin.tie(NULL);				// cin�� cout�� ����ȭ ����

	vector<bool> primes = sieve(1000000);	//�Ҽ� �̸� �����ؼ� �����صα�
	int num;
	stringstream result;					//����� �ѹ��� ��Ƽ� �ϱ� ���� ��ġ

	while (true) {
		cin >> num;
		if (num == 0) break;				//0�� �ԷµǸ� ����
		if (6 <= num && num <= 1000000) {	//�Է¹���
			Goldbach(num, primes, result);	
		}
	}

	cout << result.str();					//��Ƴ��� ��� ���

	return 0;
}