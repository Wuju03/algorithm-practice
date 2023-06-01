#include <bits/stdc++.h>
#define X first
#define Y second
using namespace ::std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string board[1000];
int fire[1000][1000];
int sangeun[1000][1000];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;

    cin >> T;

    while(T--){
        int n, m;
        int escape = 0;
        
        cin >> m >> n;

        for(int i = 0; i < n; i++){
            fill(fire[i], fire[i]+m, -1);
            fill(sangeun[i], sangeun[i]+m, -1);
        }

        queue<pair<int,int>> queue_F;
        queue<pair<int,int>> queue_S;

        for(int i = 0; i < n; i++) cin >> board[i];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(board[i][j] == '*'){ // 불 시작 위치 발견시
                    queue_F.push({i,j});
                    fire[i][j] = 0; // 경과 시간 0
                }

                if(board[i][j] == '@'){ // 상근 시작 위치 발견시
                    queue_S.push({i,j});
                    sangeun[i][j] = 0;
                }
            }
        }

        while(!queue_F.empty()){
            auto cur = queue_F.front();
            queue_F.pop();

            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 불은 범위를 벗어나서 번질 수 없음
                if(fire[nx][ny] >= 0 || board[nx][ny] == '#') continue; // 이미 번져있거나, 벽에는 번질 수 없음

                queue_F.push({nx, ny});
                fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            }
        }


        while(!queue_S.empty() && !escape){
            auto cur = queue_S.front();
            queue_S.pop();

            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m){ // 범위 벗어나면 탈출 한 것임
                    cout << sangeun[cur.X][cur.Y] + 1 << '\n';
                    escape = 1;
                    break;
                }
                
                if(sangeun[nx][ny] >= 0 || board[nx][ny] == '#') continue; // 상근이가 이미 밟은 칸이거나(다시가면 비효율적), 벽이면 컨티뉴
                if(fire[nx][ny] != -1 && fire[nx][ny] <= sangeun[cur.X][cur.Y] + 1) continue; // 불이 번지는게 확정적이고, 불이 번지는게 상근이가 가는 것과 동시에 이뤄지거나 더 빨리 이뤄지면 컨티뉴

                sangeun[nx][ny] = sangeun[cur.X][cur.Y] + 1;
                queue_S.push({nx,ny});
                
            }

        }

        if(!escape) cout << "IMPOSSIBLE" << '\n'; // 탈출하지 못 했다면
    }

    return 0;
    
}