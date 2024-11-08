#include <iostream>
#include <vector>
using namespace std;
int N, M;	

vector<int> result;	//결과값을 저장해뒀다가 출력 후 삭제
bool visited[9];	//방문여부

void N_M(int depth) {	
	if (depth == M) {	//깊이만큼 도달했다면 그동안 저장된 값들을 공백과 함께 출력한다.
		for (int n : result) {
			cout << n << " ";
		}
		cout << '\n';	//줄바꿈 이후 다음 패턴으로 넘어간다.
		return;
	}

	for (int i = 1; i <= N; i++) {	
		if (!visited[i]) {	//이미 방문된 적이 있다면 중복을 허용하지 않으므로 건너뛰기
			visited[i] = true;	//방문된 적이 없다면 해당 인덱스의 방문여부를 참으로 바꿔줌.
			result.push_back(i);	//결과값 출력후보의 가장 뒤에 저장한다.
			N_M(depth + 1);			//재귀적으로 실행한다.
			result.pop_back();		//출력을 바쳤을 때 가장 뒤의 값을 삭제한다.
			visited[i] = false;		//가장 뒤의 값의 방문여부를 다시 거짓으로 바꿔준다.
		}
	}
}

int main() {
	cin >> N >> M;

	N_M(0);

	return 0;
}