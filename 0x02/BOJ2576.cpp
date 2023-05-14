#include <bits/stdc++.h>
int main(){
    int sum = 0, min = 100, count = 0; // 총합, 최솟값(주어지는 수의 범위는 100미만), 홀수 개수
    int a; // 임시로 값을 입력받는 변수

    for(int i = 0; i < 7; i++){
        scanf("%d", &a);
        
        if(a % 2){ // a를 2로 나눴을때 나머지가 0이 아니면 홀수
            count++; // 홀수를 찾았으니 개수 +1
            sum += a;
            if(a < min) min = a; // 최솟값이 a보다 크면 최솟값은 a
        }
    }

    if(count){
        printf("%d\n%d", sum, min);
    } else {
        printf("-1");
    }

    return 0;

}