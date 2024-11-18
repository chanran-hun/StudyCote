#include <iostream>
#include <vector>		//result, arr, visited 모두 vector자료구조를 사용함.
#include <algorithm>	//sort를 사용하기 위해 필요한 라이브러리
using namespace std;

int N, M;				
vector<int> arr;		//입력한 수를 저장해 둘 벡터
vector<int> result;		//결과값을 출력하는데 사용할 벡터
vector<bool> visited;	//수들의 방문여부를 표시할 벡터

void N_M(int depth) {	//깊이에 도달하게 될 시 출력하는 함수
	if (depth == M) {
		for (int n : result) {
			cout << n << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) {	//이미 방문된 수는 건너뛰기
			continue;
		}

		result.push_back(arr[i]);	//수를 추가하고 방문여부를 참으로 설정
		visited[i] = true;

		N_M(depth + 1);		//함수 재귀적으로 호출

		result.pop_back();	//수를 삭제하고 방문여부를 거짓으로 설정
		visited[i] = false;
	}
}

int main() {
	cin >> N >> M;

	arr.resize(N);
	visited.resize(N, false);	//arr과 visited를 올바른 값과 크기로 설정

	for (int i = 0; i < N; i++) {	//arr에 정해진 개수를 입력
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());	//arr의 요소들을 오름차순으로 정렬
	N_M(0);

	return 0;
}