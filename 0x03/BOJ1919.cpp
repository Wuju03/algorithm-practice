#include <bits/stdc++.h>

int main(){
    char a[1001], b[1001];

    int alphabet[26] = {0};

    int count = 0;

    scanf("%s", a);
    scanf("%s", b);

    for(int i = 0; i < 1000; i++){
        if(a[i] == '\0') break;

        alphabet[a[i] - 'a']++;
    }

    for(int i = 0; i < 1000; i++){
        if(b[i] == '\0') break;
        alphabet[b[i] - 'a']--;
    }

    for(int i = 0; i < 26; i++){
        if(alphabet[i] != 0){
            count += abs(alphabet[i]);
        }
    }

    printf("%d", count);

    return 0;
}