/*
[ N과 M (7) ]
https://www.acmicpc.net/problem/15656

4 2
9 8 7 1
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int n,m;
int arr[10];
int result[10];

void found(int x){
    if(x == m){
        for(int i=0 ; i<m; i++){
            cout<<result[i]<<' ';
        }
        cout<<'\n';
    }else{
        for(int i=0; i<n; i++){
            result[x] = arr[i];
            found(x+1);
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    found(0);
    
    return 0;
}