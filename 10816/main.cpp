#include <iostream>
#include <unordered_map>	//freq를 선언하기 위해서 필요한 헤더입니다.
using namespace std;

int main() {
	ios::sync_with_stdio(false);	//출력시 시간 초과를 막기위한 장치입니다.
	cin.tie(0);

	int N, M;	//가각 기준카드와 탐색 카드의 개수입니다.
	cin >> N;
	
	unordered_map<int, int> freq;	//어떤 숫자가 몇 개 있는지 저장할 자료구조입니다.
	int num;

	for (int i = 0; i < N; i++) {	//기준카드를 입력하는 과정 입니다.
		cin >> num;
		freq[num]++;
	}

	cin >> M;
	
	for (int i = 0; i < M; i++) {	//탐색카드를 입력하고 동시에 개수를 세서 출력하는 과정입니다.
		cin >> num;
		cout << freq[num] << " ";
	}
	cout << "\n";

	return 0;
}