/*
테트로미노
5 5
1 2 3 4 5
5 4 3 2 1
2 3 4 5 6
6 5 4 3 2
1 2 1 2 1

제일 왼쪽 벽돌이
1개면 
1. 1 1 1 1
2. 1 2 1
3. 1 3
4. 1 1 2

2개면
1. 2 1 1
2. 2 2

3개면
1. 3 1

4개면
1. 4

*/

#include <cstdio>
#include <iostream>
#include <memory.h>

using namespace std;

int arr[501][501];
int n,m;
int maxNum;

void found(int x, int y, int k, int cnt, int t){
    //(x,y)가 포함되게 세로로 k개 이하의 벽돌의 합을 cnt에 더한다. 지금까지 더한 벽돌의 개수는 t, 남은벽돌 k
    if(k == 0){
        if(maxNum<cnt){
            maxNum = cnt;
        }
    }else if(t<4){
        if(y>=m && y<0) return;
        for(int i=1; i<=k; i++){//같은 y에서 i개의 벽돌 
            for(int j=i-1; j>-i; j--){//시작점
                if(x+j>=0 && x+j+i-1<n){
                    int temp = 0;
                    for(int a=0; a<i; a++){//부터 i개 더하기
                        temp+=arr[x+j+a][y];
                    }
                    for(int a=0; a<i; a++){
                        found(x+j+a,y+1,k-i,cnt+temp,t+i);
                    }
                    
                }
            }

        }
    }
}

int main(){
    cin>>n>>m; 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            found(i,j,4,0,0);
        }
    }

    cout<<maxNum;
    return 0;
}