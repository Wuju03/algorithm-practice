/*
스택의 크기 = 막대 개수로 두고 풀기

여는 괄호 나오면 일단 push

닫는 괄호 나왔을때
    전 문자가 여는 괄호면 레이저니까 pop + 막대기 절단

    아니면 막대기 끝이니까, 막대기 개수 줄여야하니 pop, 파편 개수 +1 하고 끝

*/
#include <bits/stdc++.h>
using namespace ::std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    stack<char> mystack;
    int count = 0;

    cin >> s;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') mystack.push(s[i]);
        else{
            if(s[i-1] == '('){
                mystack.pop();
                count += mystack.size();
            } else {
                mystack.pop();
                count++;
            }
        }
    }

    cout << count;

    return 0;
}