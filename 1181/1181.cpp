#include <iostream>
#include <algorithm>
using namespace std;
bool compare(const string& a, const string& b) {
	int length = min(a.length(), b.length());	//더 짧은 문자열의 길이를 저장합니다.

	if (a.length() < b.length()) {	//문자열의 길이를 비교합니다.
		return true;				//짧은것이 앞에 오도록 합니다.
	} else if (a.length() > b.length()) {
		return false;
	} else {						//문자열의 길이가 같은 경우입니다.
		for (int i = 0; i < length; i++) {	//사전순 비교시에 짧은 문자열의 길이에 맞춰 비교합니다.
			if (a[i] < b[i]) return true;	//길이가 같을 때는 사전순으로 정렬합니다.
			if (a[i] > b[i]) return false;
		}
	}

	return a.length() < b.length();
}
int main() {
	int N;	//문자열의 개수 입니다.
	cin >> N;

	string* array = new string[N];	//문자열의 개수만큼 배열을 할당합니다.

	for (int i = 0; i < N; i++) {	//문자열들을 입력합니다.
		cin >> array[i];
	}

	sort(array, array + N, compare);	//문자열을 compare라는 조건으로 정렬합니다.

	cout << array[0] << endl;	//정렬된 문자열을 출력합니다.
	for (int i = 1; i < N; i++) {
		if (array[i] != array[i - 1]) {	//이 때, 중복되는 문자열은 하나만 출력합니다.
			cout << array[i] << '\n';
		}
	}

	return 0;
}