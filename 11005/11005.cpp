#include <iostream>
#include <cmath>
using namespace std;
string converseToBase(int N, int B) {	//N을 B진수로 바꾸기
	string result = "";

	while (N > 0) {
		int remainder = N % B;
		if (remainder >= 10) {
			result = char(remainder - 10 + 'A') + result;
		} else {
			result = char(remainder + '0') + result;
		}
		N /= B;
	}
	return result.empty() ? "0" : result;	//비어잇으면 0 출력
}

int main() {
	int value = 0, base = 0;	//10진수와 교환할 진법
	
	cin >> value >> base;

	cout << converseToBase(value, base);

	return 0;
		
}