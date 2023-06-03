#include <bits/stdc++.h>
using namespace ::std;

int dist[1000001];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int f, s, g, u, d;
    /*
    f는 빌딩의 크기
    s는 강호가 위치해있는 층
    g는 스타트링크의 입주 층
    u는 위 버튼 눌렀을때 가는 층의 개수
    d는 아래 버튼 눌렀을때 가는 층의 개수
    */

    cin >> f >> s >> g >> u >> d;

    for(int i = 1; i <= f; i++) dist[i] = -1;

    int dx[2] = {u, -d};

    queue<int> myqueue;

    myqueue.push(s);
    dist[s] = 0;

    while(!myqueue.empty()){
        auto cur = myqueue.front();
        myqueue.pop();

        for(int dir = 0; dir < 2; dir++){
            int nx = cur + dx[dir];

            if(nx < 1 || nx > f) continue;
            if(dist[nx] >= 0) continue;

            myqueue.push(nx);
            dist[nx] = dist[cur] + 1;
        }
    }

    if(dist[g] >= 0) cout << dist[g];
    else cout << "use the stairs";

    return 0;

}