/*
모든 난쟁이들의 키 총합 sum
sum에서 2명의 키를 빼면 100 됨

int real_fake[9]; // 진짜랑 가짜 난쟁이 키 섞여 있는 배열
int real[7]; // 진짜 난쟁이들의 키만 있는 배열
int fake_pos1, fake_pos2; 선언
*/

#include <bits/stdc++.h>

void selection_sort(int *arr, int N){ // arr은 배열, N은 배열 원소 개수
    for(int i = 0; i < N-1; i++){
        int min_idx = i;
        int temp;
        int count = 0; // if문이 실행되었는지 여부

        for(int p = i+1; p < N; p++){
            if(arr[p] < arr[min_idx]){
                min_idx = p;
                count++; // if문이 실행(최솟값이 나타났음을 알려주는 표시)
            }
        }

        if(count){ // 최솟값이 발견되었다면 스왑
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

int main(){
    int sum = 0; // 9명의 모든 난쟁이들의 키 합
    int real_fake[9]; // 진짜와 가짜 난쟁이들 모두 섞여있는 키 배열
    int real[7]; // 진짜 난쟁이들만의 키 배열
    int fake_pos1, fake_pos2; // real_fake 배열에서 가짜들의 index

    for(int i = 0; i < 9; i++){
        scanf("%d", &real_fake[i]);

        sum += real_fake[i];
    }

    for(int i = 0; i < 8; i++){
        for(int p = 1; p < 9; p++){
            if(sum - (real_fake[i] + real_fake[p]) == 100){ // 가짜 위치 판별
                fake_pos1 = i;
                fake_pos2 = p;
                break;
            }
        }
    }

    for(int i = 0, k = 0; i < 9; i++){
        if(i == fake_pos1 || i == fake_pos2) continue; // 만약 가짜위치면 다음 루프로

        real[k] = real_fake[i]; // 가짜와 진짜가 섞여있는 배열에서 진짜들만 솎아내기
        k++; // 진짜 배열 index + 1
    }

    selection_sort(real, 7); // 진짜들 배열 오름차순으로 선택정렬

    for(int i = 0; i < 7; i++){ // 오름차순으로 출력
        printf("%d\n", real[i]);
    }

    return 0;

}