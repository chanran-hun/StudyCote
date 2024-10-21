#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
//범위 내의 소수들을 미리 연산해두고 저장
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
//4이상의 짝수를 두 홀수 소수의 합으로 표현
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
	ios::sync_with_stdio(false); // C++의 입출력 속도 향상
	cin.tie(NULL);				// cin과 cout의 동기화 해제

	vector<bool> primes = sieve(1000000);	//소수 미리 연산해서 저장해두기
	int num;
	stringstream result;					//출력을 한번에 모아서 하기 위한 장치

	while (true) {
		cin >> num;
		if (num == 0) break;				//0이 입력되면 종료
		if (6 <= num && num <= 1000000) {	//입력범위
			Goldbach(num, primes, result);	
		}
	}

	cout << result.str();					//모아놓은 결과 출력

	return 0;
}