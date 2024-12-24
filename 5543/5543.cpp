#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int b1, b2, b3, c, s;	//3개의 버거와 콜라, 사이다 입니다
	int cheap_b, cheap_d;	//가장 싼 버거, 음료수입니다.

	cin >> b1 >> b2 >> b3 >> c >> s;	

	cheap_b = min(b1, b2);	
	cheap_b = min(b3, cheap_b);	//cheap_b에 가장 싼 버거의 가격을 저장하는 과정입니다.
	cheap_d = min(c, s);		//cheap_d에 가장 싼 음료의 가격을 저장하는 과정입니다.

	cout << cheap_b + cheap_d - 50 << '\n';	//가장 싼 버거와 가장 싼 음료로 가장 싼 세트의 가격을 정하는 과정입니다.

	return 0;
}