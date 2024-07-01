/*
https://www.acmicpc.net/problem/1091
*/

#include <cstdio>
#include <iostream>
#include <memory.h>

using namespace std;
int n;
int P[49];
int S[49];

int card[49] = {0,1,2,3,4,5,6,7,8,9,10,
                11,12,13,14,15,16,17,18,19,20,
                21,22,23,24,25,26,27,28,29,30,
                31,32,33,34,35,36,37,38,39,40,
                41,42,43,44,45,46,47,48
                };//i번째 어떤 카드

int master[49];//i 카드 누구에게

bool testAll(){
    //맨 처음 i번째 위치에 있던 카드(i) 를 최종적으로 플레이어 P[i] 에게 보내야한다.
    for(int i=0; i<n; i++){
        if(P[i] != master[i]) return false;
    }
    return true;
}

void sakeCard(){
    int temp[49];
    for(int i=0; i<n; i++){
        int to = S[i];
        temp[to] = card[i];
    }
    memcpy(card,temp,sizeof(temp));
}

void giveCard(){
    for(int i=0; i<n; i++){
        //맨 처음 i번째 위치에 있던 카드(i)를 최종적으로 플레이어 P[i] 에게 보내야한다.
        master[card[i]] = i % 3;
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>P[i];
    }
    for(int i=0; i<n; i++){
        cin>>S[i];
    }

    int idx = 0;
    giveCard();

    while(testAll() == false){
        sakeCard();
        giveCard();
        idx++;
        if(idx>987987){
            cout<<-1;
            return 0;
        }
    }
    cout<<idx;
    return 0;
}