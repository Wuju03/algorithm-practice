#include <bits/stdc++.h>
int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        int a;
        char S[21];

        scanf("%d %s", &a, S);

        for(int p = 0; p < 21; p++){ // p는 문자열 idx
            if(S[p] == '\0') break; // NULL 문자 발견시 탈출
            
            for(int k = 0; k < a; k++){ // 각 문자 반복횟수만큼
                printf("%c", S[p]);
            }
        }
        
        printf("\n");
    }
    
    return 0;

}