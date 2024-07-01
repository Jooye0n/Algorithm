/*
[ N과 M (8) ]
https://www.acmicpc.net/problem/15657

4 2
9 8 7 1

1 1
1 7
1 8
1 9
7 7
7 8
7 9
8 8
8 9
9 9
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;
int arr[10];
int result[10];

void found(int x, int k){
    if(x == m){
        for(int i=0; i<m; i++){
            cout<<result[i]<<' ';
        }
        cout<<'\n';
    }else{
        for(int i=k; i<n; i++){
            result[x] = arr[i];
            found(x+1,i);
        }

    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    found(0,0);
    return 0;
}