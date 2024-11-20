	#include <iostream>
	#include <vector>		//arr과 result를 vector로 선언하기 위해서 필요한 라이브러리
	#include <algorithm>	//arr을 sort로 정렬하기 위해서 필요한 라이브러리
	using namespace std;

	int N, M;
	vector<int> arr;		//수열을 입력할 vector
	vector<int> result;		//수열을 출력할 vector

	void N_M(int depth) {
		if (depth == M) {	//depth가 M과 같을 때 result의 내용을 출력합니다.
			for (int n : result) {
				cout << n << " ";
			}
			cout << '\n';
			return;			//출력을 마친 후 함수를 종료합니다.
		}

		for (int i = 0; i < N; i++) {	//depth가 M보다 작을 때는 반복문으로 들어오게 됩니다.
			result.push_back(arr[i]);	//arr의 i번째 요소를 result에 추가합니다.

			N_M(depth + 1);				//함수를 재귀적으로 호출합니다.

			result.pop_back();			//출력을 마치게 되면 마지막 요소를 제거한 뒤 다음 사이클로 가게 됩니다.
		}
	}

	int main() {
		cin >> N >> M;					
		arr.resize(N);					//arr을 N의 크기로 맞춰줍니다.
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		sort(arr.begin(), arr.end());

		N_M(0);		//함수를 호출할 때 depth의 값을 0으로 설정합니다.

		return 0;
	}