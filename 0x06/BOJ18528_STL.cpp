/*
정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여섯 가지이다.

push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/
#include <bits/stdc++.h>
using namespace ::std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> myqueue;
    
    int N;

    cin >> N;

    for(int i = 0; i < N; i++){
        string command;

        cin >> command;

        if(command == "push"){
            int x;
            cin >> x;
            myqueue.push(x);
        } else if(command == "pop"){
            if(myqueue.size() == 0) cout << "-1" << '\n';
            else{
            cout << myqueue.front() << '\n'; // 앞에 있는 정수 출력 후
            myqueue.pop(); // 그 정수 빼기
            }

        } else if(command == "size"){
            cout << myqueue.size() << '\n';
        } else if(command == "empty"){
            cout << myqueue.empty() << '\n';
        } else if(command == "front"){
            if(myqueue.size() == 0) cout << "-1" << '\n';
            else cout << myqueue.front() << '\n';
        } else if(command == "back"){
            if(myqueue.size() == 0) cout << "-1" << '\n';
            else cout << myqueue.back() << '\n';
        }

    }

    return 0;
    
}