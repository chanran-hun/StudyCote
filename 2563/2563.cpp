#include <iostream>
using namespace std;

int main() {
	const int size = 100;	//도화지의 가로, 세로 사이즈 입니다.
	int canvas[size][size] = { 0 };	//도화지의 초기값은 모두 0으로 초기화 해 둡니다.

	int num_paper;	//붙일 색종이의 개수 입니다.
	cin >> num_paper;

	for (int i = 0; i < num_paper; i++) {	
		int x;	//각 색종이의 가로 시작위치 입니다.
		int y;	//각 색종이의 세로 시작위치 입니다.
		cin >> x >> y;

		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				canvas[j][k] = 1;	//도화지에서 색종이가 붙은 위치를 모두 1로 바꾸어줍니다.
			}
		}
	}
	
	int area = 0;	//색종이가 붙은 넓이의 총합을 저장할 변수 입니다.
	for (int i = 0; i < size; i++) {	//도화지에서 1인 부분이 발견될 때 마다 area변수의 크기를 1씩 늘려줍니다.
		for (int j = 0; j < size; j++) {
			if (canvas[i][j] == 1) {
				area++;
			}
		}
	}

	cout << area << '\n';	//구한 넓이의 총합인 area를 출력합니다.
	
	return 0;
}