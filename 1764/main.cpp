#include <iostream>
#include <set>		//듣도 못한 사람을 저장하는데 쓸 자료구조 입니다.
#include <vector>	//듣도 보도 못한 사람을 저장하는데 쓸 자료구조 입니다.
#include <algorithm>	//정렬 할 때 필요한 헤더 입니다.
using namespace std;

int main() {
	int N, M;	//듣도 못한사람 수 N과 보도 못한 사람의 수 M 입니다.
	cin >> N >> M;

	set<string> unheard;	//듣도 못한 사람 목록 입니다.
	vector<string> unseen_unheard;	//듣도 보도 못한 사람 목록 입니다.

	for (int i = 0; i < N; i++) {	//듣도 못한 사람을 입력합니다.
		string name;
		cin >> name;
		unheard.insert(name);
	}

	for (int i = 0; i < M; i++) {	//보도 못한 사람을 입력합니다.
		string name;
		cin >> name;
		if (unheard.find(name) != unheard.end()) {	//그리고 입력 한 후 듣도 못한 사람과 겹치는 사람을 찾습니다.
			unseen_unheard.push_back(name);			//찾고 나서는 듣도 보도 못한 사람의 목록에 저장합니다.
		}
	}

	sort(unseen_unheard.begin(), unseen_unheard.end());	//듣도 보도 못한 사람의 목록을 사전순으로 정렬합니다.

	cout << unseen_unheard.size() << endl;				//듣도 보도 못한 사람의 수를 출력합니다.
	for (int i = 0; i < unseen_unheard.size(); i++) {	//듣도 보도 못한 사람의 목록을 출력합니다.
		cout << unseen_unheard[i] << endl;
	}

	return 0;
}