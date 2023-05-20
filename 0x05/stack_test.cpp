#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0; // 최상단 원소 + 1 위치 값

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

void test(){
  push(5); push(4); push(3);
  cout << top() << '\n'; // 3
  pop(); pop();
  cout << top() << '\n'; // 5
  push(10); push(12);
  cout << top() << '\n'; // 12
  pop();
  cout << top() << '\n'; // 10
}

int main(void) {
	test();
}