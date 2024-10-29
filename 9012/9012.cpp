#include <iostream>
#include <stack>
using namespace std;

int main() {
	int num;
	cin >> num;	//반복횟수 입력

	for (int i = 0; i < num; i++) {	
		string VPS;
		cin >> VPS;		//괄호쌍 입력

		stack<char> units;
		for (char unit : VPS) {
			if (unit == '(') {
				units.push(unit);	//왼쪽괄호는 스택에 저장
			} else {
				if (!units.empty()) {
					if (unit != units.top()) {	//오른쪽 괄호가 입력되었을때 왼쪽 괄호가 스택 안에 
						units.pop();			//있다면 왼쪽괄호 하나 삭제
					} else {
						units.push(unit);		//왼쪽괄호가 없다면 오른쪾 괄호 저장
					}
				} else {
					units.push(unit);			//스택이 비어있다면 오른쪽 괄호 저장
				}
			}
		}

		if (units.empty()){			//스택이 비어있으면 모든 괄호가 짝이 맞다는 뜻이므로
			cout << "YES" << endl;	//VPS가 맞다고 출력
		} else {					//비어있다면
			cout << "NO" << endl;	//아니라고 출력
		}
	}
	return 0;
}