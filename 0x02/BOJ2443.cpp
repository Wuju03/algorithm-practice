#include <bits/stdc++.h>
int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){ // 몇 번째 줄?
        for(int p = i; p > 0; p--){
            printf(" ");
        }

        for(int p = 2 * N - (2 * i + 1); p > 0; p--){ // 2N - 1, 2N - 3, 2N - 5....
            printf("*");
        }

        printf("\n");
    }

    return 0;

}