#include <bits/stdc++.h>
using namespace ::std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    while(1){
        string s;
        int no = 0; // 괄호 쌍 불가능 여부 점검하는 변수

        getline(cin, s);

        if(s == ".") break; // 한 줄에 .만 존재할경우 종료

        stack<char> mystack;

        for(auto c : s){
            if(c == '(' || c == '[') mystack.push(c); // 만약에 여는 괄호가 나온다면 push하기

            if(c == ')'){ // 닫는 소괄호가 나온다면
                if(mystack.empty() || mystack.top() != '('){
                    no++;
                    break;
                }

                mystack.pop();
            }

            if(c == ']'){ // 닫는 대괄호가 나온다면
                if(mystack.empty() || mystack.top() != '['){
                    no++;
                    break;
                }

                mystack.pop();
            }
        }

        if(mystack.empty() && !no) cout << "yes\n"; // 스택이 비어있고, 괄호 쌍이 올바르면 yes 출력
        else cout << "no\n"; // 둘 중 하나라도 만족 못 하면 no 출력
    }

    return 0;
}