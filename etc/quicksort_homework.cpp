#include <bits/stdc++.h>
using namespace ::std;

void quicksort(struct Sungjuk* sj, int l, int r); // 내림차순으로 정렬해주는 퀵소트 (구조체인자, 좌측 idx, 우측 idx)
int partition(struct Sungjuk* sj, int l, int r);
// void reverse(struct Sungjuk* sj, int start, int end, int ammount); // 구조체 배열 sj의 순서를 역으로 돌려주는 함수(사용 안 함)

struct Sungjuk // 성적 저장하는 구조체 선언
    {
        char hakbun[11]; // 학번
        int korean; // 국어 점수
        int english; // 영어 점수
        int math; // 수학 점수
    };

int main(){
    Sungjuk sj[10] = { {"2023216026", 100, 100, 100}, {"2023216239", 80, 93, 78}, {"2023216357", 70, 80, 84}, {"2023216232", 65, 28, 72}, {"2023216854", 90, 85, 83}, {"2023216952", 83, 72, 94}, {"2023216651", 82, 84, 85}, {"2023216942", 91, 94, 63}, {"2023216254", 69, 53, 84}, {"2023216992", 96, 94, 92} }; // 구조체 배열 선언
    
    quicksort(sj, 0, 10); // 퀵소트 함수 시작
    // reverse(sj, 0, 9, 10); (사용 안 함)

    cout << "아래 기능 중 한 가지를 선택 해주세요" << "\n" << "(1) 전체 정렬된 데이터 보기 " << "(2) 검색하기" << '\n';

    int n;

    cin >> n;

    switch (n)
    {
    case 1:

        for(int i = 0; i < 10; i++){
            cout << "학번 : " << sj[i].hakbun << '\n';
            cout << "국어 : " << sj[i].korean << " 수학 : " << sj[i].math << " 영어 : " << sj[i].english << '\n' << '\n';
        }
        
        break;
    
    case 2:
        char target[11]; // 검색할 학번을 입력 받는 변수
        int found = 0;

        cout << "찾으시는 학생의 학번을 입력해주세요 : ";

        cin >> target;

        for(int i = 0; i < 10; i++){
            if(strcmp(sj[i].hakbun, target) == 0){ // 인티저형일때 sj[i].hakbun == target
                cout << "국어 : " << sj[i].korean << " 수학 : " << sj[i].math << " 영어 : " << sj[i].english;
                found++;
                break;
            }
        }

        if(!found) cout << "찾을 수 없는 학번입니다."; // found가 증가 된적이 없다면, 못 찾았다는 뜻이므로 오류 메시지 출력

        break;
    }
     
    
}

void quicksort(struct Sungjuk* sj, int l, int r){
    if(l < r){
        int p = partition(sj, l, r);

        quicksort(sj, l, p-1);
        quicksort(sj, p+1, r);
    }

}

int partition(struct Sungjuk* sj, int l, int r){
    int i = l - 1;

    for(int j = l; j <= r-1; j++){
        if(strcmp(sj[j].hakbun, sj[r].hakbun) >= 0){ // 인티저형일때 sj[j].hakbun <= sj[r].hakbun
            i++;
            swap(sj[i], sj[j]); // STL 함수(두 변수의 값을 상호교환 해주는 함수)
        }
    }

    swap(sj[i+1], sj[r]);

    return i+1;

}

/*
void reverse(struct Sungjuk* sj, int start, int end, int ammount){
    for(int i = 0; i < ammount/2; i++){
        swap(sj[start++], sj[end--]);
    }

}
*/