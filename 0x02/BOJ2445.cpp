/*

5 입력했을때

출력
*        *
**      **
***    *** 상단부분(N-1줄)
****  ****
********** 중간부분(1줄)
****  ****
***    *** 하단부분(N-1줄)
**      **
*        *

*/

#include <bits/stdc++.h>
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N-1; i++){ // 상단 몇 번째 줄인지
        for(int p = 0; p < i+1; p++){ // 상단 좌측 별 출력
            printf("*");
        }

        for(int p = 0; p < 2* (N-(i+1)); p++){ // 상단 중간 공백 출력
            printf(" ");
        }
        
        for(int p = 0; p < i+1; p++){ // 상단 우측 별 출력
            printf("*");
        }

        printf("\n");
    }

    for(int i = 0; i < 2 * N; i++){ // 중단 부분 출력
        printf("*");
    }
    
    printf("\n");

    for(int i = 0; i < N-1; i++){
        for(int p = 0; p < N-(i+1); p++){ // 하단 좌측 별
            printf("*");
        }

        for(int p = 0; p < 2 * (i+1); p++){ // 하단 중간 공백
            printf(" ");
        }

        for(int p = 0; p < N-(i+1); p++){ // 하단 우측 별
            printf("*");
        }

        printf("\n");
    }

    return 0;

}