#include <iostream>
#include <vector>		//arr과 result를 vector로 선언하기 위한 라이브러리
#include <algorithm>	//sort를 사용하기 위한 라이브러리
using namespace std;

int N, M;		
vector<int> arr;	//수열을 입력 할 vector
vector<int> result;	//수열을 출력 할 vector

void N_M(int depth) {
	if (depth == M) {	//depth가 M과 같아지면 내용을 출력
		for (int n : result) {
			cout << n << " ";
		}
		cout << '\n';
		return;			//출력 후 함수종료
	}

	for (int i = 0; i < N; i++) {
		if (!result.empty() && result.back() > arr[i]) {	//이전 요소보다 현재의 요소가 작다면 건너뛰기
			continue;
		}

		result.push_back(arr[i]);	//현재 인덱스의 요소를 출력 수열에 저장

		N_M(depth + 1);				//함수 재귀적으로 호출

		result.pop_back();			//호출 후 마지막 요소 삭제
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