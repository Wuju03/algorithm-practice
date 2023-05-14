/*
배는 0
등은 1

배 1개 = > 도(A)
배 2개 = > 개(B)
배 3개 = > 걸(C)
배 4개 = > 윷(D)
배 0개 = > 모(E)
*/
#include <bits/stdc++.h>

int main(){
    for(int i = 0; i < 3; i++){
        int N = 0, count = 0;
        for(int i = 0; i < 4; i++){
            scanf("%d", &N);
            if(N == 0) count++;
        }

        switch (count)
        {
        case 1:
            printf("A\n");
            break;
        case 2:
            printf("B\n");
            break;
        case 3:
            printf("C\n");
            break;
        case 4:
            printf("D\n");
            break;
        case 0:
            printf("E\n");

        }
    }

    return 0;

}