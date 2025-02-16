#include <iostream>
#include <set>		//�赵 ���� ����� �����ϴµ� �� �ڷᱸ�� �Դϴ�.
#include <vector>	//�赵 ���� ���� ����� �����ϴµ� �� �ڷᱸ�� �Դϴ�.
#include <algorithm>	//���� �� �� �ʿ��� ��� �Դϴ�.
using namespace std;

int main() {
	int N, M;	//�赵 ���ѻ�� �� N�� ���� ���� ����� �� M �Դϴ�.
	cin >> N >> M;

	set<string> unheard;	//�赵 ���� ��� ��� �Դϴ�.
	vector<string> unseen_unheard;	//�赵 ���� ���� ��� ��� �Դϴ�.

	for (int i = 0; i < N; i++) {	//�赵 ���� ����� �Է��մϴ�.
		string name;
		cin >> name;
		unheard.insert(name);
	}

	for (int i = 0; i < M; i++) {	//���� ���� ����� �Է��մϴ�.
		string name;
		cin >> name;
		if (unheard.find(name) != unheard.end()) {	//�׸��� �Է� �� �� �赵 ���� ����� ��ġ�� ����� ã���ϴ�.
			unseen_unheard.push_back(name);			//ã�� ������ �赵 ���� ���� ����� ��Ͽ� �����մϴ�.
		}
	}

	sort(unseen_unheard.begin(), unseen_unheard.end());	//�赵 ���� ���� ����� ����� ���������� �����մϴ�.

	cout << unseen_unheard.size() << endl;				//�赵 ���� ���� ����� ���� ����մϴ�.
	for (int i = 0; i < unseen_unheard.size(); i++) {	//�赵 ���� ���� ����� ����� ����մϴ�.
		cout << unseen_unheard[i] << endl;
	}

	return 0;
}