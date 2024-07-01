/*
[ N과 M(3)]
https://www.acmicpc.net/problem/15651

4 2

1 1
1 2
1 3
1 4
2 1
2 2
2 3
2 4
3 1
3 2
3 3
3 4
4 1
4 2
4 3
4 4
*/

#include <cstdio>
#include <iostream>

using namespace std;
int n,m;
int arr[10];
bool chk[10];

void found(int x){
    if(x == m){
        for(int i=0; i<m; i++){
            cout<<arr[i]<<' ';
        }
        printf("\n");
    }else{
        for(int i=1; i<=n; i++){
            arr[x] = i;
            found(x+1);
        }
    }
}

int main(){
    cin>>n>>m;
    found(0);
    return 0;
}