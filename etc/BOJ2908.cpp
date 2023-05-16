/*
숫자는 3자리임
상수는 숫자를 거꾸로 읽음
그런 후 큰 숫자를 출력함
*/

#include <bits/stdc++.h>
int main(){
    int a, b;
    int a_reverse, b_reverse;

    scanf("%d %d", &a, &b);
    
    a_reverse = ((a % 10) * 100) + (((a / 10) % 10) * 10) + (a / 100);

    b_reverse = ((b % 10) * 100) + (((b / 10) % 10) * 10) + (b / 100);

    if(a_reverse > b_reverse) printf("%d", a_reverse);
    else printf("%d", b_reverse);

    return 0;
}