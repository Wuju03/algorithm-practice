#include <bits/stdc++.h>
#define X first
#define Y second
using namespace ::std;

int monun[100][100]; // 모눈종이칸 배열
int vis[100][100]; // 방문 확인 배열

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    queue<int> queue_area; // 넓이 저장해둘 임시 큐

    int m, n, k;
    int count = 0;
    vector<int> result;

    cin >> m >> n >> k;
    
    for(int i = 0; i < k; i++){
        int x1, x2, y1, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        for(int j = y1; j < y2; j++){
            for(int p = x1; p < x2; p++){
                monun[j][p] = 1;
            }
        }
    }

    for(int i = 0; i < m; i++){ // BFS 시작(각 좌표의 지점을 시작점으로 삼아야함)
        for(int j = 0; j < n; j++){
            if(monun[i][j] == 1 || vis[i][j] == 1) continue;

            int area = 1;

            queue<pair<int,int>> myqueue;

            myqueue.push({i,j});
            vis[i][j] = 1;
            count++;

            while(!myqueue.empty()){
                auto cur = myqueue.front();
                myqueue.pop();

                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx >= m || nx < 0 || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny] == 1 || monun[nx][ny] == 1) continue;

                    myqueue.push({nx,ny});
                    vis[nx][ny] = 1;
                    area++;
                }
            }

            result.push_back(area); // 벡터에 저장
        }
    }

    sort(result.begin(), result.end());

    cout << count << '\n';

    for(auto a : result){
        cout << a << " ";
    }

    return 0;

}