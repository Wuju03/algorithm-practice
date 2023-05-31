/*
문제
지훈이는 미로에서 일을 한다. 지훈이를 미로에서 탈출하도록 도와주자!

미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에 타기전에 탈출할 수 있는지의 여부, 그리고 얼마나 빨리 탈출할 수 있는지를 결정해야한다.

지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다) 이동한다.

불은 각 지점에서 네 방향으로 확산된다.

지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.

지훈이와 불은 벽이 있는 공간은 통과하지 못한다.

입력
입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다. 단, 1 ≤ R, C ≤ 1000 이다. R은 미로 행의 개수, C는 열의 개수이다.

다음 입력으로 R줄동안 각각의 미로 행이 주어진다.

각각의 문자들은 다음을 뜻한다.

#: 벽
.: 지나갈 수 있는 공간
J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
F: 불이 난 공간
J는 입력에서 하나만 주어진다.

출력
지훈이가 불이 도달하기 전에 미로를 탈출 할 수 없는 경우 IMPOSSIBLE 을 출력한다.

지훈이가 미로를 탈출할 수 있는 경우에는 가장 빠른 탈출시간을 출력한다.

예제 입력 1 
4 4
####
#JF#
#..#
#..#

예제 출력 1 
3
*/
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace ::std;

string miro[1001]; // 널문자 고려

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int time_fire[1000][1000];
int time_jihoon[1000][1000];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;

    queue<pair<int,int>> queue_fire;
    queue<pair<int,int>> queue_jihoon;

    cin >> n >> m;

    for(int i = 0; i < n; i++){ // 불과 지훈의 이동시간 배열 초기화
        fill(time_fire[i], time_fire[i]+m, -1);
        fill(time_jihoon[i], time_jihoon[i]+m, -1);
    }

    for(int i = 0; i < n; i++) cin >> miro[i]; // 미로 채우기

    for(int i = 0; i < n; i++){ // 입력 받은 미로들을 한 문자씩 확인해서 시작점(최초 발화점 + 지훈의 위치) 찾기
        for(int j = 0; j < m; j++){
            if(miro[i][j] == 'F'){
                queue_fire.push({i,j}); // BFS 최초 시작점
                time_fire[i][j] = 0; // 최초 시작점이니 경과 시간은 0
            }

            if(miro[i][j] == 'J'){
                queue_jihoon.push({i,j}); // 지훈 BFS 최초 시작점
                time_jihoon[i][j] = 0; // 최초 시작점이니 경과 시간은 0
            }
        }
    }

    while(!queue_fire.empty()){ // 불에 대한 BFS
        auto cur = queue_fire.front(); // 일단 큐에서 좌표 정보 받아오기
        queue_fire.pop(); // 정보를 받아 왔으니 그 정보 큐에서 제거

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 미로 범위를 벗어나는 곳에는 불이 안 붙음
            if(time_fire[nx][ny] >= 0 || miro[nx][ny] == '#') continue; // 이미 번져있거나, 벽인 곳은 불이 안 붙음

            time_fire[nx][ny] = time_fire[cur.X][cur.Y] + 1;
            queue_fire.push({nx,ny}); // 옮겨 붙은 곳에서 다시 시작
        }
    }

    while(!queue_jihoon.empty()){
        auto cur = queue_jihoon.front();
        queue_jihoon.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                cout << time_jihoon[cur.X][cur.Y] + 1; // 미로 범위를 벗어났다는 것 -> 탈출 했다는 것이므로 현재 위치의 시간 + 1이 탈출 시간임
                return 0;
            }
            if(time_jihoon[nx][ny] >= 0 || miro[nx][ny] == '#') continue; // 지훈이가 이미 왔다갔거나, 벽이라면 컨티뉴
            if(time_fire[nx][ny] != -1 && time_fire[nx][ny] <= time_jihoon[cur.X][cur.Y] + 1) continue; // 이동할 칸에 지훈이가 이동하기전에 불이 붙거나, 동시에 도달하면 이동 불가능

            time_jihoon[nx][ny] = time_jihoon[cur.X][cur.Y] + 1;
            queue_jihoon.push({nx,ny});
        }
    }

    cout << "IMPOSSIBLE";

}