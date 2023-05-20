#include <bits/stdc++.h>
using namespace ::std;

int main(){
    stack<int> mystack;
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        string command;
        int x;

        cin >> command;

        if(command == "push"){
            cin >> x;
            mystack.push(x);
        } else if(command == "pop"){
            if(mystack.size() == 0) printf("-1\n"); // 만약 스택에 저장되어 있는 정수가 없다면
            else{
                printf("%d\n", mystack.top());
                mystack.pop();
                 // 스택에 저장 되어있는 정수 삭제와 동시에 그 수 출력
            }
        } else if(command == "size"){
            printf("%d\n", mystack.size()); // pos 값이 곧 스택에 들어있는 정수의 개수
        } else if(command == "empty"){
            if(mystack.size()) printf("0\n"); // 스택이 비어있지 않다면
            else printf("1\n");
        } else if(command == "top"){
            if(!mystack.size()) printf("-1\n"); // pos 값이 0이라면(!pos이므로 0일때 true) -1 출력
            else printf("%d\n", mystack.top());
        }
    }

    return 0;

}