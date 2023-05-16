/*
변수
char S[100]; // 단어의 길이는 100을 넘지 않으므로 NULL 고려해서 100 선언
int alphabet[26]; // 단어가 처음 등장하는 위치를 기록하는 배열

1. alphabet 배열 모든 원소 -1로 fill 함수 이용해서 초기화
2. 단어 입력받기
3. for
    A. S[i] == '\0' 일 경우 break;
    B. alphabet[S[i] - 'a'] == -1 일 경우, alphabet[S[i] - 'a'] = i;
4. for
    A. alphabet[i]를 공백으로 구분해서 26개의 원소 모두 출력함
5. 종료
*/

#include <bits/stdc++.h>
int main(){
    char S[100];
    int alphabet[26] = {-1};

    std::fill(alphabet, alphabet + 26, -1); // algorithm 헤더에 있는 fill 함수, 첫 두 파라미터는 포인터 주소 넣어야함

    scanf("%s", S);

    
    for(int i = 0; i < 100; i++){
        if(S[i] == '\0') break; // 만약 NULL 문자 발견시 break;

        if(alphabet[S[i] - 'a'] == -1) alphabet[S[i] - 'a'] = i;
    }
    

    for(int i = 0; i < 26; i++){
        printf("%d ", alphabet[i]);
    }

    return 0;
}