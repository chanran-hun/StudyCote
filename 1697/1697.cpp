#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int bfs(int start, int target) {
    vector<int> visited(100001, -1);    // -1�� �ʱ�ȭ�Ͽ� �̹湮 ���� ǥ�� -> �湮 ������ ���ÿ� �ð����� ������
    queue<int> q;                       //Ž���۾� ���

    // ���� ��ġ ����
    q.push(start);           //���� ��ġ�� Ž���۾� ����� ���� �տ� �߰��Ѵ�
    visited[start] = 0;      //���� ��ġ�� �ð����� 0���� �ʱ�ȭ �Ѵ�.

    // BFS ����
    while (!q.empty()) {            //��ǻ� while(true)�� �ٸ����� ����.
        int current = q.front();    //�۾��� ������ �غ� �ϰ� �۾� ����� ����ش�.
        q.pop();

        // ������ ã�� ���
        if (current == target) {
            return visited[current];    //������ ã�� ��� �ð����� ����Ѵ�.
        }

        // ���� �̵� ��ġ�� �ҿ� �ð��� ť�� �߰�
        for (int next : {current - 1, current + 1, current * 2}) {
            if (next >= 0 && next <= 100000 && visited[next] == -1) {   //������ �Ѿ�� ��쿡�� �������� �ʴ´�.
                q.push(next);
                visited[next] = visited[current] + 1; // �̵� �ð� ����
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;              //�������� ��ġ�� ������ ��ġ�� �Է��Ѵ�.

    cout << bfs(n, k) << endl;  //�ּ� �ð����� ����Ѵ�

    return 0;
}
