#include <iostream>
using namespace std;
bool isGroupWord(string &word) {	//�׷�ܾ� �Ǻ��Լ�
	bool visited[26] = { false };	//������ ���ĺ��� ���ؼ� �ߺ� ���θ� Ȯ���Ѵ�
	char prev = '\0';

	for (char ch : word) {	
		if (ch != prev) {			//���� ���ĺ��� ���� ���ĺ��� �ٸ��ٸ� ���� ���ĺ��� �������� �ִ��� Ȯ���Ѵ�
			if (visited[ch - 'a']) {
				return false;		//�������� �ִٸ� ������ ��ȯ�Ѵ�(�׷�ܾ �ƴϱ� ����)
			} 
			visited[ch - 'a'] = true;	//������ �� ���ٸ� �ش� ���ĺ��� ���� ������ ������ �ٲ۴�
		}
		prev = ch;						//���� �ܾ ���� ������ �����Ѵ�
	}

	return true;						// ��� �ܰ迡�� ������ ��ȯ�� �� ���ٸ� ���� ��ȯ�Ѵ�
}
int main() {
	int numString;						//�Էµ� ���ڿ��� ����
	cin >> numString;

	int result = 0;						//�����, �׷�ܾ �������

	string str;

	for (int i = 0; i < numString; i++) {
		cin >> str;						//������ Ƚ����ŭ ���ڿ��� �Է�
		if (isGroupWord(str)) {			//���ڿ��� �׷�ܾ� ���θ� Ȯ��
			result++;					//�׷�ܾ��� ����� ����
		}
	}

	cout << result << endl;				//����� ���

	return 0;
}