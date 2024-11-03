#include <iostream>
#include <queue>
using namespace std;

queue<int> result;	//��� ���� �̰��� ���� �� ����� ���̴�.

class Node {		//���� ���� Circle�̶�� �ڷᱸ���� ����̴�. ���Ḯ��Ʈ�� ���� �����ϴ�.
public:
	int data;
	Node* next;
	Node(int value) {
		data = value;
		next = nullptr;
	}
};

class Circle {	//circle �ڷᱸ���̴�. �������� ������ ������.
	Node* start;
	Node* last;	//������ next�� �������� ������ ��� ��ȯ�Ǵ� �����̴�.
public:	
	Circle() {	//start�� last�� nullptr�� �ʱ�ȭ �Ѵ�.
		start = nullptr;
		last = nullptr;
	}

	void insertCircle(int value) {	//�ڷᱸ���� ��带 �����Ѵ�
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

	void eraseByDistance(int distance) {	//�ڷᱸ������ Ư�� ���ڷ� ���Ҹ� �����ϴ� �޼����̴�.
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
	int size;		//�ڷᱸ���� ũ��
	int distance;	//��������

	Circle myCircle = Circle();

	cin >> size >> distance;

	for (int i = 1; i <= size; i++) {	//������������ ũ�⸸ŭ ä���ش�.
		myCircle.insertCircle(i);
	}

	myCircle.eraseByDistance(distance);	//���ڴ�� �����ش�.

	cout << "<";
	cout << result.front();
	result.pop();
	while (!result.empty()) {			//����� ����Ѵ�.
		cout << ", " << result.front();
		result.pop(); 
	}
	cout << ">";

	return 0;

}