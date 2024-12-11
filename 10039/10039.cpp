#include <iostream>
using namespace std;

int main() {
	int scores[5];	//점수 5개를 저장할 정수형 배열입니다.
	int sum = 0;	//총합을 저장할 정수형 변수입니다. 

	for (int i = 0; i < 5; i++) {	
		cin >> scores[i];	

		if (scores[i] < 40) {	//입력한 점수가 40보다 작을 경우, 40점으로 보정해주는 작업입니다.
			scores[i] = 40;	
		}

		sum += scores[i];		//총합을 저장하는 과정입니다.
	}

	cout << sum / 5 << '\n';	//총합을 5로 나누어 평균 점수를 출력합니다.

	return 0;
}