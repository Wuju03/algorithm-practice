#include <bits/stdc++.h>
#define X first
#define Y second
using namespace ::std;

// 말처럼 움직일때 필요한것
int dx_horse[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy_horse[] = {1, 2, 2, 1, -1, -2, -2, -1};

// 원숭이처럼 움직일때
int dx_monkey[] = {1, 0, -1, 0};
int dy_monkey[] = {0, 1, 0, -1};

int board[200][200];
int dist[200][200];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int k, w, h; // 말처럼 움직이는 횟수, y, x

    cin >> k >> w >> h;

    // 거리 -1로 초기화
    for(int i = 0; i < h; i++){
        fill(dist[i], dist[i]+w, -1);
    }

    // 보드에 입력받기
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> board[i][j];

            if(board[i][j] == 1) dist[i][j] = 0;
        }
    }

    queue<pair<int,int>> myqueue;

    // 시작점 소요시간은 0
    dist[0][0] = 0;
    myqueue.push({0,0});

    while(!myqueue.empty() && k){
        auto cur = myqueue.front();
        myqueue.empty();

        for(int dir = 0; dir < 6; dir++){
            int nx = cur.X + dx_horse[dir];
            int ny = cur.Y + dy_horse[dir];

            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(board[nx][ny] == 1 || dist[nx][ny] >= 0) continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            myqueue.push({nx,ny});
        }

        k--;
    }

    while(!myqueue.empty()){
        auto cur = myqueue.front();
        myqueue.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx_monkey[dir];
            int ny = cur.Y + dy_monkey[dir];

            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(dist[nx][ny] >= 0) continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            myqueue.push({nx,ny});
        }
    }

    cout << dist[h-1][w-1];

    return 0;

}