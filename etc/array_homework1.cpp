#include <bits/stdc++.h>
int main(){
    int a[100];
    // a배열은 5의 배수와 7의 배수 모두 저장해두는 배열
    int idx_a = 0; // idx_a 변수는 a배열의 끝 idx 정보를 저장해두기 위해서

    for(int i = 0; i < 100; i++){ // 100개의 정수를 생성해야하므로

        int K = rand() % 100;

        if(K == 0) continue; // 만약 생성 된 난수가 0이면 다음 루프

        if(K % 5 == 0 || K % 7 == 0){
            a[idx_a] = K;
            idx_a++;
            // 5의 배수이거나 7의 배수이면 a[idx_a(현재idx)]에 저장하고 idx_a 값 증가
        }
    }

    for(int i = 0; i < idx_a; i++){ // 마지막 idx_a값은 a배열의 마지막 idx값 + 1 된 상태임
        if(a[i] % 5 == 0 && a[i] % 7 == 0) printf("%d ", a[i]); // 5의 배수이고 7의 배수이면 출력
    }

    return 0;

}