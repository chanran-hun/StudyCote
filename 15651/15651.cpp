#include <iostream>
#include <vector>	//벡터를 사용하기 위한 라이브러리
using namespace std;
int N, M;			//문제에서 주어진 N과 M입니다.
vector<int> result;	//정답값을 모은 후에 한 사이클 마다 출력 할 것입니다.

void N_M(int depth) {	//문제에서 주어진 조건의 수열을 출력하는 함수
	if (depth == M) {	//수열의 길이가 목표치에 도달하게 되면 수열을 공백과 함께 출력한 후 줄바꿈을 합니다.
		for (int n : result) {	//벡터의 요소를 모두 출력하는 과정입니다.
			cout << n << " ";
		}
		cout << '\n';
		return;			//출력한 후 함수를 종료합니다.
	}

	for (int i = 1; i <= N; i++) {	//1부터 N까지의 수를 규칙에 따라 출력하는 것이므로 해당 조건에 부합하는 반복문을 만듭니다.
		result.push_back(i);		//결과 수열에 오름차순으로 수가 저장되게 합니다.
		N_M(depth + 1);		//수열에 수가 한 개 저장되었기 때문에 현재 수열의 길이를 1 늘린 후 재귀적으로 함수를 실행합니다.
		result.pop_back();			//만약 함수가 호출되어 출력을 한 후 라면 가장 뒤의 요소를 결과 수열에서 제거합니다.
	}
}

int main() {
	cin >> N >> M;			//N과 M을 입력합니다.
	N_M(0);					//만들어 놓은 함수에 수열의 길이를 0으로 하여 실행합니다.

	return 0;
}