#include <bits/stdc++.h>
#define X first
#define Y second
using namespace ::std;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;

    cin >> T;

    while(T--) {
        int n;
        int cur_x, cur_y;
        int target_x, target_y;

        cin >> n;

        int dist[n][n]; // 각 보드 칸에 도달 하는데 걸리는 시간
    
        for(int i = 0; i < n; i++){ // 초기값 -1로
            fill(dist[i], dist[i]+n, -1);
        }

        queue<pair<int,int>> myqueue;

        cin >> cur_x >> cur_y;
        cin >> target_x >> target_y;

        dist[cur_x][cur_y] = 0; // 시작점이니까 0
        myqueue.push({cur_x,cur_y}); // BFS 시작점에 넣기

        while(!myqueue.empty()){
            auto cur = myqueue.front();
            myqueue.pop();

            for(int dir = 0; dir < 8; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위 벗어나면 불가능
                if(dist[nx][ny] >= 0) continue; // 이미 지정 되어있으면 불가능

                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                myqueue.push({nx,ny});
            }
        }   

        cout << dist[target_x][target_y] << '\n';
    }

    return 0;
    
}