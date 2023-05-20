#include <bits/stdc++.h>
using namespace ::std;

const int MX = 100005;
int dat[MX];
int pos = 0;

void push(int x){ // x 값을 스택에 저장
    dat[pos] = x;
    pos++;
}

void pop(){ // 상단의 원소 제거
    pos--;
    // dat[pos] = 0; 어차피 나중에 덮어쓰기 당하니 수정하는건 낭비
}

int top(){ // 상단의 값 불러오기
    return dat[pos-1];
}

int main(){
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
            push(x);
        } else if(command == "pop"){
            if(pos == 0) printf("-1\n"); // 만약 스택에 저장되어 있는 정수가 없다면
            else{
                printf("%d\n", top());
                pop();
                 // 스택에 저장 되어있는 정수 삭제와 동시에 그 수 출력
            }
        } else if(command == "size"){
            printf("%d\n", pos); // pos 값이 곧 스택에 들어있는 정수의 개수
        } else if(command == "empty"){
            if(pos) printf("0\n"); // 스택이 비어있지 않다면
            else printf("1\n");
        } else if(command == "top"){
            if(!pos) printf("-1\n"); // pos 값이 0이라면(!pos이므로 0일때 true) -1 출력
            else printf("%d\n", top());
        }
    }

    return 0;
}