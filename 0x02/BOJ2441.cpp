/*
입력 5
출력
***** 공백 0개, 별 5개
 **** 공백 1개, 별 4개
  *** 공백 2개, 별 3개
   ** 공백 3개, 별 2개
    * 공백 4개, 별 1개
*/

#include <bits/stdc++.h>
int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){ // i는 몇 번째 줄인지
        for(int p = i; p > 0; p--){ // 공백 출력해주는 for문
            printf(" ");
        }

        for(int p = N-i; p > 0; p--){ // 별 출력해주는 for문
            printf("*");
        }

        printf("\n");

    }

    return 0;

}