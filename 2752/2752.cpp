#include <iostream>
#include <algorithm>	//sort를 사용하기 위한 라이브러리
using namespace std;

int main() {
	int array[3];		//크기가 3인 정수형 배열입니다.
	for (int i = 0; i < 3; i++) {	//정수 세 개를 입력합니다.
		cin >> array[i];
	}

	sort(array, array+3);	//sort를 사용하여 오름차순으로 정렬합니다.
		
	for (int i = 0; i < 3; i++) {	//정렬된 정수들을 순서대로 출력합니다.
		cout << array[i] << ' ';
	}

	return 0;
}