#include <bits/stdc++.h>
#define X first
#define Y second
using namespace ::std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int height[100][100]; // 높이 저장해두는 배열
int vis[100][100]; // 방문여부 저장해두는 배열

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int max_area_count = 0; // 최대 영역 개수를 저장해두는 변수

    int n; // 지도 크기

    int maxh = 0, minh = 100; // 최대 높이와 최소 높이 변수 초기화

    cin >> n; // 지도 크기 입력 받기

    for(int i = 0; i < n; i++){ // 높이를 입력 받기 + 최소 최대 높이 찾기
        for(int j = 0; j < n; j++){
            cin >> height[i][j];

            maxh = max(maxh, height[i][j]);
            minh = min(minh, height[i][j]);
        }
    }

    for(int i = minh; i <= maxh; i++){ // 최소 높이에서, 최대 높이까지 올라감

        for(int k = 0; k < n; k++) fill(vis[k], vis[k]+n, 0); // 방문 배열 초기화

        int area_count = 0; // 영역 개수 0개로 시작

        for(int p = 0; p < n; p++){
            for(int q = 0; q < n; q++){
                if(vis[p][q] || i > height[p][q]) continue; // 방문한 적이 있거나, 침수되었으면 컨티뉴

                area_count++;

                queue<pair<int,int>> myqueue;
                myqueue.push({p,q});
                vis[p][q] = 1;

                while(!myqueue.empty()){

                    auto cur = myqueue.front();
                    myqueue.pop();

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(i > height[nx][ny] || vis[nx][ny]) continue;

                        myqueue.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }

        max_area_count = max(max_area_count, area_count);

    }

    cout << max_area_count;

    return 0;
}