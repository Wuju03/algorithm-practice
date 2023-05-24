/*
예제 입력
4 // 케이스 총 개수
RDD // 1번 케이스 명령어
4 // 1번 케이스 배열 크기
[1,2,3,4] // 1번 케이스 배열
DD
1
[42]
RRD
6
[1,1,2,3,5,8]
D
0
[]
*/
#include <bits/stdc++.h>
using namespace ::std;

/*
cout_result가 제대로 동작하지 않음 고쳐야됨
*/
void cout_result(deque<int>& d){
    int k = d.size(); // 최초의 덱 사이즈를 저장
    cout << '[';

    if(k >= 2){
        for(int i = 0; i < k - 1; i++){ // 사이즈가 3일때, d1,d2,d3 (d1,d2,) 출력 후 for문 밖에서 d3 출력해주면 됨
            cout << d.front() << ',';
            d.pop_front();
        }
    }

    cout << d.front() << ']' << '\n';

}

void parse(string& s, deque<int>& d){
    int num = 0;

    for(int i = 1; i+1 < s.size(); i++){ // 마지막 괄호의 위치가 s.size() - 1(null문자 고려해야하므로)이니까 미만일때까지 반복
        if(s[i] == ','){
            d.push_back(num);
            num = 0;
        } else {
            num = 10 * num + (s[i] - '0'); // 만약 콤마를 만나지 않았다면, 일의 자리만 가지고 있는 숫자가 아니므로, 그 수를 10 곱해주고, 현재 자리의 숫자 더해줌
        }
    }

    if(num != 0) d.push_back(num); // num이 0이라면 콤마를 만나서 pushback 이후 초기화 된 것이므로 무시하면 되지만, 아니라면 숫자가 존재하는것이므로 삽입

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int T;

    cin >> T;

    for(int i = 0; i < T; i++){
        string command, array;
        int array_size, rev = 0, error = 0;
        deque<int> mydeque;

        cin >> command;
        cin >> array_size;
        cin >> array;

        parse(array, mydeque);

        for(char c : command){

            if(c == 'R') rev = 1 - rev; // R명령(뒤집기 명령)
            else { // D명령(앞 쪽 원소 삭제 명령어)
                if(mydeque.empty()){ // 덱의 사이즈가 0이면 삭제할 원소가 없으므로 에러
                    cout << "error\n";
                    error++;
                    break;
                }

                if(rev) mydeque.pop_back(); // 반대로 되어있을 경우, 덱의 뒤쪽 원소가 앞의 원소임
                else mydeque.pop_front(); // 반대가 아닐 경우
            }
        }

        if(rev){
            reverse(mydeque.begin(), mydeque.end());
        }

        if(mydeque.empty()){
            if(!error) cout << "[]\n";
        }
        else cout_result(mydeque);

    }

    return 0;

}