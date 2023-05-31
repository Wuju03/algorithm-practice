#include <bits/stdc++.h>
#define X first
#define Y second
using namespace ::std;

int board[1000][1000];
int dist[1000][1000];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    queue<pair<int,int>> myqueue; // BFS용 큐

    int n, m;
    cin >> m >> n; // 토마토 상자의 세로가 m, 가로가 n이기에

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];

            if(board[i][j] == 1) myqueue.push({i,j}); // 익은 토마토의 상하좌우로 BFS가 이뤄져야하므로 큐에 푸쉬
            if(board[i][j] == 0) dist[i][j] = -1; // 거리가 사실상 토마토가 익는데 필요한 일 수임
        }
    }

    while(!myqueue.empty()){
        pair<int,int> cur = myqueue.front(); // cur pair 변수에 큐의 head부분 정보 받아오기
        myqueue.pop(); // 그 정보를 받아왔으니 큐에서 제거

        for(int dir = 0; dir < 4; dir++){ // 상하좌우를 살펴보는 BFS를 실행해야함
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 정해진 범위를 벗어나면 다음 루프
            if(dist[nx][ny] >= 0) continue; // 이미 거리(날 수)가 부여되었으면 다음 루프

            dist[nx][ny] = dist[cur.X][cur.Y] + 1; // 1칸 차이나면 날 수도 1일 차이 남
            myqueue.push({nx,ny}); // 현재 루프를 도는 칸 또한 익은 토마토가 되므로, 다음 BFS의 대상
        }
    }

    int date = 0; // 최종 걸린 날 수
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dist[i][j] == -1){ // 초기값은 0, 초기값으로만 남아있을 수 있는 것은 비어있는 공간 뿐임 -> -1이라면 익지 않은 토마토임
                cout << "-1";
                return 0;
            }

            date = max(date, dist[i][j]);
        }
    }

    cout << date;

    return 0;

}