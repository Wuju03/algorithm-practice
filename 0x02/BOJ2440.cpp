#include <bits/stdc++.h>
int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){ // i는 몇 번째 줄인지
        for(int p = N-i; p > 0; p--){ // p는 별의 개수가 몇 개인지
            printf("*");
        }
        
        printf("\n");

    }

    return 0;

}