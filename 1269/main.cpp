#include <iostream>
#include <unordered_set>	//두 집합을 선언할 때 필요한 헤더입니다.
using namespace std;
int main() {
	int n, m;	//두 집합 A, B의 원소의 개수입니다.
	cin >> n >> m;

	int result = 0;	//결과값 입니다.

	unordered_set<int> A, B;	//두 집합 입니다.
	int num;

	for (int i = 0; i < n; i++) {
		cin >> num;
		A.insert(num);
	}

	for (int i = 0; i < m; i++) {
		cin >> num;
		B.insert(num);
	}

	for (int x : A) {	//대칭 차집합을 구하는 과정입니다. A에는 있고 B에는 없는 원소의 수를 구합니다.
		if (B.find(x) == B.end()) {
			result++;
		}
	}

	for (int x : B) {	//대칭 차집합을 구하는 과정입니다. B에는 있고 A에는 없는 원소의 수를 구합니다.
		if (A.find(x) == A.end()) {
			result++;
		}
	}

	cout << result << endl;	

	return 0;
}