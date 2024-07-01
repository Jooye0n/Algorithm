/*
[ N과 M (6)]
https://www.acmicpc.net/problem/15655

4 2
9 8 7 1

1 7
1 8
1 9
7 8
7 9
8 9
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int n,m;//10,000보다 작거나 같은 자연수
int arr[10001];
int result[10001];

void found(int x, int k){
    if(x == m){
        for(int i=0; i<m; i++){
            cout<<result[i]<<' ';
        }
        cout<<'\n';
    }else{
        for(int i=k ;i<n; i++){
            result[x] = arr[i];
            found(x+1,i+1);
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
