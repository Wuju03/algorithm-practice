/*
길이 N인 int 배열 arr에서, 합이 100인 서로 다른 위치의 두 원소가 존재하면 1, 없으면 0을 반환하라
반환해주는 함수는 func2(int arr[], int N)이다
arr의 각 수는 0이상 100이하이고, N은 1000이하이다
*/
#include <stdio.h>
void func2(int arr[], int N);
int main(){

}

void func2(int arr[], int N){
    for(int i = 0; i < N; i++){
        for(int p = i+1; p < N; p++){
            if(arr[i] + arr[p] == 100){
                return 1;
            }
        }
    }
    
    return 0;
}