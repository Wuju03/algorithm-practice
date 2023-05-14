#include <bits/stdc++.h>

int main(){
    int N;
    scanf("%d", &N);

    char a[1000], b[1000];

    for(int i = 0; i < N; i++){
        int count = 0;
        int alphabet[26] = {};
        

        scanf("%s %s", a, b);

        for(int p = 0; p < 1000; p++){ // 첫번째 문자열 구성요소 개수 확인
            if(a[p] == '\0') break; // null 문자 발견하면 break

            alphabet[a[p] - 'a']++;
        }

        for(int p = 0; p < 1000; p++){ // 두번째 문자열 구성요소 개수 확인
            if(b[p] == '\0') break; // null 문자 발견하면 break

            alphabet[b[p] - 'a']--;
        }

       for(int k = 0; k < 26; k++){
            if(alphabet[k] != 0){ // alphabet[k]의 값이 0이 아니면 둘의 구성요소가 다르다는 뜻이니 불가능
                printf("Impossible\n");
                count++;
                break;
            }
        }

        if(count == 0){
            printf("Possible\n");
        }

    }

    return 0;

}