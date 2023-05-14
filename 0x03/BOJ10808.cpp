/*
알파벳 소문자로만 이루어진 단어 S 주어짐(단어 길이는 100을 넘지 않음)
이 곳에 포함되어 있는 알파벳의 개수를 센 후
a의 개수, b의 개수, ... , z의 개수 식으로 공백을 사이에 두고 출력

변수
char S[101]; // 단어 S
int alphabet_num[26] = {0}; // 알파벳 개수 저장해두는 배열(개수는 초기값 0으로 초기화)

해결법
1. 단어 S를 문자열 S에 입력받음
2. for문으로 S[0]부터 '\0'(널) 문자 나올때까지 순회
    alphabet_num[S[i] - 97]++; (소문자 아스키코드는 97~122)
    null 문자 발견하면 탈출
3. for문으로 alphabet_num 출력함
*/
#include <stdio.h>
int main(){
    char S[101];
    int alphabet_num[26] = {0};

    scanf("%s", S);

    for(int i = 0; i < 101; i++){
        if(S[i] == '\0'){ // 문자열의 끝은 NULL이기에 발견하면 탈출
            break;
        }

        alphabet_num[S[i] - 97]++;
    }

    for(int i = 0; i < 26; i++){
        printf("%d ", alphabet_num[i]);
    }

    return 0;
}