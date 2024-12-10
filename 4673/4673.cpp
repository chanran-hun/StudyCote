#include <iostream>
#include <vector>	//bool형 vector에 해당 수가 셀프넘버인지 아닌지를 저장할 것입니다.
using namespace std;

int main() {
	vector<bool> is_nonself(10001,false);	//true일 경우 셀프넘버가 아니고 false일 경우 셀프넘버 입니다.

	for (int i = 1; i <= 10000; i++) {		//1~10000의 수에 대해서 d(n)의 결과를 true로 바꿔주는 과정.
		int temp = i;
		int j = i;
		while (j > 0) {
			temp += j % 10;
			j /= 10;
		}
		if (temp <= 10000) {				//결과값이 10000 이하 일때만 작업을 수행합니다.
			is_nonself[temp] = true;
		}
	}

	for (int i = 1; i <= 10000; i++) {		//10000이하의 모든 셀프 넘버를 출력합니다.
		if(!is_nonself[i]){
			cout << i << '\n';
		}
	}

	return 0;
}