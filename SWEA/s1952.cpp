/*
수영장

10 40 100 300   
0 0 2 9 1 5 0 0 0 0 0 0


하루랑 1달이랑 3달의 조화



// 첫 번째 테스트 케이스, 이용권 가격들
// 12개월 이용 계획
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int month[13];
int pay[5];//1일:1 1달:2 3달:3 1년:4
int T;
int result[15];
int minPay;

void DFS(int x){
    if(x > 12){
        int total = 0;
        for(int i=1; i<=12; i++){
            if(result[i] == 1){
                total+=pay[result[i]]*month[i];
            }else{
                total+=pay[result[i]];
            }
        }

        if(total<minPay) minPay = total;
        
    }else{
        result[x] = 1;
        DFS(x+1);
        
        result[x] = 2;
        DFS(x+1);

        result[x] = 3;
        result[x+1] = 0;
        result[x+2] = 0;
        DFS(x+3);
    }
}

int main(){
    cin>>T;
    for(int t=1; t<=T; t++){
        for(int i=1; i<=4; i++){
            cin>>pay[i];
        }
        minPay = pay[4];
        for(int i=1; i<=12; i++){
            cin>>month[i];
        }

        DFS(1);

        printf("#%d %d\n",t,minPay);
    }

    return 0;
}