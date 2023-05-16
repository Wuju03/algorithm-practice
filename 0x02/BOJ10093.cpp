/*
두 양의 정수가 주어졌을 때, 두 수 사이에 있는 정수를 모두 출력하라

예시입력
8 14

예시출력
5
9 10 11 12 13

서브태스크
1번 30점 1 <= A, B <= 1000
2번 70점 1 <= A, B <= 10^15, 차이는 최대 100,000

서브태스크 2번을 만족하기 위해서 long long형을 써야함
*/
#include <bits/stdc++.h>
int main(){
    long long A, B, C, min;

    scanf("%lld %lld", &A, &B);
    
    if(A<B){
        C = B-A-1;
        min = A;
    } else if (A>B){
        C = A-B-1;
        min = B;
    } else {
        C = 0;
    }

    printf("%lld\n", C);

    for(long long i = 0; i < C; i++){
        if(A==B) break;
        printf("%lld ", min+i+1);
    }
    
    return 0;

}