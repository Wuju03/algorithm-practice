#include <bits/stdc++.h>
int func2(int arr[], int N){
    int exist_num[101] = {0}; // 현재 배열 내에 있는 숫자 0~100까지의 존재 개수 / 0의 개수도 세야하기에 idx값 그대로 사용해도 됨

    for(int i = 0; i < N; i++){
        exist_num[arr[i]]++; // arr[i]는 배열 원소의 값
    }

    for(int i = 0; i < N; i++){
        if(exist_num[100-arr[i]]){ // (100-배열 원소의 값)의 원소가 1이상이면
            return 1;
        }
    }
    
    return 0;
}

int main(){

}