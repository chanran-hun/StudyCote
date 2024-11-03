#include <iostream>
using namespace std;

class Node {	
public:
	int data;
	Node* next;
	Node* prev;

	Node(int value) {
		data = value;
		next = nullptr;
		prev = nullptr;
	}
};

class Deque {	
	Node* front;
	Node* back;
public:
	Deque() {
		front = nullptr;
		back = nullptr;
	}

	void push_front(int value) {	//덱의 가장 앞에 새로운 원소 추가
		Node* node = new Node(value);

		if (front == nullptr) {
			front = node;
			back = node;
		} else {
			node->next = front;
			front->prev = node;
			front = node;
		}
	}

	void push_back(int value) {		//덱의 가장 뒤에 새로운 원소 추가
		Node* node = new Node(value);

		if (front == nullptr) {
			front = node;
			back = node;
		} else {
			back->next = node;
			node->prev = back;
			back = node;
		}

	}

	int pop_front() {				//덱의 가장 앞 원소를 삭제하고 값 반환
		if (front == nullptr) {
			return -1;
		}

		int temp = front->data;

		if (front->next == nullptr) {
			front = nullptr;
			back = nullptr;
			return temp;
		}

		front = front->next;
		front->prev = nullptr;
		return temp;
	}

	int pop_back() {				//덱의 가장 뒤 원소를 삭제하고 값 반환
		if (back == nullptr) {
			return -1;
		}

		int temp = back->data;

		if (back->prev == nullptr) {
			front = nullptr;
			back = nullptr;
			return temp;
		}

		back = back->prev;
		back->next = nullptr;

		return temp;
	}

	int show_front() {				//덱의 가장 앞 원소 반환
		if (front == nullptr) {
			return -1;
		}

		return front->data;
	}

	int show_back() {				//덱의 가장 뒤 원소 반환
		if (back == nullptr) {
			return -1;
		}

		return back->data;
	}

	int size() {					//덱의 크기 반환
		Node* temp = front;
		int count = 0;
		while (temp != nullptr) {
			count++;
			temp = temp->next;
		}
		return count;
	}

	int empty() {					//덱이 비어있으면 1반환, 그렇지 않으면 0반환
		if (front == nullptr) {
			return 1;
		} else {
			return 0;
		}
	}
};

int main() {
	int num;
	cin >> num;						//명령어 입력 횟수

	Deque myDeque = Deque();

	while (num--) {
		string command;						//명령어 입력
		cin >> command;

		if (command == "push_front") {		//명령어에 따른 처리
			int n;
			cin >> n;
			myDeque.push_front(n);
		} else if (command == "push_back") {
			int n;
			cin >> n;
			myDeque.push_back(n);
		} else if (command == "pop_front") {
			cout << myDeque.pop_front() << '\n';
		} else if (command == "pop_back") {
			cout << myDeque.pop_back() << '\n';
		} else if (command == "size") {
			cout << myDeque.size() << '\n';
		} else if (command == "empty") {
			cout << myDeque.empty() << '\n';
		} else if (command == "front") {
			cout << myDeque.show_front() << '\n';
		} else if (command == "back") {
			cout << myDeque.show_back() << '\n';
		}

	}

	return 0;
}