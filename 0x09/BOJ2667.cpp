#include <bits/stdc++.h>
#define X first
#define Y second
using namespace ::std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string danji[25];

int vis[25][25];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n; // 지도 크기

    int count = 0; // 단지 개수

    vector<int> result; // 단지 넓이들 저장해둘 벡터(초기에 크기 미정이고, 나중에 정렬까지 해야하므로 벡터 사용)

    cin >> n;

    for(int i = 0; i < n; i++) cin >> danji[i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(danji[i][j] == '0' || vis[i][j] == 1) continue; // danji는 string형이므로 아스키코드 주의

            count++;

            queue<pair<int,int>> myqueue;
            myqueue.push({i,j});
            vis[i][j] = 1;

            int area = 1;

            while(!myqueue.empty()){
                auto cur = myqueue.front();
                myqueue.pop();

                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(danji[nx][ny] == '0' || vis[nx][ny] == 1) continue; // danji는 string형이므로 아스키코드 주의

                    area++;
                    myqueue.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
            result.push_back(area);
        }
    }

    sort(result.begin(), result.end());

    cout << count << '\n';

    for(auto r : result){
        cout << r << '\n';
    }

    return 0;

}