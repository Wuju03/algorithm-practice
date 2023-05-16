/*
예시

입력
5

출력
*********
 *******
  *****
   ***  여기까지를 상단으로 봄
    *   여기부터 하단으로 봄
   ***
  *****
 *******
*********
*/
#include <bits/stdc++.h>
int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N-1; i++){ // 상단
        for(int p = 0; p < i; p++){ // 공백 출력
            printf(" ");
        }

        for(int p = 0; p < 2*N - (2*i+1); p++){ // 별 출력
            printf("*");
        }

        printf("\n");
    }

    for(int i = 0; i < N; i++){ // 하단
        for(int p = 0; p < N - (i+1); p++){ // 공백 출력
            printf(" ");
        }

        for(int p = 0; p < 2*i + 1; p++){ // 별 출력
            printf("*");
        }

        printf("\n");
    }

    return 0;
   
}