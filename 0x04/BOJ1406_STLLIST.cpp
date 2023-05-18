#include <bits/stdc++.h>
using namespace std;

int main(){
    char k[100000];
    list<char> stringList;
    list<char>::iterator L = stringList.begin();
    int N;
    char status;

    scanf("%s", &k);

    for(int i = 0; i < 100000; i++){
        if(k[i] == '\0') break;
        stringList.push_back(k[i]);
    }

    L = stringList.end();


    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf(" %c", &status);

        switch (status)
        {
        case 'L':
            if(L != stringList.begin()) L--;
            continue;
        
        case 'D':
            if(L != stringList.end()) L++;
            continue;

        case 'B':
            if(L != stringList.begin()){
                L--; // 가리키는 값의 왼쪽 값을 가리키도록 변경
                L = stringList.erase(L); // 그 값 삭제 후, 다시 오른쪽의 값을 가리킴. 결과적으로 커서의 위치는 그대로지만 커서 왼쪽의 문자 삭제됨
            }
            continue;
        
        case 'P':
            char for_insert;
            scanf(" %c", &for_insert); // 한 개의 문자를 입력 받으려할때, scanf를 이전에 사용해서 버퍼가 남아 있으면 다음 scanf에서 공백 하나 넣어주기

            stringList.insert(L, for_insert);
            continue;
        }
    }

    for(auto i : stringList){
        cout << i;
    }

    return 0;
    

    
}