/*
N과 M (2)
https://www.acmicpc.net/problem/15650
*/
#include <cstdio>
#include <iostream>

using namespace std;
int n,m;
int arr[10];
bool chk[10];

void found(int x, int k){
    if(x == m){
        for(int i=0; i<m; i++){
            cout<<arr[i]<<' ';
        }
        printf("\n");
    }else{
        for(int i=k; i<=n; i++){
            arr[x] = i;
            found(x+1, i+1);
        }
    }
}

int main(){
    cin>>n>>m;
    found(0,1);

    return 0;
}