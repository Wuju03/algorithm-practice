/*
해결법
N이 4일때는 예시로 듬

1번 스택 생성 후, 카드 채워 넣기
아래(back)
4
3
2
1
위(front)

2번 pop 실행
아래(back)
4
3
2
1 삭제(pop)
위(front)

3번 front 원소를 임시 변수에 저장 후, pop 한 번 더 실행
int K; // 임시변수
K = card.front();

아래(back)
4
3
2 삭제(pop)
위(front)

4번 임시 변수 값 push
아래(back)
2 삽입(push)
4
3
위(front)

2~4 반복을 큐 size가 1이 될때까지 반복
*/
#include <bits/stdc++.h>
using namespace ::std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    queue<int> card;
    int N;

    cin >> N;

    for(int i = 0; i < N; i++) card.push(i+1);

    while(card.size() != 1){ // 1이 될때까지 반복이므로, 1이 아닐때 참이면 됨
        card.pop();
        int K = card.front();
        card.pop();
        card.push(K);
    }

    cout << card.front();

    return 0;
}