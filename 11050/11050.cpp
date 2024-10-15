#include <iostream>
using namespace std;
int factorial(int n) {	//n!값을 반환
	if (n == 0) {
		return 1;	//0!은 1임
	} else {
		return n * factorial(n - 1);	//재귀적으로 팩토리얼 값 구하기
	}
}
int main() {
	int n, k;	

	cin >> n >> k;	
	//공식을 통하여 값 구하기 : n!/(k!(n-k)!)
	cout << factorial(n) / (factorial(k) * factorial(n - k)) << endl;
	
	return 0;
}