/*
https://www.acmicpc.net/problem/5213
*/


#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
#define MAX 250000

using namespace std;

struct point{
    int left;
    int right;
};

int n;
int N;
int lastN = 1;

point arr[MAX];
bool chk[MAX];
int before[MAX];
int dp[4][MAX];

int dx[6] = {0,0,-1,1,0,0};

bool boundTest(int dir, int cx){
    //제외해야하는 값이면 return true
    for(int i=0; i<n/2+1 ;i++){
        if(dp[dir % 2][i] == cx) return true;
    }

    return false;
}

bool allBoundTest(int dir, int cx){
    for(int i=0; i<=n; i++){
        if(dp[dir][i] == cx) return true;
    }

    return false;
}

void fillDp(){
    for(int i=0; i<=n; i++){
        dp[1][i] = (2*i+1)*n-i;
        dp[0][i] = dp[1][i]-(n-1);
        dp[3][i] = n*i - i/2;
        dp[2][i] = dp[3][i]+1;
    }
}

void findNote(){
    queue<int> q;
    chk[1] = true;
    q.push(1);

    while(q.empty()==false){
        int size = q.size();
        while(size--){
            int cx = q.front(); q.pop();

            if(cx>lastN) lastN = cx;
            if(cx == N) return;

            for(int i=0; i<6; i++){
                int nx = cx+dx[i];
                if((i==4 || i==0) && (cx==1 || boundTest(4, cx)==true)) continue;
                if((i==5 || i==1) && boundTest(5, cx)==true) continue;
                if(i==2 && allBoundTest(2, cx) == true) continue;
                if(i==3 && allBoundTest(3, cx) == true) continue;


                if(nx>=1 && nx<=N && chk[nx]==false){
                    if((i % 2 == 0 && arr[cx].left==arr[nx].right) || (i % 2 == 1 && arr[cx].right==arr[nx].left)){
                        before[nx] = cx;
                        chk[nx] = true;
                        q.push(nx);
                    }
                }
            }
        }
    }
}


int main(){
    cin>>n;
    dx[0] = -1*n;
    dx[1] = -1*n+1;
    dx[4] = n-1;
    dx[5] = n;

    N = n*n-n/2;
    fillDp();

    for(int i=1; i<=N; i++){
        cin>>arr[i].left>>arr[i].right;
    }
    
    findNote();

    vector<int> v;

    while(lastN!=0){
        v.push_back(lastN);
        lastN = before[lastN];
    }

    cout<<v.size()<<'\n';
    for(int i=v.size()-1; i>=0 ;i--){
        cout<<v[i]<<' ';
    }
    return 0;
}