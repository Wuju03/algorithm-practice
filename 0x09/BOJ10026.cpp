/*
적록색약은 빨강이랑 초록 구분 힘듬
그림 문제랑 비슷해요(구역 2개만 분류하면 됨)

빨강 + 초록 => 1
파랑 => 0으로 두면 됨

BFS 돌려서 구역 개수 구하면 끝
*/
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace ::std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string color[100];

int vis[100][100];
int n; // n은 BFS 함수에서도 사용해야하므로 전역변수로 선언

void BFS(int p, int q){
    queue<pair<int,int>> myqueue;

    vis[p][q] = 1;
    myqueue.push({p,q});
    
    while(!myqueue.empty()){
        auto cur = myqueue.front();
        myqueue.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위 넘어가면 continue
            if(vis[nx][ny] == 1 || color[cur.X][cur.Y] != color[nx][ny]) continue; // 방문한 적이 있거나, 동일한 색의 칸이 아니면 continue
            
            myqueue.push({nx,ny});
            vis[nx][ny] = 1;
        }
    }

}

int count_area(){
    int count = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!vis[i][j]){
                BFS(i,j);
                count++;
            }
        }
    }

    return count;

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    int num = 0; // 그림 개수
    
    cin >> n;

    for(int i = 0; i < n; i++) cin >> color[i]; // n* n 사이즈의 그리드 입력받기

    num = count_area();
    
    cout << num << " ";

    for(int i = 0; i < n; i++) fill(vis[i], vis[i]+n, 0); // vis 배열 초기화

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(color[i][j] == 'G') color[i][j] = 'R'; // 적록 색약은 빨강 초록 구분 힘듬
        }
    }

    num = count_area();

    cout << num;

    return 0;

}