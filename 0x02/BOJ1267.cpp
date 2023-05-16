/*
영식 요금제
30초마다 10원씩 청구

민식 요금제
60초마다 15원씩 청구

통화 시간을 합쳤을때 요금 계산법
K(몫) = 통화시간 / 30초 or 60초라 했을때

1. 통화시간 % 30초 or 60초가 0이라면(딱 떨어진다면)
요금 = (K+1) * (30초 혹은 60초당 요금)

2. 통화시간 % 30초 or 60초가 0이 아니라면(딱 안 떨어진다면)
요금 = (K+1) * (30초 혹은 60초당 요금)
*/

/*
통화 당 요금 청구임
위의 주석 무시
*/
#include <bits/stdc++.h>
int main(){
    int N; // 통화의 개수

    int Y_fee = 0, M_fee = 0;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        int current_time; // K는 통화시간을 임시로 저장해두는 변수
        scanf("%d", &current_time);

        Y_fee += ((current_time / 30) + 1) * 10;
        M_fee += ((current_time / 60) + 1) * 15;
    }

    if(Y_fee == M_fee) printf("Y M %d", Y_fee);
    else if(Y_fee < M_fee) printf("Y %d", Y_fee);
    else printf("M %d", M_fee);

    return 0;
}