#include <iostream>
#include <stack>
using namespace std;

int main() {
	int num;
	cin >> num;	//�ݺ�Ƚ�� �Է�

	for (int i = 0; i < num; i++) {	
		string VPS;
		cin >> VPS;		//��ȣ�� �Է�

		stack<char> units;
		for (char unit : VPS) {
			if (unit == '(') {
				units.push(unit);	//���ʰ�ȣ�� ���ÿ� ����
			} else {
				if (!units.empty()) {
					if (unit != units.top()) {	//������ ��ȣ�� �ԷµǾ����� ���� ��ȣ�� ���� �ȿ� 
						units.pop();			//�ִٸ� ���ʰ�ȣ �ϳ� ����
					} else {
						units.push(unit);		//���ʰ�ȣ�� ���ٸ� �����U ��ȣ ����
					}
				} else {
					units.push(unit);			//������ ����ִٸ� ������ ��ȣ ����
				}
			}
		}

		if (units.empty()){			//������ ��������� ��� ��ȣ�� ¦�� �´ٴ� ���̹Ƿ�
			cout << "YES" << endl;	//VPS�� �´ٰ� ���
		} else {					//����ִٸ�
			cout << "NO" << endl;	//�ƴ϶�� ���
		}
	}
	return 0;
}