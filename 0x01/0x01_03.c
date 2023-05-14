#include <stdio.h>
int func3(int N);
int main(){

}

/*
N이 제곱수면 1을 반환, 제곱수가 아니면 0을 반환
*/
int func3(int N){
    for(int i = 1; i * i <= N; i++){
        if(i * i == N){ // i곱하기 i == N이면 제곱수
            return 1;
        }
        return 0;
    }
}