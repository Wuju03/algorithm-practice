/*
값 5개 입력 받고 정렬할거임 일단
*/

#include <bits/stdc++.h>
int main(){
    int a[5];
    int sum = 0, average, mid;

    for(int i = 0; i < 5; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    
    for(int i = 0; i < 4; i++){
        int min_idx = i;
        int temp;
        int count = 0; // if문이 실행되었는지 여부

        for(int p = i+1; p < 5; p++){
            if(a[p] < a[min_idx]){
                min_idx = p;
                count++;
            }
        }

        temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }

    mid = a[2];
    average = sum / 5;

    printf("%d\n%d", average, mid);

    return 0;
    
}