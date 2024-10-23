#include <iostream>
using namespace std;

int main() {
	int n;	//대상값
	cin >> n;

	int count = 0;	//결과값
		
	for (int i = 5; i <= n; i *= 5) {	//5가 몇개 있는지 탐색
		count += n / i;
	}
		
	cout << count << endl;	//결과값 출력

	return 0;
}