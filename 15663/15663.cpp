#include <iostream>
#include <vector>		//arr, result, visited를 vector로 선언하기 위한 라이브러리
#include <algorithm>	//sort를 사용하기 위한 라이브러리
using namespace std;

int N, M;
vector<int> arr;		//수열을 입력 할 vector
vector<int> result;		//수열을 출력 할 vector
vector<bool> visited;	//수열에서 각각의 요소들의 방문여부를 저장 할 vector

void N_M(int depth) {	//백트래킹 알고리즘을 사용하는 함수입니다.
	if (depth == M) {	//depth가 M과 같을 경우에 result에 저장된 요소들을 양식에 맞춰서 출력합니다
		for (int n : result) {	
			cout << n << " ";
		}
		cout << '\n';
		return;
	}

	int lastUsed = -1;	//가장 최근에 저장된 수를 저장하는 변수입니다.
	for (int i = 0; i < N; i++) {
		if (visited[i] || lastUsed == arr[i]) {	//만약 이미 방문된 수거나, 바로 직전에 저장된 수라면 현재 시퀀스는 건너뜁니다.
			continue;
		}

		result.push_back(arr[i]);	//현재 인덱스의 수를 result에 저장하고 lastUsed를 현재의 수로 초기화 한 후, visited에서 현재 인덱스를 true로 초기화 합니다.
		lastUsed = arr[i];			
		visited[i] = true;

		N_M(depth + 1);				//함수를 재귀적으로 호출합니다.

		result.pop_back();			//출력을 완료 한 후에 가장 마지막의 요소를 삭제한 후 해당 값의 인덱스 부분을 visited에서 false로 초기화 합니다.
		visited[i] = false;
	}
}

int main() {
	cin >> N >> M;
	arr.resize(N);					//arr의 크기를 N으로 설정하고 visited의 크기도 N으로 설정 한 후 기본값을 false로 초기화 합니다.
	visited.resize(N, false);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());	//arr내부의 값들을 오름차순으로 정렬합니다.

	N_M(0);							//함수를 호출 할 때 파라미터의 값을 0으로 하여 호출합니다.

	return 0;
}