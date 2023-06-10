#include <bits/stdc++.h>
using namespace ::std;

// 말처럼 움직일때 필요한것
int dx_horse[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy_horse[] = {1, 2, 2, 1, -1, -2, -2, -1};

// 원숭이처럼 움직일때
int dx_monkey[] = {1, 0, -1, 0};
int dy_monkey[] = {0, 1, 0, -1};

int board[200][200];
int dist[31][200][200];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int k, w, h; // 말처럼 움직이는 횟수, y, x

    cin >> k >> w >> h;
    
    // 보드에 입력받기
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> board[i][j];
        }
    }


    queue<tuple<int,int,int>> myqueue;

    int min_time = 15571557;

    // 시작점 소요시간은 0이지만 보드의 크기가 1일때도 고려해야하므로 1로 지정
    dist[0][0][0] = 1;
    myqueue.push({0,0,0});

    while(!myqueue.empty()){
        auto cur = myqueue.front();
        myqueue.pop();

        int count, cur_x, cur_y;

        tie(count, cur_x, cur_y) = cur;

        if(count < k){
            for(int dir = 0; dir < 8; dir++){
                int nx = cur_x + dx_horse[dir];
                int ny = cur_y + dy_horse[dir];

                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(board[nx][ny] || dist[count+1][nx][ny]) continue;

                dist[count+1][nx][ny] = dist[count][cur_x][cur_y] + 1;
                myqueue.push({count + 1, nx, ny});
            }
        }
        

        for(int dir = 0; dir < 4; dir++){
            int nx = cur_x + dx_monkey[dir];
            int ny = cur_y + dy_monkey[dir];

            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(board[nx][ny] || dist[count][nx][ny]) continue;

            dist[count][nx][ny] = dist[count][cur_x][cur_y] + 1;
            myqueue.push({count, nx, ny});
        }
    }

    for(int p = 0; p < k + 1; p++){
        if(dist[p][h-1][w-1]) min_time = min(min_time, dist[p][h-1][w-1]);
    }

    // 시작점 소요시간은 0이지만, 초기값을 1로 지정했으므로 1 감소시켜 출력
    if(min_time != 15571557) cout << min_time - 1;
    else cout << "-1";

    return 0;

}