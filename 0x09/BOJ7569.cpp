#include <bits/stdc++.h>
using namespace ::std;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int box[100][100][100];
int dist[100][100][100];

queue<tuple<int,int,int>> myqueue;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int m, n, h;

    int date = 0; // 모두 익는데 걸리는 날짜

    cin >> m >> n >> h; // y, x, z 순

    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int q = 0; q < m; q++){
                cin >> box[j][q][i];

                if(box[j][q][i] == 1) myqueue.push({j, q, i});
                if(box[j][q][i] == 0) dist[j][q][i] = -1;
            }
        }
    }

    while(!myqueue.empty()){
        auto cur = myqueue.front();
        myqueue.pop();

        int cur_x, cur_y, cur_z;

        tie(cur_x, cur_y, cur_z) = cur;

        for(int dir = 0; dir < 6; dir++){
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            int nz = cur_z + dz[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if(dist[nx][ny][nz] >= 0) continue;

            dist[nx][ny][nz] = dist[cur_x][cur_y][cur_z] + 1;
            myqueue.push({nx, ny, nz});
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int q = 0; q < m; q++){
                if(dist[j][q][i] == -1){
                    cout << "-1";
                    return 0;
                }

                date = max(date, dist[j][q][i]);
            }
        }
    }

    cout << date;

    return 0;
}