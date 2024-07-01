/*
https://www.acmicpc.net/problem/16637
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int n;
int numOfFirst;//괄호의 개수
vector<int> number;
vector<char> oper;
bool operChk[12];//true인 부분이 괄호 넣을 부분
long long maxNum = -987987987987;

long long calculSimple(long long x,long long y,char op){
    switch(op){
        case '+': return x+y;
        case '-': return x-y;
        case '*': return x*y;
    }
}

void calculate(){
    //전체 식 계산한 후 maxNum update
    int Idx = 1;
    long long tempMaxNum = number[0];//첫번째 num이자 최종 결과값
    char curOper = oper[0];//현재 oper

    //3+ 8* 7- 9* 2+ 3
    while(Idx<number.size()){
        if(operChk[Idx] == true){//괄호면,
            int t1 = number[Idx];
            char nextOper = oper[Idx];
            int t2 = number[++Idx];
            tempMaxNum = calculSimple(tempMaxNum,calculSimple(t1,t2,nextOper),curOper);
        }else{
            tempMaxNum = calculSimple(tempMaxNum,number[Idx],curOper);
        }
        curOper = oper[Idx++];
    }
    maxNum = max(maxNum,tempMaxNum);
}

void choice(int x, int k){
    //괄호가 될 부분에 operChk == true 한다.
    if(x == numOfFirst){
        calculate();
    }else{
        for(int i=k; i<oper.size(); i++){
            operChk[i] = true;
            choice(x+1,i+2);
            operChk[i] = false;
        }
    }
}

int main(){
    cin>>n;
    if(n == 1){
        cin>>n; cout<<n;
        return 0;
    }
    
    for(int i=0; i<n; i++){
        int tempN;
        char tempO;

        if(i % 2 == 0){
            cin>>tempN;
            number.push_back(tempN);
        }else{
            cin>>tempO;
            oper.push_back(tempO);
        }
    }

    for(int i=0; i<=oper.size()/2; i++){
        numOfFirst = i;
        choice(0,0);
    }

    cout<<maxNum;
    return 0;
}