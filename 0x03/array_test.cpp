#include <bits/stdc++.h>
using namespace std;

void insert(int idx, int num, int arr[], int& len){
  for(int i = len; i > idx; i--){ // (len-1)이 배열의 마지막 index값, 거기서부터 1씩 감소해나가면서 요소들을 뒷 번호로 하나씩 미룸
    arr[i] = arr[i-1];

  }

  arr[idx] = num;
  
  len++; // len의 값은 참조자로 받았기에 증가시키면 insdert_test에서도 늘어남 / 베열 요소의 개수 증가했으니 len 증가


}

void erase(int idx, int arr[], int& len){
  for(int i = idx; i < len; i++){
    arr[i] = arr[i+1];  
  }

  len--;
}

void printArr(int arr[], int& len){
  for(int i = 0; i < len; i++) cout << arr[i] << ' ';
  cout << "\n\n";
}

void insert_test(){
  cout << "***** insert_test *****\n";
  int arr[10] = {10, 20, 30};
  int len = 3;
  insert(3, 40, arr, len); // 10 20 30 40
  printArr(arr, len);
  insert(1, 50, arr, len); // 10 50 20 30 40
  printArr(arr, len);
  insert(0, 15, arr, len); // 15 10 50 20 30 40
  printArr(arr, len);
}

void erase_test(){
  cout << "***** erase_test *****\n";
  int arr[10] = {10, 50, 40, 30, 70, 20};
  int len = 6;
  erase(4, arr, len); // 10 50 40 30 20
  printArr(arr, len);
  erase(1, arr, len); // 10 40 30 20
  printArr(arr, len);
  erase(3, arr, len); // 10 40 30
  printArr(arr, len);
}

int main(void) {
  insert_test();
  erase_test();
}
