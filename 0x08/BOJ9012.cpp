/*
1. 스택 생성
2. 여는 괄호 나오면 무조건 push
3. 닫는 괄호 나왔을때,
    만약에 비이있거나 top 부분과 다르면 불가능하므로 불가능 출력후 break;
    같은 종류의 여는 괄호면 pop 후 진행
*/
#include <bits/stdc++.h>
using namespace ::std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N;

    cin >> N;

    for(int i = 0; i < N; i++){
        string s;
        stack<char> mystack;
        int NO = 0;

        cin >> s; // 공백 없는 문장이므로 getline 안 써도 됨

        for(auto c : s){
            if(c == '(') mystack.push(c);

            if(c == ')'){
                if(mystack.empty()){
                    NO++;
                    break;
                }
                
                mystack.pop();
            }

        }

        if(!NO && mystack.empty()) cout << "YES\n"; // 스택이 비어있고, 불가능하다는 표시가 없으면 올바른것
        else cout << "NO\n"; // 아니라면 불가능하다고 출력

    }

    return 0;
    
}