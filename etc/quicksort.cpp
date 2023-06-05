#include <bits/stdc++.h>
using namespace ::std;

void swap(int* a, int* b);
void quicksort(int arr[], int l, int r);
int Partition(int arr[], int l, int r);

int main(){
    int A[10] = {40, 30, 100, 60, 80, 70, 90, 10, 20, 50};

    quicksort(A, 0, 9);

    for(auto i : A){
        cout << i << " ";
    }
}

void swap(int* a, int* b){
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int arr[], int l, int r){
    if(l < r){
        int p = Partition(arr, l, r);

        quicksort(arr, l, p-1);
        quicksort(arr, p+1, r);
    }
}

int Partition(int arr[], int l, int r){
    int i = l -1;
    
    for(int j = l; j <= r-1; j++){
        if(arr[j] <= arr[r]){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[r]);

    return i+1;
}