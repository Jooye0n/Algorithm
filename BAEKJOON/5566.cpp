/*
https://www.acmicpc.net/problem/5566
(2 ≤ N ≤ 1000, 1 ≤ M ≤ 1000)
*/

#include <cstdio>
#include <iostream>

using namespace std;

int n,m;
int board[1001];//1-1000
int dice[1001];


int cur = 1;//현재 말의 위치
int cnt = 1;//주사위 몇번째인지

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>board[i];
    }
    for(int i=1; i<=m; i++){
        cin>>dice[i];
    }

    while(cur<n){
        int move = dice[cnt];

        if(cur+move>=n) break;
        cur +=move;

        if(cur+board[cur]>=n) break;
        cur +=board[cur];
        
        cnt++;
    }

    cout<<cnt;
    return 0;
}