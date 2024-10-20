#include <iostream>
#include <algorithm>
using namespace std;
int binarySearch(int finder, int* numbers, int low, int high) {	//이진탐색

	while ( low <= high ) {	//종료조건
		int mid = (low + high) / 2;

		if (finder < numbers[mid]) {	//중간값보다 작을경우
			high = mid - 1;					
		} else if (finder == numbers[mid]) {	//같을경우
			return 1;
		} else {						//중간값보다 클 경우
			low = mid + 1;
		}
	}
	
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);  // 입출력 속도 최적화
	cin.tie(nullptr);  // cin과 cout을 묶지 않음

	int* numbers;	//대상 배열
	int size;

	cin >> size;	//대상배열의 크기
	numbers = new int[size];

	for (int i = 0; i < size; i++) {	//대상배열 입력
		cin >> numbers[i];
	}

	sort(numbers, numbers + size);		//오름차순으로 정렬

	int size2;
	int* finders;	//탐색배열

	cin >> size2;
	finders = new int[size2];

	for (int i = 0; i < size2; i++) {	//탐색배열 입력
		cin >> finders[i];
		cout << binarySearch(finders[i], numbers, 0, size - 1) << '\n';	//결과출력
	}

	return 0;
}