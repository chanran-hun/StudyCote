#include <iostream>
#include <vector>	//채널 모음을 vector로 선언할 때 필요합니다.
using namespace std;


int main() {
	int num_channels;	//입력할 채널의 개수 입니다.
	cin >> num_channels;

	int kbs1_index;		
	int kbs2_index;	
	
	vector<string> channels(num_channels);
	for (int i = 0; i < num_channels; i++) {
		cin >> channels[i];	//채널명을 입력합니다.
		
		if (channels[i] == "KBS1") {	//입력하면서 KBS1이 몇번 채널인지 저장합니다.
			kbs1_index = i;
		}

		if (channels[i] == "KBS2") {	//같은 작업을 KBS2를 대상으로도 진행합니다.
			kbs2_index = i;
		}
	}
	
	for (int i = 0; i < kbs1_index; i++) {	//KBS1이 될 때 까지 채널을 이동합니다.
		cout << 1;
	}

	for (int i = 0; i < kbs1_index; i++) {	//KBS1을 1번채널(0번 인덱스)까지 이동시킵니다.
		cout << 4;
	}

	if (kbs2_index < kbs1_index) {	//만약 KBS2가 KBS1보다 앞에 있을 때 KBS1을 앞으로 이동시키는 과정에서
		kbs2_index++;				//KBS2가 뒤로 한 칸 밀릴 수 있으므로 KBS2의 위치를 1 증가시켜줍니다.
	}

	for (int i = 0; i < kbs2_index; i++) {	//KBS1에 대해서 한 작업을 동일하게 KBS2에 대해서도 진행합니다.
		cout << 1;
	}

	for (int i = 0; i < kbs2_index - 1; i++) {
		cout << 4;
	}

	return 0;

}