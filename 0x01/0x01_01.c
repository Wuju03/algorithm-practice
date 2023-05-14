#include <stdio.h>
int func1(int N);
int main(){
    int N;
    scanf("%d", &N);

    int result = func1(N);
    printf("func1(%d) = %d", N, result);

    return 0;
    
}

int func1(int N){
    int sum = 0;
    
    for(int i = 1; i <= N; i++){
        if(i % 3 == 0 || i % 5 == 0){
            sum += i;
        }        
    }

    return sum;
}