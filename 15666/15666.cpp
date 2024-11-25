#include <iostream>
#include <vector>		//arr과 result를 vector로 선언하기 위한 라이브러리
#include <algorithm>	//sort를 사용하기 위한 라이브러리
using namespace std;

int N, M;				
vector<int> arr;		//수열을 입력할 vector
vector<int> result;		//수열을 출력할 vector

void N_M(int depth) {	
	if (depth == M) {	//depth의 값과 M의 값이 같을 때 result의 내용을 출력합니다.
		for (int n : result) {
			cout << n << " ";
		}
		cout << '\n';
		return;			//출력 완료 후 함수를 종료합니다.
	}

	int lastUsed = -1;	//가장 마지막에 저장된 수를 기록합니다. 이 작업을 통해서 같은 수열이 여러번 출력되는것을 방지합니다.
	for (int i = 0; i < N; i++) {
		if ((!result.empty() && result.back() > arr[i]) || lastUsed == arr[i]) {
			continue;	//result의 마지막 값이 현재 arr의 인덱스보다 크거나, arr의 현재 인덱스가 가장 이전에 추가된 수와 같다면 현재 시퀀스를 건너뜁니다.
		}
		result.push_back(arr[i]);	//현재 arr의 인덱스를 result에 추가합니다
		lastUsed = arr[i];			//현재 arr의 인덱스로 lastUSed를 초기화 합니다.

		N_M(depth + 1);				//함수를 재귀적으로 호출하고 파라미터값을 1 늘립니다.

		result.pop_back();			//출력 후 가장 마지막값을 삭제합니다.
	}
}

int main() {
	cin >> N >> M;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	N_M(0);

	return 0;
}