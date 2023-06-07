#include <bits/stdc++.h>
using namespace ::std;

string board[30][30]; // z x y
int dist[30][30][30]; // z x y

int dx[] = {1, 0, -1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int l, r, c; // 층수, x, y

    
    while(1){
        cin >> l >> r >> c;

        if(l == 0 && r == 0 && c == 0) break;

        int target_x, target_y, target_z;

        queue<tuple<int,int,int>> myqueue;

        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                fill(dist[i][j], dist[i][j]+30, 0);
            }
        }

        for(int i = l-1; i >= 0; i--){
            for(int j = 0; j < r; j++){
            cin >> board[i][j];
            }
        }

        for(int i = l-1; i >= 0; i--){
            for(int j = 0; j < r; j++){
            for(int q = 0; q < c; q++){
                    if(board[i][j][q] == 'S') myqueue.push({i, j, q});
                    if(board[i][j][q] == '.') dist[i][j][q] = -1;
                    if(board[i][j][q] == 'E'){
                        target_x = j;
                        target_y = q;
                        target_z = i;
                    }
            }
            }
        }

        while(!myqueue.empty()){
            auto cur = myqueue.front();
            myqueue.pop();

            int cur_x, cur_y, cur_z;

            tie(cur_z, cur_x, cur_y) = cur;

            for(int dir = 0; dir < 6; dir++){
                int nx = cur_x + dx[dir];
                int ny = cur_y + dy[dir];
                int nz = cur_z + dz[dir];

                if(nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
                if(board[nz][nx][ny] == '#' || dist[nz][nx][ny] > 0) continue;

                myqueue.push({nz, nx, ny});
                dist[nz][nx][ny] = dist[cur_z][cur_x][cur_y] + 1;
            }
        }

        if(dist[target_z][target_x][target_y] > 0) cout << "Escaped in " << dist[target_z][target_x][target_y] << " minute(s)." << '\n';
        else cout << "Trapped!" << '\n';
    }

    

    return 0;


}