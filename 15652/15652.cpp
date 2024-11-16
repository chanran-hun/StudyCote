#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> result;
void N_M(int depth) {
	if (depth == M) {
		for (int n : result) {
			cout << n << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!result.empty() && i < result.back()) {
			continue;
		}
		result.push_back(i);
		N_M(depth + 1);
		result.pop_back();
	}
}

int main() {
	cin >> N >> M;
	N_M(0);

	return 0;
}