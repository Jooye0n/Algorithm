/*
[제약사항]

N은 10이상 1,000이하의 정수이다. (10 ≤ N ≤ 1,000)

[입력]

입력으로 정수 N 이 주어진다.


[출력]

1 ~ N까지의 숫자를 게임 규칙에 맞게 출력한다.

입력
10
input.txt
출력
1 2 - 4 5 - 7 8 - 10
10 11 ... 30 31 32 33 34 35 36 ... 999 1000

*/

#include <cstdio>
#include <iostream>

using namespace std;

int main(){

    int n;
    bool chk = false;
    cin>>n;
    for(int i=1; i<=n; i++){
        
        if(i/100 == 3 || i/100 == 6 || i/100 ==9){
            cout<<'-';
            chk = true;
        }
        int temp = i - i/100*100;
        if(temp/10 == 3 || temp/10 == 6 || temp/10 ==9){
            cout<<'-';
            chk = true;
        }
        if(i%10 == 3 || i%10 == 6 || i%10 ==9){
            cout<<'-';
            chk = true;
        }

        if(chk == false){
            cout<<i;
        }else{
            chk = false;
        }

        cout<<' ';
    }
    return 0;
}