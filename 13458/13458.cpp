#include <iostream>
using namespace std;
int main() {
	int numRoom;					//������� ��
	cin >> numRoom;	

	int* numStu = new int[numRoom];	//����� �ϳ��� ���û� ��
	for (int i = 0; i < numRoom; i++) {
		cin >> numStu[i];
	}

	int forceMaster;				//�� �������� ������ �� �ִ� �л� ��
	int forceMember;				//�� �������� ������ �� �ִ� �л� ��
	cin >> forceMaster >> forceMember;

	long long result = 0;			//�ʿ��� �������� ��
	for (int i = 0; i < numRoom; i++) {
		numStu[i] -= forceMaster;	//�� �������� ������ �� �ִ� �л� ���� ����
		result++;					//�������� ���� �Ѹ� �߰��Ѵ�.

		if (numStu[i] <= 0) {		//���� �л��� ���� 0 ���϶��
			continue;
		}

		if (numStu[i] % forceMember != 0) {	//�л����� ������ �������� �ʴ´ٸ� �������� �Ѹ� �� �ʿ��ϹǷ� �������� ���� 1�� �ø���.
			result++;
		}
		result += numStu[i] / forceMember;	//�л����� �� �������� ���簡���� �л� ���� ������ �ʿ��� �������� ���� �߰��Ѵ�.
	}

	cout << result;					//�ʿ��� �������� ���� ����Ѵ�.
	
	return 0;

}