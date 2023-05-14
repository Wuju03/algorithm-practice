#include <bits/stdc++.h>
int main(){
    int N;
    int RequireSet = 0;
    int num[9] = {0};
    scanf("%d", &N);

    for(int i = 0; i < 6; i++){
        int current;
        
        if(N <= 0) break;

        current = N % 10;

        if(current == 6 || current == 9){
            num[6]++;
        } else {
            num[current]++;
        }

        N /= 10;
    }

    num[6] = (num[6] / 2) + (num[6] % 2);

    for(int i = 0; i < 9; i++){
        if(num[i] >= RequireSet) RequireSet = num[i];
    }

    printf("%d", RequireSet);


}