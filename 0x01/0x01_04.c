#include <stdio.h>
int func4(int N);
int main(){

}

/*
N이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환하는 함수 func4(int N)
*/
int func4(int N){

    int sum = 1;
    
    while(sum * 2 < N){
        sum *= 2;
    }
    
    return sum;
}