#include <bits/stdc++.h>
#define X first
#define Y second
using namespace ::std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int board[100][100]; // 지도 저장하는 배열 x y
int vis[100][100]; // 방문여부 저장하는 배열 -> 섬에 번호 매기는 BFS에만 사용
int dist[100][100]; // 다리의 길이 저장하는 배열

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n; // 지도 크기
    int num = 0; // 섬 번호
    int min_length = 15571557; // 다리의 최소 길이

    cin >> n;

    // 초기 섬 지도 입력 받기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    
    // 섬 번호 매기는 BFS
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 0 || vis[i][j] == 1) continue;

            num++; // 섬 번호 증가

            queue<pair<int,int>> myqueue;

            myqueue.push({i, j});
            vis[i][j] = 1; // 방문 표시
            board[i][j] = num; // 섬 번호 부여

            while(!myqueue.empty()){
                auto cur = myqueue.front();
                myqueue.pop();

                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 지도 범위 벗어나면 continue
                    if(board[nx][ny] == 0 || vis[nx][ny] == 1) continue; // 바다이거나, 방문 한 적 있는 땅이면 continue

                    board[nx][ny] = num;
                    vis[nx][ny] = 1;
                    myqueue.push({nx,ny});
                }
            }

        }
    }

    // 모든 점을 시작점으로 삼을 수 있는 BFS -> 다리 길이 측정
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            for(int p = 0; p < n; p++){ // dist 배열 초기화
                fill(dist[p], dist[p]+n, -1);
            }

            if(board[i][j] == 0) continue; // 시작점은 육지여야함(바다인 경우는 고려 X)

            queue<pair<int,int>> myqueue;

            dist[i][j] = 0; // 시작점 길이는 0
            myqueue.push({i,j});

            while(!myqueue.empty()){
                auto cur = myqueue.front();
                myqueue.pop();

                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위 벗어나면 continue
                    if(board[nx][ny] == board[i][j]) continue; // 출발점인 섬의 번호와 도착점의 섬의 번호가 같으면 안 됨
                    if(dist[nx][ny] >= 0) continue; // 거리가 0 이상이라는 것은, 시작점이거나 이미 갔던 곳이므로 안 됨

                    if(board[nx][ny] != 0 && board[nx][ny] != board[i][j]){ // 바다가 아닌데, 섬의 번호가 다르면 출발지와 도착지의 섬이 다르다는 뜻
                        min_length = min(min_length, dist[cur.X][cur.Y]);
                    }

                    dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                    myqueue.push({nx,ny});
                }
            }
        }
    }

    cout << min_length;
    
    return 0;


}