#include <iostream>
#include <algorithm>	//swap알고리즘을 사용하기 위한 헤더 입니다.
using namespace std;

int main() {
	string N;	//입력할 수 입니다.
	cin >> N;

	for (int i = 0; i < N.length(); i++) {	//가장 간단한 정렬 알고리즘을 사용하였습니다.
		for (int j = 0; j < N.length()-1; j++) {
			if (N[j] < N[j + 1]) {
				swap(N[j], N[j + 1]);
			}
		}
	}

	cout << N << '\n';	//내림차순으로 정렬 된 수를 출력합니다.

	return 0;
}