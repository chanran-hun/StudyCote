#include <iostream>
#include <algorithm>
using namespace std;
class member {
public:
	string name;
	int age;
	int order;
};

bool compare(member& a, member& b) {
	if (a.age < b.age) {
		return true;
	} else if (b.age < a.age) {
		return false;
	} else {
		if (a.order < b.order) {
			return true;
		} else {
			return false;
		}
	}
}

int main() {
	int N;
	cin >> N;
	member* array = new member[N];

	for (int i = 0; i < N; i++) {
		cin >> array[i].age >> array[i].name;
		array[i].order = i;
	}

	sort(array, array + N,compare);

	for (int i = 0; i < N; i++) {
		cout << array[i].age << " " << array[i].name << endl;
	}

	return 0;
}