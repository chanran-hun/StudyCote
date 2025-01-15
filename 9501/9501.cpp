#include <iostream>
using namespace std;

int main() {
	int test_case;	//테스트 케이스의 수 입니다.
	int result = 0;	//결과값 저장 변수 입니다.

	cin >> test_case;	

	while (test_case--) {	
		int num_spaceship;	//우주선의 개수 입니다.
		float distance;		//목적지 까지의 거리 입니다.
		float max_velocity;	//각 우주선의 스펙 중 첫 번째, 최고 속도 입니다.
		float fuel_mount;	//두 번째 스펙, 연료 량 입니다.
		float cost_fuel;	//세 번째 스펙, 단위 시간당 연료 소비량 입니다.

		cin >> num_spaceship;	
		cin >> distance;

		while (num_spaceship--) {
			cin >> max_velocity;	
			cin >> fuel_mount;
			cin >> cost_fuel;
			if (fuel_mount / cost_fuel >= distance / max_velocity) {	//나눗셈을 통하여 도착 가능한 우주선의 개수를 찾는 과정입니다.
				result++;
			}
		}
		cout << result << '\n';	
		result = 0;
	}

	return 0;
}