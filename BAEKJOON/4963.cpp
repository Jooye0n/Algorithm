/*
https://www.acmicpc.net/problem/4963
*/

#include <cstdio>
#include <iostream>
#include <memory.h>

using namespace std;

int arr[50][50];
bool chk[50][50];
int n,m;

int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

void fun(int x, int y){
    chk[x][y] = true;

    for(int i=0; i<8; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0 && ny>=0 && nx<n && ny<m && chk[nx][ny] == false && arr[nx][ny] == 1){
            fun(nx,ny);
        }
    }
}

int main(){

    while(true){
        int cnt = 0;
        memset(chk,false,sizeof(chk));
        memset(arr,0,sizeof(arr));//불필요?

        cin>>m>>n;
        if(n == 0 && m == 0) break;
        for(int i=0 ;i<n ; i++){
            for(int j=0; j<m; j++){
                cin>>arr[i][j];
            }
        }

        for(int i=0 ;i<n ; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == 1 && chk[i][j] == false){
                    cnt++;
                    fun(i,j);
                }
            }
        }

        cout<<cnt<<'\n';
    }
    
    return 0;
}