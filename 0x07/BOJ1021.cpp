/*
문제
지민이는 N개의 원소를 포함하고 있는 양방향 순환 큐를 가지고 있다. 지민이는 이 큐에서 몇 개의 원소를 뽑아내려고 한다.

지민이는 이 큐에서 다음과 같은 3가지 연산을 수행할 수 있다.

첫 번째 원소를 뽑아낸다. 이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.
큐에 처음에 포함되어 있던 수 N이 주어진다. 그리고 지민이가 뽑아내려고 하는 원소의 위치가 주어진다. (이 위치는 가장 처음 큐에서의 위치이다.) 이때, 그 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 큐의 크기 N과 뽑아내려고 하는 수의 개수 M이 주어진다. N은 50보다 작거나 같은 자연수이고, M은 N보다 작거나 같은 자연수이다. 둘째 줄에는 지민이가 뽑아내려고 하는 수의 위치가 순서대로 주어진다. 위치는 1보다 크거나 같고, N보다 작거나 같은 자연수이다.

출력
첫째 줄에 문제의 정답을 출력한다.

1. 첫번째 원소를 뽑아내는 연산

*/
#include <bits/stdc++.h>
using namespace ::std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    deque<int> mydeque;
    int N, M;
    int count = 0; // 2, 3번 명령 실행 횟수

    cin >> N; // 순환 큐의 크기 입력받기
    cin >> M; // 뽑아내려고 하는 수의 개수 입력 받기

    int num[M];

    for(int i = 0; i < M; i++){
        cin >> num[i]; // 후보 숫자군 입력받기
    }
    
    for(int i = 1; i <= N; i++){ // 1~N까지의 덱 생성
        mydeque.push_back(i);
    }

    for(int i = 0; i < M; i++){ // M개의 원소를 뽑아내기(M번 반복)
        int idx; // 후보 군의 현재 인덱스
        idx = find(mydeque.begin(), mydeque.end(), num[i]) - mydeque.begin(); // 후보 군의 현재 인덱스 찾기
        while(mydeque.front() != num[i]){ // head 부분에 후보 숫자군이 없다면 반복
            if(idx < mydeque.size() - idx){ // 왼쪽으로 이동시키는 길이 < 오른쪽으로 이동시키는 길이 -> 2번 명령어 실행
                mydeque.push_back(mydeque.front()); // 왼쪽으로 이동 시키면, 앞의 원소가 뒤로 이동해야하므로
                mydeque.pop_front(); // 앞의 원소가 뒤로 이동했으니, 중복 되는 앞의 원소 제거
            } else {
                mydeque.push_front(mydeque.back()); // 오른쪽으로 이동 시키면, 뒤의 원소가 앞으로 이동해야하므로
                mydeque.pop_back(); // 뒤의 원소가 앞으로 이동했으니, 중복 되는 뒤의 원소 제거
            }

            count++; // 실행 횟수 증가
        }

        mydeque.pop_front(); // 후보 원소 찾았으므로 뽑고, 다음 후보 원소 찾기 실행
    }

    cout << count;

    return 0;

}