/*
순서
1. 케이스 개수 N 입력 받음
2. for문으로 N개의 케이스 입력 받음
    NULL문자면 탈출해서, 다음케이스로 진행
    O가 나오면 streak 1 증가 시킨후, sum과 더 함
    X가 나오면 streak 0으로 만듬
    현재 케이스의 총 점수 출력
3. 종료
*/
#include <bits/stdc++.h>
int main(){
    char str[80]; // 80보다 작은 문자열이라 했으므로 NULL 고려해서 80
    int N; // 케이스 개수

    scanf("%d", &N); // 케이스 개수 입력

    for(int i = 0; i < N; i++){
        scanf("%s", str);

        int sum = 0, streak = 0; // 총점수, 연속정답 횟수

        for(int p = 0; p < 81; p++){
            if(str[p] == '\0') break; // NULL문자 나오면 탈출

            if(str[p] == 'O'){ // 정답
                streak++;
                sum += streak;
            } else streak = 0; // 오답
        }

        printf("%d\n", sum); // 케이스 총점수 출력

    }

    return 0;

}