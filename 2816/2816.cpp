#include <iostream>
#include <vector>	//ä�� ������ vector�� ������ �� �ʿ��մϴ�.
using namespace std;


int main() {
	int num_channels;	//�Է��� ä���� ���� �Դϴ�.
	cin >> num_channels;

	int kbs1_index;		
	int kbs2_index;	
	
	vector<string> channels(num_channels);
	for (int i = 0; i < num_channels; i++) {
		cin >> channels[i];	//ä�θ��� �Է��մϴ�.
		
		if (channels[i] == "KBS1") {	//�Է��ϸ鼭 KBS1�� ��� ä������ �����մϴ�.
			kbs1_index = i;
		}

		if (channels[i] == "KBS2") {	//���� �۾��� KBS2�� ������ε� �����մϴ�.
			kbs2_index = i;
		}
	}
	
	for (int i = 0; i < kbs1_index; i++) {	//KBS1�� �� �� ���� ä���� �̵��մϴ�.
		cout << 1;
	}

	for (int i = 0; i < kbs1_index; i++) {	//KBS1�� 1��ä��(0�� �ε���)���� �̵���ŵ�ϴ�.
		cout << 4;
	}

	if (kbs2_index < kbs1_index) {	//���� KBS2�� KBS1���� �տ� ���� �� KBS1�� ������ �̵���Ű�� ��������
		kbs2_index++;				//KBS2�� �ڷ� �� ĭ �и� �� �����Ƿ� KBS2�� ��ġ�� 1 ���������ݴϴ�.
	}

	for (int i = 0; i < kbs2_index; i++) {	//KBS1�� ���ؼ� �� �۾��� �����ϰ� KBS2�� ���ؼ��� �����մϴ�.
		cout << 1;
	}

	for (int i = 0; i < kbs2_index - 1; i++) {
		cout << 4;
	}

	return 0;

}