#include <iostream>
#include <queue>
using namespace std;

queue<int> result;	//결과 값을 이곳에 저장 후 출력할 것이다.

class Node {		//직접 만든 Circle이라는 자료구조의 노드이다. 연결리스트의 노드와 동일하다.
public:
	int data;
	Node* next;
	Node(int value) {
		data = value;
		next = nullptr;
	}
};

class Circle {	//circle 자료구조이다. 시작점과 끝점을 가진다.
	Node* start;
	Node* last;	//끝점의 next는 시작점을 가리켜 계속 순환되는 구조이다.
public:	
	Circle() {	//start와 last를 nullptr로 초기화 한다.
		start = nullptr;
		last = nullptr;
	}

	void insertCircle(int value) {	//자료구조에 노드를 삽입한다
		Node* node = new Node(value);

		if (start == nullptr) {
			start = node;
			last = node;
		} else if (start->next == nullptr) {
			start->next = node;
			node->next = start;
			last = node;
		} else {
			Node* temp = start;
			while (temp->next != start) {
				temp = temp->next;
			}
			temp->next = node;
			node->next = start;
			last = node;
		}
	}

	void eraseByDistance(int distance) {	//자료구조에서 특정 박자로 원소를 제거하는 메서드이다.
		Node* temp = start;
		while (start != last) {
			if (distance == 1) {
				result.push(start->data);
				start = temp->next;
				temp = temp->next;
				last->next = start;
			} else {
				if (temp->next == nullptr) {
					break;
				}

				for (int i = 0; i < distance-2; i++) {
					temp = temp->next;
				}

				if (temp->next->next == temp) {
					if (temp->next == start) {
						start = temp;
					}
					result.push(temp->next->data);
					temp->next = nullptr;
					continue;
				}

				if (temp->next == start) {
					start = temp->next->next;
				}
				result.push(temp->next->data);
				temp->next = temp->next->next;
				temp = temp->next;
			}
		}
		result.push(start->data);
	}
};
int main() {
	int size;		//자료구조의 크기
	int distance;	//삭제박자

	Circle myCircle = Circle();

	cin >> size >> distance;

	for (int i = 1; i <= size; i++) {	//오름차순으로 크기만큼 채워준다.
		myCircle.insertCircle(i);
	}

	myCircle.eraseByDistance(distance);	//박자대로 지워준다.

	cout << "<";
	cout << result.front();
	result.pop();
	while (!result.empty()) {			//결과를 출력한다.
		cout << ", " << result.front();
		result.pop(); 
	}
	cout << ">";

	return 0;

}