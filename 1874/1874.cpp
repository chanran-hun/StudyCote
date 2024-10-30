#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int num;
	cin >> num;	//�Է�Ƚ��

	stack<int> sequence;	//���ϴ� ����
	queue<char> result;		//�����(push�� pop)
	int count = 1;

	for (int i = 0; i < num; i++) {
		int num;
		cin >> num;

		if (!sequence.empty() && sequence.top() == num) {	//���� top�� ���� �Է°��� ���ٸ� �ٷ� pop����
			sequence.pop();
			result.push('-');
		} else if (count <= num) {							//���� ������ top�� �۴ٸ� ���簪�� ��� �� ����
			while (count <= num) {							//push�ݺ�
				sequence.push(count++);						
				result.push('+');
			}
			sequence.pop();									//���ΰ����� �����ϸ� pop
			result.push('-');
		} else if (!sequence.empty() && sequence.top() > num) {
			cout << "NO" ;									//top�� ���� ��ǥ������ ũ�ٸ� ����(�Ұ���)
			return 0;
		}

		
	}

	while (!result.empty()) {	//������ ���(pop�� push)���
		cout << result.front() << '\n';
		result.pop();
	}
		
	return 0;
}