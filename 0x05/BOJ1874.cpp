#include <bits/stdc++.h>
using namespace ::std;;

/*
집 가서 다시
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    stack<int> mystack;

    cin >> N;

    int num[N];
    int exist[N+1]; // 접근 된적이 없다면 -1, push 되면 1, pop 되면 0으로
    int can = 1; // 가능여부
    fill(exist, exist+N+1, -1);
    char pushorpop[N]; // push는 +니 1, pop은 -니 0

    for(int i = N-1; i >= 0; i--){ // 수열 오름차순으로 저장
        int K;
        cin >> K;

        num[i] = K;
    }

    for(int i = 1, k = 0; i < k; i++){ // i는 스택에 push 할 수, k는 수열 idx
        if(exist[num[k]] == 0){
            printf("NO");
            can = 0;
            break;
        }
        
        if(num[k] > i){
            mystack.push(i);
            pushorpop[i-1] = '+';
            continue;
        }

        if(num[k] < i){
            mystack.pop();
            pushorpop[i-1] = '-';
        }

        if(num[k] == i){
            mystack.pop();
            pushorpop[i-1] = '-';
            k++;
        }
        
    }

    if(can){
        for(int i = 0; i < N; i++){
            printf("%c\n", pushorpop[i]);
        }
    }
}