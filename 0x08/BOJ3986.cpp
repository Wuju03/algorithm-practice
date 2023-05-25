/*
1. 스택이 비어있지 않으면 스택의 탑 부분에 있는 문자와, 현재의 문자를 비교해서 같으면 pop 하고 통과
같지 않다면 push 하고 통과
2. 스택이 비어있다면 push
3. 루프 다 돌고 난 후에, 스택이 비어있지 않다면 올바르지 않은 것
*/

#include <bits/stdc++.h>
using namespace ::std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, count = 0; // 단어의 총 개수와, 그 중 좋은 단어 개수
    string s;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> s; // 각 줄에 주어지는 것이 문장이 아닌 단어이므로 getline 안 써도 됨
        stack<char> AB;

        for(auto c : s){
            if(AB.empty()) AB.push(c);
            else {
                if(AB.top() == c) AB.pop();
                else AB.push(c);
            }
            
        }

        if(AB.empty()) count++;

    }

    cout << count;

    return 0;
}