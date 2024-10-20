#include <iostream>
using namespace std;
bool isGroupWord(string &word) {	//그룹단어 판별함수
	bool visited[26] = { false };	//각각의 알파벳에 대해서 중복 여부를 확인한다
	char prev = '\0';

	for (char ch : word) {	
		if (ch != prev) {			//이전 알파벳과 현재 알파벳이 다르다면 현재 알파벳이 등장한적 있는지 확인한다
			if (visited[ch - 'a']) {
				return false;		//등장한적 있다면 거짓을 반환한다(그룹단어가 아니기 때문)
			} 
			visited[ch - 'a'] = true;	//등장한 적 없다면 해당 알파벳의 등장 정보를 참으로 바꾼다
		}
		prev = ch;						//현재 단어를 현재 순서에 저장한다
	}

	return true;						// 모든 단계에서 거짓이 반환된 적 없다면 참을 반환한다
}
int main() {
	int numString;						//입력될 문자열의 개수
	cin >> numString;

	int result = 0;						//결과값, 그룹단어가 몇개였는지

	string str;

	for (int i = 0; i < numString; i++) {
		cin >> str;						//정해진 횟수만큼 문자열을 입력
		if (isGroupWord(str)) {			//문자열의 그룹단어 여부를 확인
			result++;					//그룹단어라면 결과값 증가
		}
	}

	cout << result << endl;				//결과값 출력

	return 0;
}