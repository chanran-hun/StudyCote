#include <iostream>
#include <algorithm>
using namespace std;

class spot {	//좌표저장 구조체 입니다.
public:
	int x;	//x좌표	입니다.
	int y;	//y좌표 입니다.
};

bool compare(const spot& a, const spot& b) {
	if (a.x == b.x) return a.y < b.y; // x가 같으면 y 기준 정렬
	return a.x < b.x; // 기본적으로 x 기준 정렬
}

int main() {
	int n;	//좌표들의 개수 입니다.
	cin >> n;
	spot* array = new spot[n];	//개수만큼 구조체 배열을 할당합니다.
	
	for (int i = 0; i < n; i++) {
		cin >> array[i].x >> array[i].y;
	}

	sort(array, array + n, compare);	//직접 만든 compare를 규칙으로 하여 배열을 정렬합니다.

	for (int i = 0; i < n; i++) {
		cout << array[i].x << " " << array[i].y << '\n';	//정렬된 좌표들을 출력합니다.
	}

	return 0;
}