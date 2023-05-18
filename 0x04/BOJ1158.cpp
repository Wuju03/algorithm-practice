#include <bits/stdc++.h>
using namespace std;

/*
리스트.end()의 값은 마지막 원소의 주소를 나타내는것이 아님(마지막 원소 + 1의 위치값임)
*/

int main(){
    list<int> lineup;
    int N, K;

    scanf("%d %d", &N, &K);

    int yosepus[N]; // 요세푸스 순열 선언

    for(int i = 0; i < N; i++){ // lineup 리스트 채움
        lineup.push_back(i+1);
    }

    list<int>::iterator cursor = lineup.begin();

    for(int i = 0; i < N-1; i++){
        for(int p = 0; p < K-1; p++){ // 현재 가리키고 있는 원소를 포함하여 수를 세야 하므로, (K-1)번 반복임
            if(cursor == --lineup.end()){ // 만약 커서가 lineup 리스트의 마지막 원소를 가리키고 있다면, 첫 원소를 가리키도록 변경
                cursor = lineup.begin();
            } else cursor++; // 아니라면 다음 원소가 존재하기에 커서++ 실행
        }

        yosepus[i] = *cursor; // 커서가 가리키는 곳의 원소를 요세푸스 순열에 저장

        if(cursor != --lineup.end()) cursor = lineup.erase(cursor); // 다음 원소가 존재한다면(마지막 원소가 아니라면), 원소 제거 후 커서 1 증가
        else{ // 커서가 가리킨 위치가 마지막 원소의 위치라면
            lineup.erase(cursor); // 커서가 가리키는 위치의 원소 제거
            cursor = lineup.begin(); // 커서를 1 증가 시켰을때 첫 원소를 가리켜야함
        }

    }

    yosepus[N-1] = *cursor; // 마지막에 커서가 가리킨 원소가 결국 요세푸스 순열의 마지막 원소이므로 저장

    printf("<");

    for(int i = 0; i < N-1; i++){
        printf("%d, ", yosepus[i]);
    }

    printf("%d>", yosepus[N-1]);

    return 0;

    
}