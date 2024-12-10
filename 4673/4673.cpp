#include <iostream>
#include <vector>	//bool�� vector�� �ش� ���� �����ѹ����� �ƴ����� ������ ���Դϴ�.
using namespace std;

int main() {
	vector<bool> is_nonself(10001,false);	//true�� ��� �����ѹ��� �ƴϰ� false�� ��� �����ѹ� �Դϴ�.

	for (int i = 1; i <= 10000; i++) {		//1~10000�� ���� ���ؼ� d(n)�� ����� true�� �ٲ��ִ� ����.
		int temp = i;
		int j = i;
		while (j > 0) {
			temp += j % 10;
			j /= 10;
		}
		if (temp <= 10000) {				//������� 10000 ���� �϶��� �۾��� �����մϴ�.
			is_nonself[temp] = true;
		}
	}

	for (int i = 1; i <= 10000; i++) {		//10000������ ��� ���� �ѹ��� ����մϴ�.
		if(!is_nonself[i]){
			cout << i << '\n';
		}
	}

	return 0;
}