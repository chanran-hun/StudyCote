#include <iostream>
#include <string>
using namespace std;

int main() {

	int numRepeat;	//반복횟수
	string OX;		//정답/오답 기록

	int sum = 0, isConsecutive = 0;	//결과, 연속정보

	cin >> numRepeat;	//반복횟수 입력

	for (int i = 0; i < numRepeat; i++) {
		cin >> OX;		//정답 결과 입력

		for (int j = 0; j < OX.size(); j++) {
			if (OX[j] == 'O') {		//맞은경우
				sum += isConsecutive + 1;	//지금 몇번 연속으로 정답인지에 따라 다른 포인트를 올려줌
				isConsecutive++;			//연속기록 저장
			} else if( OX[j] == 'X' ) {
				isConsecutive = 0;			//오답시 연속기록 초기화
			}
		}

		cout << sum << endl;		//총합점수 출력
		sum = 0;					//점수 초기화
		isConsecutive = 0;			//연속기록 초기화
	}

	return 0;
}