/*
변수
char a[1000000]; // 단어의 길이는 1000000을 넘지 않으므로
int alphabet[26] = {}; // 알파벳의 개수

순서

1. 문자열 입력 받음
2. for문 작성
    if문
    A. NULL 문자인지 확인하고 맞으면 break, 아니면 진행
    B. (문자열[i] - 'a') >= 0이면 소문자라는 뜻이므로
    alphabet[문자열[i]-'a']++;
    C. 앞의 경우가 다 아니라면 대문자라는 뜻이므로
    alphabet[문자열[i]-'A]++;
*/
#include <bits/stdc++.h>
int main(){
    int max_cnt = 0; // 많이 나온 알파벳이 몇 번 나왔는지
    char max_alphabet = 0; // 최다빈출 알파벳
    char a[1000000]; // 단어 입력받는 문자열
    int alphabet[26] = {}; // 알파벳 등장횟수 저장해두는 배열

    scanf("%s", a);

    for(int i = 0; i < 1000000; i++){
        if(a[i] == '\0') break; // NULL 문자 나오면 문자열의 끝이라는 뜻이므로 탈출

        if(a[i] - 'a' >= 0){ // 소문자라면
            alphabet[a[i] - 'a']++;
        } else { // 대문자라면
            alphabet[a[i] - 'A']++;
        }
    }

    for(int i = 0; i < 26; i++){
        if(alphabet[i] > max_cnt){ // 특정 알파벳 등장횟수가 현재까지의 알파벳 최다 등장횟수보다 많다면
            max_cnt = alphabet[i];
            max_alphabet = i + 'A';
        } else if(max_cnt == alphabet[i]){
            max_alphabet = '?';
        }
    }

    printf("%c", max_alphabet);

    return 0;

}