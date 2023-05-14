/*
a1, a2, a3, a4, ... , an으로 이루어진 수열 존재
서로 다른 양의 정수임
1 <= an <= 1,000,000
자연수 x = ai + aj를 만족하는 (ai, aj)의 쌍의 개수는?

입력
첫째 줄에 수열의 크기 n
둘째 줄에 수열에 포함되는 수
셋째 줄에 x

순서도
int num[1000001] 선언(1~1000000 idx 그대로 사용)
N 입력받음
0~N까지 수열 입력받음
*/

#include <bits/stdc++.h>

int num[2000001] = {}; // idx의 크기를 가진 숫자의 개수

int main(){
    int N; // 수열의 크기
    int x;
    int count = 0; // 쌍의 개수

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        int K;

        scanf("%d", &K);

        num[K]++;
    }

    scanf("%d", &x);

    for(int i = 1; i <= x; i++){
        if(num[i] && num[x-i]){ // num[i]가 존재하고, num[x-i]가 존재하면
            count++;
        }
    }

    count /= 2;

    
    printf("%d", count);

    return 0;
}