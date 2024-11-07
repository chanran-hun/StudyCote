#include <iostream>
using namespace std;
int main() {
	int numRoom;					//고사장의 수
	cin >> numRoom;	

	int* numStu = new int[numRoom];	//고사장 하나의 응시생 수
	for (int i = 0; i < numRoom; i++) {
		cin >> numStu[i];
	}

	int forceMaster;				//총 감독관이 감독할 수 있는 학생 수
	int forceMember;				//부 감독관이 감독할 수 있는 학생 수
	cin >> forceMaster >> forceMember;

	long long result = 0;			//필요한 감독관의 수
	for (int i = 0; i < numRoom; i++) {
		numStu[i] -= forceMaster;	//총 감독관이 감독할 수 있는 학생 수를 뺀다
		result++;					//감독관의 수를 한명 추가한다.

		if (numStu[i] <= 0) {		//남은 학생의 수가 0 이하라면
			continue;
		}

		if (numStu[i] % forceMember != 0) {	//학생수가 나누어 떨어지지 않는다면 감독관이 한명 더 필요하므로 감독관의 수를 1명 늘린다.
			result++;
		}
		result += numStu[i] / forceMember;	//학생수를 부 감독관이 감당가능한 학생 수로 나눠서 필요한 감독관의 수를 추가한다.
	}

	cout << result;					//필요한 감독관의 수를 출력한다.
	
	return 0;

}