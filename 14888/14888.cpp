#include <iostream>
#include <vector>	//숫자들을 vector에 저장하기 위해 필요합니다.
#include <algorithm>	//max와 min연산을 위해 필요합니다.
#include <climits>		//최대값과 최소값으로 초기화 하기 위해 필요합니다.
using namespace std;

int num_num;	//입력할 정수의 개수 입니다.
vector<int> numbers;	//정수를 저장할 vector입니다.
int operators[4];	//+, -, *, / 순서
int max_result = INT_MIN;	//출력할 최대값입니다. 최초에는 int형 변수의 최소값으로 초기화 합니다.
int min_result = INT_MAX;	//출력할 최소값입니다. 최초에는 int형 변수의 최대값으로 초기화 합니다.

void backtrack(int index, int current_result) {	
	if (index == num_num) {	//인덱스가 정수의 개수와 같은 경우 현재결과값과 최대/최소 결과값을 비교하여 최대/최소 결과값을 최신화 합니다.
		max_result = max(max_result, current_result);
		min_result = min(min_result, current_result);
		return;
	}

	for (int i = 0; i < 4; i++) {	//+기호부터 /기호까지 차례대로 연산을 진행합니다.
		if (operators[i] > 0) {	//사용 가능한 개수가 1개 이상일 때 실행할 수 있도록 합니다.
			operators[i]--;		//기호를 사용했으므로 1 감소시킵니다.
			if (i == 0)backtrack(index + 1, current_result + numbers[index]);	//기호에 알맞은 연산을 하고 함수를 재귀적으로 호출합니다.
			if (i == 1)backtrack(index + 1, current_result - numbers[index]);
			if (i == 2)backtrack(index + 1, current_result * numbers[index]);
			if (i == 3)backtrack(index + 1, current_result / numbers[index]);
			operators[i]++;	//이 코드에 도달했다는 것은 인덱스가 정수의 개수에 한 번 도달 했다는 뜻이므로 처음부터 다시 연산을 
							//해야 하기 때문에 연산자의 개수를 다시 원래대로 되돌려줍니다.
		}
	}
}

int main() {
	cin >> num_num;	//입력할 정수의 개수를 입력합니다.
	numbers.resize(num_num);	//그 정수의 개수에 따라 정수를 저장할 vector의 크기를 설정합니다.
	
	for (int i = 0; i < num_num; i++) {	//정수들을 입력합니다.
		cin >> numbers[i];
	}

	for (int i = 0; i < 4; i++) {	//연산자의 개수를 입력합니다.
		cin >> operators[i];
	}

	backtrack(1, numbers[0]);	//백트래킹 알고리즘을 실행합니다. index는 1, current_result는 첫 번째 정수로 하여 실행합니다.
	
	cout << max_result << '\n' << min_result << '\n';	//최대값과 최소값을 출력합니다.

	return 0;
}