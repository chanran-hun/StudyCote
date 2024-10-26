#include <iostream>
using namespace std;
long long count_factors(long long x, long long n) { //n!에 x가 몇번이나 곱해지는지 반환
	long long result = 0;

	for (long long i = x; i <= n; i *= x) {
		result += n / i;
	}

	return result;
}

int main() {
	long long m, n;
	cin >> n >> m;	//nCm을 구하는 것이기 때문에 n->m순서로 입력

	long long result_2;	//2가 곱해진 횟수
	long long result_5;	//5가 곱해진 횟수

	result_2 = count_factors(2, n) - count_factors(2, n - m) - count_factors(2, m);
	result_5 = count_factors(5, n) - count_factors(5, n - m) - count_factors(5, m);

	if (result_2 <= result_5) {	//더 작은것을 출력(더 작은것의 개수만큼 10이 곱해지는것이기 때문에
		cout << result_2 << endl;
	} else {
		cout << result_5 << endl;
	}

	return 0;
}