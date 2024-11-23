#include <iostream>
#include <vector>		//arr, result, visited를 vector로 선언하기 위한 라이브러리
#include <algorithm>	//sort를 사용하기 위한 알고리즘
using namespace std;

int N, M;
vector<int> arr;		//수열을 입력할 vector
vector<int> result;		//수열을 출력할 vector
vector<bool> visited;	//인덱스의 방문 여부를 저장할 vector

void N_M(int depth) {	
	if (depth == M) {	//depth와 M이 같을 때 result의 내용물을 출력한 후 함수를 종료합니다.
		for (int n : result) {
			cout << n << " ";
		}
		cout << '\n';
		return;
	}
	int lastUsed = -1;	//가장 최근에 추가된 수를 저장합니다.
	for (int i = 0; i < N; i++) {
		if ((!result.empty() && result.back() > arr[i]) || lastUsed == arr[i] || visited[i]) {
			continue;	//같은 수열이 여러번 추가되지 않도록 하고, 비내림차순이 되도록 해줍니다.
		}
		result.push_back(arr[i]);	//수를 추가한 이후에 방문여부를 참으로 바꿔주고 가장 최근에 추가된 수도 초기화 해줍니다.
		visited[i] = true;
		lastUsed = arr[i];

		N_M(depth + 1);	//함수를 재귀적으로 호출합니다.

		result.pop_back();	//가장 뒤의 요소를 삭제하고 방문여부도 거짓으로 바꿔줍니다.
		visited[i] = false;
	}
}

int main() {
	cin >> N >> M;	
	arr.resize(N);	
	visited.resize(N, false);
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	N_M(0);

	return 0;
}