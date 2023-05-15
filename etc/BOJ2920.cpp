#include <bits/stdc++.h>
int main(){
    int K[8];
    int asc = 0, des = 0, mixed = 0; // 상태 확인하는 변수

    scanf("%d", &K[0]);

    if(K[0] == 1){ // 첫번째가 1일때
        for(int i = 1; i < 8; i++){
            scanf("%d", &K[i]);

            if(K[i] != K[i-1] + 1){
                mixed++;
                break;
            } // ascending 방식이 아니면 break;
        }
        asc++;
    } else if(K[0] == 8){
        for(int i = 1; i < 8; i++){
            scanf("%d", &K[i]);

            if(K[i] != K[i-1] - 1){
                mixed++;
                break;
            } // descending 방식이 아니면 break;
        }
        des++;
    } else mixed++; // 다른 모든 경우가 아니면 무조건 mixed
    
    if(mixed) printf("mixed");
    else if(des) printf("descending");
    else if(asc) printf("ascending");

    return 0;
    
}