#include <iostream>
#include <unordered_map>	//freq�� �����ϱ� ���ؼ� �ʿ��� ����Դϴ�.
using namespace std;

int main() {
	ios::sync_with_stdio(false);	//��½� �ð� �ʰ��� �������� ��ġ�Դϴ�.
	cin.tie(0);

	int N, M;	//���� ����ī��� Ž�� ī���� �����Դϴ�.
	cin >> N;
	
	unordered_map<int, int> freq;	//� ���ڰ� �� �� �ִ��� ������ �ڷᱸ���Դϴ�.
	int num;

	for (int i = 0; i < N; i++) {	//����ī�带 �Է��ϴ� ���� �Դϴ�.
		cin >> num;
		freq[num]++;
	}

	cin >> M;
	
	for (int i = 0; i < M; i++) {	//Ž��ī�带 �Է��ϰ� ���ÿ� ������ ���� ����ϴ� �����Դϴ�.
		cin >> num;
		cout << freq[num] << " ";
	}
	cout << "\n";

	return 0;
}