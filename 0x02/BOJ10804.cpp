#include <bits/stdc++.h>
int main(){
    int card[20];
    for(int i = 0; i < 20; i++){
        card[i] = i+1; // 0~19인덱스에 1~20번 카드 저장
    }

    for(int i = 0; i < 10; i++){
        int a, b;

        scanf("%d %d", &a, &b);

        int size = b - a + 1; // tmp_reverse 배열 크기

        if(size == 0) continue; // size가 0이면 다음 루프 진행

        int tmp_reverse[size]; // 역방향으로 저장해두는 배열
        
        for(int i = size - 1, k = a-1; i >= 0; i--, k++){
            tmp_reverse[i] = card[k];
        }

        for(int i = 0, k = a-1; i < size; i++, k++){
            card[k] = tmp_reverse[i];
        }
    }

    for(int i = 0; i < 20; i++){
        printf("%d ", card[i]);
    }

    return 0;

}