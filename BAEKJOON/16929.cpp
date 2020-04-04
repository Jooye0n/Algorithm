/*
https://www.acmicpc.net/problem/16929
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <memory.h>

using namespace std;
char arr[50][50];
bool chk[50][50];
int n,m;
int startX;
int startY;
bool flag;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void foundCycle(int x, int y, int cnt){
    //첫점을 만나고 cnt가 4이상이면 cycle
    chk[x][y] = true;
    
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0 && ny>=0 && nx<n && ny<m && arr[nx][ny] == arr[x][y]){
            if(chk[nx][ny]==false)
                foundCycle(nx,ny,cnt+1);
            if(nx==startX && ny==startY && cnt>=3) flag = true;
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<s.size(); j++){
            arr[i][j] = s[j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            startX = i; startY = j;
            memset(chk,false,sizeof(chk));
            foundCycle(i,j,1);
            if(flag == true){
                cout<<"Yes";
                return 0;
            }
            
        }
    }
    cout<<"No";
    return 0;
}