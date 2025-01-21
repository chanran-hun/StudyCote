#include <iostream>
#include <algorithm>	//max와 min을 사용하기 위한 라이브러리 입니다.
using namespace std;
int main() {
	int num_marvel;	//구슬의 개수 입니다.
	cin >> num_marvel;

	int max_x = -10000, max_y = -10000;	//구슬들의 가장 큰 x값과 y값 입니다.
	int	min_x = 10000, min_y = 10000;	//구슬들의 가장 작은 x값과 y값 입니다.

	for (int i = 0; i < num_marvel; i++) {
		int x;
		int y;
		cin >> x >> y;
		max_x = max(max_x, x);	//구슬들의 x값과 y값을 입력함과 동시에 x값의 최대치와 최소치, y값의 최대치와 최소치를 지속적으로 초기화 합니다.
		max_y = max(max_y, y);
		min_x = min(min_x, x);
		min_y = min(min_y, y);
	}	

	if (num_marvel == 1) {
		cout << 0 << '\n';	//구슬의 개수가 한 개 일때는 넓이는 0이 됩니다.
	} else {
		cout << (max_x - min_x) * (max_y - min_y) << '\n';	//가장 큰 x값과 가장 작은 x값의 차가 가로의 길이가 되고,
															//가장 큰 y값과 가장 작은 y값의 차가 세로의 길이가 됩니다.
	}														//그 두 값을 곱하면 직사각형의 넓이가 됩니다.

	return 0;
}