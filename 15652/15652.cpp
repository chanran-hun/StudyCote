#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> result;		//결과값 저장 수열.
void N_M(int depth) {	//깊이를 입력받아서 종료조건을 만듭니다.
	if (depth == M) {	//깊이가 M과 같을 때 출력
		for (int n : result) {
			cout << n << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {					//1부터 시작하여 N까지 반복
		if (!result.empty() && i < result.back()) {	//이전 수보다 크거나 같아야 함.
			continue;
		}
		result.push_back(i);						//조건에 만족한다면 결과 수열에 수 추가
		N_M(depth + 1);								//depth 증가시키기
		result.pop_back();							//출력 한 후에 가장 뒤에 있는 수 삭제
	}
}

int main() {
	cin >> N >> M;
	N_M(0);

	return 0;
}