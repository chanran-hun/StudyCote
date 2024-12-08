#include <iostream>
#include <vector>	//���ڵ��� vector�� �����ϱ� ���� �ʿ��մϴ�.
#include <algorithm>	//max�� min������ ���� �ʿ��մϴ�.
#include <climits>		//�ִ밪�� �ּҰ����� �ʱ�ȭ �ϱ� ���� �ʿ��մϴ�.
using namespace std;

int num_num;	//�Է��� ������ ���� �Դϴ�.
vector<int> numbers;	//������ ������ vector�Դϴ�.
int operators[4];	//+, -, *, / ����
int max_result = INT_MIN;	//����� �ִ밪�Դϴ�. ���ʿ��� int�� ������ �ּҰ����� �ʱ�ȭ �մϴ�.
int min_result = INT_MAX;	//����� �ּҰ��Դϴ�. ���ʿ��� int�� ������ �ִ밪���� �ʱ�ȭ �մϴ�.

void backtrack(int index, int current_result) {	
	if (index == num_num) {	//�ε����� ������ ������ ���� ��� ���������� �ִ�/�ּ� ������� ���Ͽ� �ִ�/�ּ� ������� �ֽ�ȭ �մϴ�.
		max_result = max(max_result, current_result);
		min_result = min(min_result, current_result);
		return;
	}

	for (int i = 0; i < 4; i++) {	//+��ȣ���� /��ȣ���� ���ʴ�� ������ �����մϴ�.
		if (operators[i] > 0) {	//��� ������ ������ 1�� �̻��� �� ������ �� �ֵ��� �մϴ�.
			operators[i]--;		//��ȣ�� ��������Ƿ� 1 ���ҽ�ŵ�ϴ�.
			if (i == 0)backtrack(index + 1, current_result + numbers[index]);	//��ȣ�� �˸��� ������ �ϰ� �Լ��� ��������� ȣ���մϴ�.
			if (i == 1)backtrack(index + 1, current_result - numbers[index]);
			if (i == 2)backtrack(index + 1, current_result * numbers[index]);
			if (i == 3)backtrack(index + 1, current_result / numbers[index]);
			operators[i]++;	//�� �ڵ忡 �����ߴٴ� ���� �ε����� ������ ������ �� �� ���� �ߴٴ� ���̹Ƿ� ó������ �ٽ� ������ 
							//�ؾ� �ϱ� ������ �������� ������ �ٽ� ������� �ǵ����ݴϴ�.
		}
	}
}

int main() {
	cin >> num_num;	//�Է��� ������ ������ �Է��մϴ�.
	numbers.resize(num_num);	//�� ������ ������ ���� ������ ������ vector�� ũ�⸦ �����մϴ�.
	
	for (int i = 0; i < num_num; i++) {	//�������� �Է��մϴ�.
		cin >> numbers[i];
	}

	for (int i = 0; i < 4; i++) {	//�������� ������ �Է��մϴ�.
		cin >> operators[i];
	}

	backtrack(1, numbers[0]);	//��Ʈ��ŷ �˰����� �����մϴ�. index�� 1, current_result�� ù ��° ������ �Ͽ� �����մϴ�.
	
	cout << max_result << '\n' << min_result << '\n';	//�ִ밪�� �ּҰ��� ����մϴ�.

	return 0;
}