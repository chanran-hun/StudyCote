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

	void push_front(int value) {	//���� ���� �տ� ���ο� ���� �߰�
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

	void push_back(int value) {		//���� ���� �ڿ� ���ο� ���� �߰�
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

	int pop_front() {				//���� ���� �� ���Ҹ� �����ϰ� �� ��ȯ
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

	int pop_back() {				//���� ���� �� ���Ҹ� �����ϰ� �� ��ȯ
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

	int show_front() {				//���� ���� �� ���� ��ȯ
		if (front == nullptr) {
			return -1;
		}

		return front->data;
	}

	int show_back() {				//���� ���� �� ���� ��ȯ
		if (back == nullptr) {
			return -1;
		}

		return back->data;
	}

	int size() {					//���� ũ�� ��ȯ
		Node* temp = front;
		int count = 0;
		while (temp != nullptr) {
			count++;
			temp = temp->next;
		}
		return count;
	}

	int empty() {					//���� ��������� 1��ȯ, �׷��� ������ 0��ȯ
		if (front == nullptr) {
			return 1;
		} else {
			return 0;
		}
	}
};

int main() {
	int num;
	cin >> num;						//��ɾ� �Է� Ƚ��

	Deque myDeque = Deque();

	while (num--) {
		string command;						//��ɾ� �Է�
		cin >> command;

		if (command == "push_front") {		//��ɾ ���� ó��
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