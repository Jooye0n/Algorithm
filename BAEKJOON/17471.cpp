/*
https://www.acmicpc.net/problem/17471

2 ≤ N ≤ 10
1 ≤ 구역의 인구 수 ≤ 100
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 987987987
using namespace std;
int n;
int result = MAX;
int number[11];//그룹 별 인원수
bool chk[11];//같은 그룹 표시
bool arr[11][11];//연결 여부
int personNum;
int tempGroup;

int isItSameGroup(int idx){
    //idx와 같은 그룹의 인원수 합 return 
    int tempNumber = number[idx];
    bool chkGroup[11] = {0,0,0,0,0,0,0,0,0,0,0};
    queue<int> q;
    chkGroup[idx] = true;
    q.push(idx);

    while(q.empty() == false){
        int cx = q.front(); q.pop();
        tempGroup--;
        for(int i=1; i<=n; i++){
            if(arr[cx][i] == true && chk[i] == chk[idx] && chkGroup[i] == false){//연결여부 + 같은그룹 + 안본그룹
                chkGroup[i] = true;
                tempNumber+=number[i];
                q.push(i);
            }
        }
    }

    return tempNumber;
}

void makeGroup(int x, int k){
    int idx;//1과 다른 그룹
    if(x == personNum){//그룹 다 고름.
        bool flag = chk[1];
        for(int i=2; i<=n; i++){
            if(chk[i] != flag){
                idx = i;
                break;
            }
        }

        tempGroup = n;
        int num1 = isItSameGroup(idx);
        int num2 = isItSameGroup(1);

        if(tempGroup == 0){
            result = min(result,abs(num1-num2));
        }
    }else{
        for(int i=k; i<=n; i++){
            chk[i] = true;
            makeGroup(x+1,i+1);
            chk[i] = false;
        }
    }
}

int main(){
    cin>>n; 
    for(int i=1; i<=n; i++){
        cin>>number[i];
    }

    for(int i=1; i<=n; i++){
        int tempNum; cin>>tempNum;
        while(tempNum--){
            int temp; cin>>temp;
            arr[i][temp] = true;
            arr[temp][i] = true;
        }
    }

    for(int i=1; i<n; i++){
        personNum = i;
        makeGroup(0,1);
    }

    result == MAX ? cout<<-1 : cout<<result;
    return 0;
}