#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;
vector<int> result;
vector<bool> visited;

void N_M(int depth) {
	if (depth == M) {
		for (int n : result) {
			cout << n << " ";
		}
		cout << '\n';
		return;
	}
	int lastUsed = -1;
	for (int i = 0; i < N; i++) {
		if ((!result.empty() && result.back() > arr[i]) || lastUsed == arr[i] || visited[i]) {
			continue;
		}
		result.push_back(arr[i]);
		lastUsed = arr[i];
		visited[i] = true;

		N_M(depth + 1);

		result.pop_back();
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