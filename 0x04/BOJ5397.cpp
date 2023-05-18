#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        list<char> password;
        list<char>::iterator cursor = password.end();
        char input[1000001];

        scanf("%s", input);

        for(int p = 0; p < 1000001; p++){
            if(input[p] == '\0') break;
            
            if(input[p] == '<'){
                if(cursor != password.begin()) cursor--;
            } else if(input[p] == '>'){
                if(cursor != password.end()) cursor++;
            } else if(input[p] == '-'){
                if(cursor != password.begin()){
                    cursor--;
                    cursor = password.erase(cursor);
                }
            } else password.insert(cursor, input[p]);
        }

        for(auto i : password) cout << i;

        printf("\n");
    }

    return 0;

}