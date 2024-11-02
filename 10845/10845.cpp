#include <iostream>
using namespace std;

class LinkedListNode {
public:
	int data;					//노드에 들어간 값
	LinkedListNode* next;		//다음 노드를 가리킴

	LinkedListNode(int value) {	//노드의 생성자, 넣은 정수로 data를 초기화 하고 next는 NULL로 초기화
		data = value;
		next = nullptr;
	}
};

class Queue {
	LinkedListNode* front;	//최전방 노드
	LinkedListNode* back;	//최후방 노드

public:
	Queue() {
		front = nullptr;
		back = nullptr;	//Queue의 생성자, front와 back이 모두 NULL로 초기화 됨
	}

	~Queue() {			//Queue의 소멸자, Queue구조 내부의 노드들의 메모리를 반납
		while (front != nullptr) {
			LinkedListNode* temp = front;
			front = front->next;
			delete temp;
		}
	}

	void enQueue(int value) {	//새로운 값 삽입
		LinkedListNode* node = new LinkedListNode(value);	//노드 생성

		if (this->back == nullptr) {	//만약 노드가 하나라면 그 노드는 front이자 back이 된다
			this->front = node;
			this->back = node;
		} else {
			this->back->next = node;	//뒤에 하나를 추가했다면 그 추가된 노드가 back이 되어야 한다.
			this->back = node;
		}
	}

	int deQueue() {
		if (front == nullptr) {
			return -1;
		}

		int value = front->data;		//front 노드의 데이터값을 저장해둔다.
		LinkedListNode* temp = front;	//현재의 front를 저장해둔다
		front = front->next;	//front 다음 노드가 front가 되게 한다.
		delete temp;	//기존의 front가 차지하는 메모리 반납
		if (front == nullptr) {
			back = nullptr;						//back도 NULL이 되어야한다.
		}

		return value;
	}

	int get_front() {
		if (front == nullptr) {
			return -1;
		}

		return front->data;
	}

	int get_back() {
		if (front == nullptr) {
			return -1;
		} 
		
		return back->data;	
	}

	int size() {
		if (front == nullptr) {
			return 0;
		} 

		int count = 0;
		LinkedListNode* temp = front;

		while (temp != nullptr) {
			count++;
			temp = temp->next;
		}

		return count;
	}

	int empty() {
		if (front == nullptr) {
			return 1;
		} else {
			return 0;
		}
	}
};

int main() {
	int num;
	cin >> num;

	Queue myQueue = Queue();

	for (int i = 0; i < num; i++) {
		string command;
		cin >> command;
		if (command == "push") {
			int n;
			cin >> n;
			myQueue.enQueue(n);
		} else if (command == "front") {
			cout << myQueue.get_front() << '\n';
		} else if (command == "back") {
			cout << myQueue.get_back() << '\n';
		} else if (command == "size") {
			cout << myQueue.size() << '\n';
		} else if (command == "empty") {
			cout << myQueue.empty() << '\n';
		} else if (command == "pop") {
			cout << myQueue.deQueue() << '\n';
		}
	}

	return 0;
}