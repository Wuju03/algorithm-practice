#include <bits/stdc++.h>
void selection_sort(int *arr, int N){ // arr은 배열, N은 배열 원소 개수
    for(int i = 0; i < N-1; i++){
        int min_idx = i;
        int temp;
        int count = 0; // if문이 실행되었는지 여부

        for(int p = i+1; p < N; p++){
            if(arr[p] < arr[min_idx]){
                min_idx = p;
                count++; // if문이 실행(최솟값이 나타났음을 알려주는 표시)
            }
        }

        if(count){ // 최솟값이 발견되었다면 스왑
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

int main(){
    int a[5];
    int average, mid;

    for(int i = 0; i < 5; i++){
        scanf("%d", &a[i]);
    }

    selection_sort(a, 5);

    for(int i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
    
}