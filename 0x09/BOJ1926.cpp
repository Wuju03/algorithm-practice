#include <bits/stdc++.h>
#define X first
#define Y second
using namespace ::std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[500][500];
int vis[500][500];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    int num = 0, mxarea = 0; // 그림 개수, 최대넓이

    cin >> n >> m;

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> board[i][j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] != 1 || vis[i][j] == 1) continue; // 그림이 없거나, 방문한 적 있는 칸이면 컨티뉴

            queue<pair<int,int>> myqueue;

            num++;

            int area = 0;

            myqueue.push({i,j}); // 푸쉬하기
            vis[i][j] = 1; // 방문 한 적 있다고 표시

            while(!myqueue.empty()){
                area++;

                auto cur = myqueue.front();
                myqueue.pop();

                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(board[nx][ny] != 1 || vis[nx][ny] == 1) continue;

                    myqueue.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }

            mxarea = max(mxarea, area);

        }
    }

    cout << num << '\n' << mxarea;
}