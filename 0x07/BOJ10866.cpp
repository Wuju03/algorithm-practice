/*
정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여덟 가지이다.

push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/
#include <bits/stdc++.h>
using namespace ::std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    deque<int> mydeque;

    cin >> N;

    for(int i = 0; i < N; i++){
        string command;

        cin >> command;

        if(command == "push_front"){
            int x;
            cin >> x;

            mydeque.push_front(x);
        } else if(command == "push_back"){
            int x;
            cin >> x;

            mydeque.push_back(x);
        } else if(command == "pop_front"){
            if(mydeque.size() == 0) cout << "-1" << '\n';
            else{
                cout << mydeque.front() << '\n'; // 앞쪽에 존재하는 수 출력 후
                mydeque.pop_front(); // 그 수 제거
            }
        } else if(command == "pop_back"){
            if(mydeque.size() == 0) cout << "-1" << '\n';
            else{
                cout << mydeque.back() << '\n'; // 앞쪽에 존재하는 수 출력 후
                mydeque.pop_back(); // 그 수 제거
            }
        } else if(command == "size"){
            cout << mydeque.size() << '\n';
        } else if(command == "empty"){
            cout << (int)mydeque.empty() << '\n';
        } else if(command == "front"){
            if(mydeque.size() == 0) cout << "-1" << '\n';
            else cout << mydeque.front() << '\n';
        } else if(command == "back"){
            if(mydeque.size() == 0) cout << "-1" << '\n';
            else cout << mydeque.back() << '\n';
        }
        
    }

    return 0;
    
}