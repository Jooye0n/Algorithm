/*
[ N과 M (5) ]
https://www.acmicpc.net/problem/15654

4 2
9 8 7 1
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int result[9];
int arr[9];
bool chk[9];

void found(int x){
    if(x == m){
        for(int i=0; i<m; i++){
            cout<<result[i]<<' ';
        }
        cout<<'\n';
    }else{
        for(int i=0; i<n; i++){
            if(chk[i] == false){
                result[x] = arr[i];
                chk[i] = true;
                found(x+1);
                chk[i] = false;
            }
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
