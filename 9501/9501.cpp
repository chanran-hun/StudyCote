#include <iostream>
using namespace std;

int main() {
	int test_case;	//�׽�Ʈ ���̽��� �� �Դϴ�.
	int result = 0;	//����� ���� ���� �Դϴ�.

	cin >> test_case;	

	while (test_case--) {	
		int num_spaceship;	//���ּ��� ���� �Դϴ�.
		float distance;		//������ ������ �Ÿ� �Դϴ�.
		float max_velocity;	//�� ���ּ��� ���� �� ù ��°, �ְ� �ӵ� �Դϴ�.
		float fuel_mount;	//�� ��° ����, ���� �� �Դϴ�.
		float cost_fuel;	//�� ��° ����, ���� �ð��� ���� �Һ� �Դϴ�.

		cin >> num_spaceship;	
		cin >> distance;

		while (num_spaceship--) {
			cin >> max_velocity;	
			cin >> fuel_mount;
			cin >> cost_fuel;
			if (fuel_mount / cost_fuel >= distance / max_velocity) {	//�������� ���Ͽ� ���� ������ ���ּ��� ������ ã�� �����Դϴ�.
				result++;
			}
		}
		cout << result << '\n';	
		result = 0;
	}

	return 0;
}