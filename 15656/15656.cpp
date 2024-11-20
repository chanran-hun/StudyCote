	#include <iostream>
	#include <vector>		//arr�� result�� vector�� �����ϱ� ���ؼ� �ʿ��� ���̺귯��
	#include <algorithm>	//arr�� sort�� �����ϱ� ���ؼ� �ʿ��� ���̺귯��
	using namespace std;

	int N, M;
	vector<int> arr;		//������ �Է��� vector
	vector<int> result;		//������ ����� vector

	void N_M(int depth) {
		if (depth == M) {	//depth�� M�� ���� �� result�� ������ ����մϴ�.
			for (int n : result) {
				cout << n << " ";
			}
			cout << '\n';
			return;			//����� ��ģ �� �Լ��� �����մϴ�.
		}

		for (int i = 0; i < N; i++) {	//depth�� M���� ���� ���� �ݺ������� ������ �˴ϴ�.
			result.push_back(arr[i]);	//arr�� i��° ��Ҹ� result�� �߰��մϴ�.

			N_M(depth + 1);				//�Լ��� ��������� ȣ���մϴ�.

			result.pop_back();			//����� ��ġ�� �Ǹ� ������ ��Ҹ� ������ �� ���� ����Ŭ�� ���� �˴ϴ�.
		}
	}

	int main() {
		cin >> N >> M;					
		arr.resize(N);					//arr�� N�� ũ��� �����ݴϴ�.
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		sort(arr.begin(), arr.end());

		N_M(0);		//�Լ��� ȣ���� �� depth�� ���� 0���� �����մϴ�.

		return 0;
	}