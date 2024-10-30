#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int num;
	cin >> num;	//입력횟수

	stack<int> sequence;	//원하는 수열
	queue<char> result;		//결과값(push와 pop)
	int count = 1;

	for (int i = 0; i < num; i++) {
		int num;
		cin >> num;

		if (!sequence.empty() && sequence.top() == num) {	//만약 top의 값이 입력값과 같다면 바로 pop실행
			sequence.pop();
			result.push('-');
		} else if (count <= num) {							//현재 값보다 top이 작다면 현재값이 담길 때 까지
			while (count <= num) {							//push반복
				sequence.push(count++);						
				result.push('+');
			}
			sequence.pop();									//본인값까지 도달하면 pop
			result.push('-');
		} else if (!sequence.empty() && sequence.top() > num) {
			cout << "NO" ;									//top의 값이 목표수보다 크다면 실패(불가능)
			return 0;
		}

		
	}

	while (!result.empty()) {	//저장한 결과(pop과 push)출력
		cout << result.front() << '\n';
		result.pop();
	}
		
	return 0;
}