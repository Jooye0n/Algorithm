/*
https://www.acmicpc.net/problem/11403

7
0 0 0 1 0 0 0
0 0 0 0 0 0 1
0 0 0 0 0 0 0
0 0 0 0 1 1 0
1 0 0 0 0 0 0
0 0 0 0 0 0 1
0 0 1 0 0 0 0
*/

#include <cstdio>
#include <iostream>
#include <memory.h>

using namespace std;

int arr[101][101];
bool chk[100];
int n;

void DFS(int x, int k){
    if(chk[k] == false){

        for(int i=0; i<n; i++){
            if(arr[k][i] == 1){
                arr[x][i] = 1;
                chk[k] = true;///이거 위치때문에 한참헤맸다..
                DFS(x,i);
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0 ;i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        memset(chk,false,sizeof(chk));
        DFS(i,i);
    }

    for(int i=0 ;i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<' ';
        }cout<<'\n';
    }
    return 0;
}