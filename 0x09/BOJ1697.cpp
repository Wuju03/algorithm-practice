/*
문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
*/
#include <bits/stdc++.h>
using namespace ::std;

int time_route[100002];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    fill(time_route, time_route + 100001, -1);

    int n, k;
    queue<int> subin;

    cin >> n >> k;

    subin.push(n);
    time_route[n] = 0; // 시작점이므로 경과시간은 0

    while(time_route[k] == -1){
        int cur = subin.front();
        subin.pop();

        for(int p : {cur+1, cur-1, cur*2}){
            if(p < 0 || p > 100000) continue;
            if(time_route[p] >= 0) continue;

            time_route[p] = time_route[cur] + 1;
            subin.push(p); // 현재 위치가 결국 다음 BFS 시작 위치
        }
    }

    cout << time_route[k];

    return 0;

}