#include <bits/stdc++.h>
using namespace ::std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

string board[1000]; // 공백이 없는 문자열 형태로 주어지므로 string 형으로 입력 받는다.
int dist[1000][1000][2]; // 거리 저장용 (각 인덱스는 x, y, 벽을 부순 여부이다.)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, found = 0; // n, m, 최단거리 존재 여부
    queue<tuple<int,int,int>> myqueue; // BFS용 큐

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> board[i];
        for(int j = 0; j < m; j++){
            // cin >> board[i][j];

            dist[i][j][0] = -1;
            dist[i][j][1] = -1;
        }
    }

    dist[0][0][0] = dist[0][0][1] = 1;
    myqueue.push({0,0,0});

    while(!myqueue.empty()){
        auto cur = myqueue.front();
        myqueue.pop();

        int cur_x, cur_y, broken;

        tie(cur_x, cur_y, broken) = cur;

        if(cur_x == n-1 && cur_y == m-1){
            cout << dist[n-1][m-1][broken];
            found++; // 찾았다는 표시
            break; // cur_x = n-1, cur_y = m-1인 경우를 찾았다는 것은 이 경우가 최단거리이므로 while문에서 break
        }

        for(int dir = 0; dir < 4; dir++){
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위를 벗어나면 continue

            if(board[nx][ny] == '0' && dist[nx][ny][broken] == -1){
                myqueue.push({nx, ny, broken});
                dist[nx][ny][broken] = dist[cur_x][cur_y][broken] + 1;
            }

            if(board[nx][ny] == '1' && !broken && dist[nx][ny][1] == -1){
                myqueue.push({nx,ny,1});
                dist[nx][ny][1] = dist[cur_x][cur_y][broken] + 1;
            }
        }
    }

    if(dist[n-1][m-1][0] >= 0) cout << dist[n-1][m-1][0];
    else if(dist[n-1][m-1][1] >= 0) cout << dist[n-1][m-1][1];
    else cout << "-1";

    if(!found) cout << "-1"; // found가 0일때 참이므로, BFS 실행결과 최단거리가 없다는 뜻이므로 -1 출력

    return 0;

}