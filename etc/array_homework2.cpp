#include <bits/stdc++.h>
int main(){
    int status; // 입금, 출금, 종료 구분해주는 변수
    int ammount, account = 100000; // ammount는 입출금 금액, sum은 총금액
    
    do
    {
        // scanf("%d %d", &status, &ammount);
        scanf("%d", &status);
        switch (status)
        {
        case 0:
            scanf("%d", &ammount);
            printf("입금 %d원\n", ammount);
            account += ammount;
            break;
        
        case 1:
            scanf("%d", &ammount);
            printf("출금 %d원\n", ammount);
            account -= ammount;
            break;

        case -1:
            printf("종료\n");
            break;
        }
    } while (status+1); // status가 0, 1일때 진행하고, -1일때 멈춰야하므로
    
    printf("현재 잔액은 : %d원입니다.", account);

    return 0;
}