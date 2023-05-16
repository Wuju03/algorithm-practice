#include <bits/stdc++.h>
int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){ // i는 몇 번째 줄인지 표기
        for(int p = i+1; p < N; p++){ // 공백 출력 부분
            printf(" ");
        }

        for(int p = 2 * i + 1; p > 0; p--){ // 별 출력 부분
            printf("*");
        }

        printf("\n");

    }

    return 0;

}