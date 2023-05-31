/*
문제
차세대 영농인 한나는 강원도 고랭지에서 유기농 배추를 재배하기로 하였다. 농약을 쓰지 않고 배추를 재배하려면 배추를 해충으로부터 보호하는 것이 중요하기 때문에, 한나는 해충 방지에 효과적인 배추흰지렁이를 구입하기로 결심한다. 이 지렁이는 배추근처에 서식하며 해충을 잡아 먹음으로써 배추를 보호한다. 특히, 어떤 배추에 배추흰지렁이가 한 마리라도 살고 있으면 이 지렁이는 인접한 다른 배추로 이동할 수 있어, 그 배추들 역시 해충으로부터 보호받을 수 있다. 한 배추의 상하좌우 네 방향에 다른 배추가 위치한 경우에 서로 인접해있는 것이다.

한나가 배추를 재배하는 땅은 고르지 못해서 배추를 군데군데 심어 놓았다. 배추들이 모여있는 곳에는 배추흰지렁이가 한 마리만 있으면 되므로 서로 인접해있는 배추들이 몇 군데에 퍼져있는지 조사하면 총 몇 마리의 지렁이가 필요한지 알 수 있다. 예를 들어 배추밭이 아래와 같이 구성되어 있으면 최소 5마리의 배추흰지렁이가 필요하다. 0은 배추가 심어져 있지 않은 땅이고, 1은 배추가 심어져 있는 땅을 나타낸다.

1	1	0	0	0	0	0	0	0	0
0	1	0	0	0	0	0	0	0	0
0	0	0	0	1	0	0	0	0	0
0	0	0	0	1	0	0	0	0	0
0	0	1	1	0	0	0	1	1	1
0	0	0	0	1	0	0	1	1	1
입력
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 그 다음 줄부터 각각의 테스트 케이스에 대해 첫째 줄에는 배추를 심은 배추밭의 가로길이 M(1 ≤ M ≤ 50)과 세로길이 N(1 ≤ N ≤ 50), 그리고 배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)이 주어진다. 그 다음 K줄에는 배추의 위치 X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)가 주어진다. 두 배추의 위치가 같은 경우는 없다.

출력
각 테스트 케이스에 대해 필요한 최소의 배추흰지렁이 마리 수를 출력한다.

전에 풀었던 그림 문제와 유사 -> 그림문제보다도 쉬움 -> 그림 개수만 뽑아내는 식으로 하면 됨
*/
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace ::std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void count_bug(int n, int m, int k);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, k, T;

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> m >> n >> k;
        count_bug(n, m, k);
    }

    return 0;

}

void count_bug(int n, int m, int k){
    int num = 0; // 이 테스트케이스에 필요한 지렁이 마리수

    int bat[n][m]; // 밭 좌표판
    int vis[n][m]; // 좌표판 방문기록

    for(int i = 0; i < n; i++){
        fill(bat[i], bat[i]+m, 0); // 밭 초기화
        fill(vis[i], vis[i]+m, 0); // 방문기록 초기화
    }

    for(int i = 0; i < k; i++){
        int t1, t2;

        cin >> t1 >> t2; // 좌표가 반대로 되어있음

        bat[t2][t1] = 1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(bat[i][j] != 1 || vis[i][j] == 1) continue; // 배추가 없거나, 방문한 적이 있으면 컨티뉴

            queue<pair<int,int>> myqueue;

            num++;

            myqueue.push({i,j});
            vis[i][j] = 1;

            while(!myqueue.empty()){ // 배추 군집의 크기 측정하는 BFS

                auto cur = myqueue.front();
                myqueue.pop();

                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(bat[nx][ny] != 1 || vis[nx][ny] == 1) continue;

                    vis[nx][ny] = 1;
                    myqueue.push({nx,ny});
                }
            }
        }
    }

    cout << num << '\n';

}