/*
[ N과 M(4) ]
https://www.acmicpc.net/problem/15652
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int arr[10];

void found(int x){
    if(x == m+1){
        for(int i=1 ;i<=m; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
    }else{
        for(int i=arr[x-1]; i<=n; i++){
            arr[x]= i;
            found(x+1);
        }
    }

}

int main(){
    cin>>n>>m;
    arr[0] = 1;
    found(1);
    return 0;
}