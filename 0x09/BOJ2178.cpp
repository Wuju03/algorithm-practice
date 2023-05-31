#include <bits/stdc++.h>
#define X first
#define Y second
using namespace ::std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string miro[100];
int dist[100][100];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    queue<pair<int,int>> myqueue;

    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> miro[i];

    for(int i = 0; i < n; i++) fill(dist[i],dist[i]+m, -1);

    myqueue.push({0,0});
    dist[0][0] = 0; // 1,1이 시작점이므로 거리는 0

    while(!myqueue.empty()){
        auto cur = myqueue.front();
        myqueue.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(miro[nx][ny] != '1' || dist[nx][ny] >= 0) continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            myqueue.push({nx,ny});
        }
    }

    cout << dist[n-1][m-1] + 1; // n-1, m-1이 결국 n, m임. 그곳까지의 거리 + 1이 지나온 칸의 개수

    return 0;

}