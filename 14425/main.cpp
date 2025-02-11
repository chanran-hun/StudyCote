#include <iostream>
#include <algorithm>	//sort와 binary_search를 사용하기 위한 헤더 입니다.
using namespace std;

int main() {
	int N, M;	//집합 내부의 문자열 개수 N과 검사를 실시할 문자열 개수 M 입니다.
	int result = 0;	//결과값을 저장할 정수 result입니다.
	cin >> N >> M;


	string* S = new string[N];	//집합을 배열로 선언하는 과정입니다.

	for (int i = 0; i < N; i++) {	
		cin >> S[i];
	}

	sort(S, S + N);	//집합 내부의 문자열을 정렬하는 과정 입니다.
	string input;
	for (int i = 0; i < M; i++) {
		cin >> input;
		if (binary_search(S, S + N, input)) {	//이진탐색 과정을 통하여 문자열을 검사하는 과정 입니다.
			result++;
		}
	}

	cout << result << endl;	

	return 0;
}