#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n = 7, m = 10; // n = 행의 수, m = 열의 수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    queue<pair<int, int>> myqueue;

    vis[0][0] = 1;
    myqueue.push({0, 0});

    while(!myqueue.empty()){
        pair<int, int> cur = myqueue.front();
        myqueue.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir]; // 현재좌표의 상하좌우를 확인하기 위해 -1, 0, 1을 더해주기
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx > 7 || ny < 0 || ny > 10) continue; // 보드판 범위를 넘거나
            if(board[nx][ny] != 1 || vis[nx][ny] == 1) continue; // 파란색 칸이 아니거나 이미 방문한 칸이면 continue

            vis[nx][ny] = 1; // 현재 좌표 상하좌우를 방문했으므로, 방문했다고 저장하기
            
            myqueue.push({nx, ny}); // 점검한 현재 좌표의 상하좌우를 시작점으로 삼아야하므로, 큐에 push 해주기
        }

    }

    return 0;
    
}