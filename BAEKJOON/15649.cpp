/*
[ N과 M ]
https://www.acmicpc.net/problem/15649

예제 입력 2 
4 2
예제 출력 2 
1 2
1 3
1 4
2 1
2 3
2 4
3 1
3 2
3 4
4 1
4 2
4 3
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
            if(chk[i] == false){
                chk[i] = true;
                arr[x] = i;
                found(x+1);
                chk[i] = false;
            }
        }
    }
}

int main(){
    cin>>n>>m;

    found(0);

    return 0;
}