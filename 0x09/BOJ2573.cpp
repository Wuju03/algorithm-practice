#include <bits/stdc++.h>
#define X first
#define Y second
using namespace ::std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int board[300][300]; // 빙산 지도
int tmp[300][300]; // 임시 지도

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m; // 배열 크기
    int year = 0; // 소요된 년수
    int found = 0; // 두 덩이 이상으로 쪼개지는 경우 1이 됨
    
    cin >> n >> m; // x = n, y = m

    int vis[n][m]; // 방문 여부를 저장

    for(int i = 0; i < n; i++){ // 보드에 입력받는 for문
            for(int j = 0; j < m; j++){
                cin >> board[i][j];
            }
        }

    while(1){ // 최대 10년 경과 가능 -> 이건 너무 단정지었음(실패 요인?)

        // year++; // 1년 경과

        int area = 0; // 구역 개수 0으로 초기화

        for(int i = 0; i < n; i++){ // vis 초기화
            fill(vis[i], vis[i]+m, 0);
        }

        // 구역 개수 세는 BFS
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0 || vis[i][j] == 1) continue;

                queue<pair<int,int>> myqueue;

                myqueue.push({i,j});
                vis[i][j] = 1;

                area++;

                while(!myqueue.empty()){
                    auto cur = myqueue.front();
                    myqueue.pop();

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(board[nx][ny] == 0 || vis[nx][ny] == 1) continue;

                        myqueue.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }

        if(area >= 2){ // 두 덩이 이상으로 쪼개질 경우 걸린 시간 출력 후 break
            cout << year;
            found++;
            break;
        } else if(area == 0) break; // 만약 다 녹아버릴경우 그냥 break

        // 빙산 녹이기
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0) continue; // 바다면 녹일 필요 없으므로 continue

                int mpy = 0; // minus per year

                for(int dir = 0; dir < 4; dir++){
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                    if(board[nx][ny] == 0) mpy++; // 상하좌우 확인했는데 0이면 더 빨리 녹으므로 mpy 1 증가
                }

                if(board[i][j] - mpy > 0) tmp[i][j] = board[i][j] - mpy;
                else tmp[i][j] = 0;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                board[i][j] = tmp[i][j];
            }
        }

        year++;

    }

    if(!found) cout << "0"; // 그냥 break 될 경우 !found는 1이므로 0 출력 됨

    return 0;
}