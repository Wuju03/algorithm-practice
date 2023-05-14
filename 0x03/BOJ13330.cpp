#include <bits/stdc++.h>
int main(){
    int N, K; // 학생 수 / 방에 들어갈 수 있는 최대 인원
    int student[6][2] = {}; // [학년][성별] (증감연산자를 사용하므로, 모든 원소의 값을 0으로 초기화)
    int require_room = 0; // 필요한 방의 개수

    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++){
        int grade, gender;
        scanf("%d %d", &gender, &grade); // 성별 학년 순으로 입력됨

        student[grade-1][gender]++; // 1~6학년이 idx에서는 0~5이기에 -1해줘야함
    }

    for(int i = 0; i < 6; i++){ // i는 학년
        for(int p = 0; p < 2; p++){ // p는 성별
            require_room += student[i][p] / K;

            if(student[i][p] % K != 0) require_room++; // 딱 맞아 안 떨어지면, 1개의 방이 더 필요함
        }
    }

    printf("%d", require_room);

    return 0;

}