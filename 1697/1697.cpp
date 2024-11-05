#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int bfs(int start, int target) {
    vector<int> visited(100001, -1);    // -1로 초기화하여 미방문 상태 표시 -> 방문 정보와 동시에 시간값을 저장함
    queue<int> q;                       //탐색작업 목록

    // 시작 위치 설정
    q.push(start);           //시작 위치를 탐색작업 목록의 가장 앞에 추가한다
    visited[start] = 0;      //시작 위치의 시간값을 0으로 초기화 한다.

    // BFS 시작
    while (!q.empty()) {            //사실상 while(true)와 다른것이 없음.
        int current = q.front();    //작업을 실행할 준비를 하고 작업 목록을 비워준다.
        q.pop();

        // 동생을 찾은 경우
        if (current == target) {
            return visited[current];    //동생을 찾은 경우 시간값을 출력한다.
        }

        // 다음 이동 위치와 소요 시간을 큐에 추가
        for (int next : {current - 1, current + 1, current * 2}) {
            if (next >= 0 && next <= 100000 && visited[next] == -1) {   //범위를 넘어가는 경우에는 실행하지 않는다.
                q.push(next);
                visited[next] = visited[current] + 1; // 이동 시간 증가
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;              //수빈이의 위치와 동생의 위치를 입력한다.

    cout << bfs(n, k) << endl;  //최소 시간값을 출력한다

    return 0;
}
