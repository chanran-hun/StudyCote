#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int value) {	//소수판별
	if (value < 2) {		//소수는 2부터 정의됨
		return false; 
	}
	//2는 2로 나누어 떨어지지만 소수이다
	if (value == 2) {		
		return true;
	}	
	//짝수는 모두 2로 나누어지기 때문에 소수가 아님
	if (value % 2 == 0) {	
		return false;
	}
	//3제곱근까지 확인하면 되며 홀수만 확인하면 된다.
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
	//각각의 수가 소수인지 확인하고 소수일때 출력
	for (int i = M; i <= N; i++) {	
		if (isPrime(i)) {
			cout << i << endl;
		}
	}

	return 0;
}