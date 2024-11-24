#include <iostream>
#include <vector>		//arr과 result를 vector로 선언하기 위해 필요한 라이브러리.
#include <algorithm>	//sort를 사용하기 위해 필요한 라이브러리.
using namespace std;

int N, M;
vector<int> arr;		//수열을 입력하는데 사용되는 vector.
vector<int> result;		//수열을 출력하는데 사용되는 vector.

void N_M(int depth) {
	if (depth == M) {	//depth가 M과 같은 경우에는 저장된 수열을 출력하고 함수를 종료합니다.
		for (int n : result) {
			cout << n << " ";
		}
		cout << '\n';
		return;
	}

	int lastUsed = -1;	//같은 수열이 여러번 출력되는것을 방지하는 변수입니다.
	for (int i = 0; i < N; i++) {	
		if (lastUsed == arr[i]) {	//이미 출력된 수열인경우 건너뛰기 합니다.
			continue;
		}
		result.push_back(arr[i]);	//result에 arr의 현재 인덱스를 result에 저장하고 lastUsed의 값도 현재 인덱스로 초기화 합니다.
		lastUsed = arr[i];

		N_M(depth+1);	//재귀적으로 함수를 호출합니다. 이때, depth의 값을 1 늘려서 호출합니다.

		result.pop_back();			//수열 출력 이후 가장 마지막 값을 삭제합니다.
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