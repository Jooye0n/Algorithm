/*
파이프 옮기기
https://www.acmicpc.net/problem/17070
*/

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int n;
int arr[20][20];
int cnt;

struct pipe{
    int x; int y; 
    int dir;//가로 0  세로 1  대각선 2 
};
//가장 처음에 파이프는 (1, 1)와 (1, 2)를 차지하고 있고, 방향은 가로이다. 
//파이프의 한쪽 끝을 (N, N)로 이동시키는 방법의 개수를 구해보자.

void DFS(pipe p){
    if(p.x == n && p.y == n){
        cnt++;
    }else{
        switch(p.dir){
            case 0:
            if(p.y+1<=n && arr[p.x][p.y+1] == 0){
                pipe pp = {p.x,p.y+1,p.dir};
                DFS(pp);
            }
            if(p.x+1<=n && p.y+1<=n && arr[p.x][p.y+1] == 0 && arr[p.x+1][p.y] == 0 && arr[p.x+1][p.y+1] == 0){
                pipe pp = {p.x+1,p.y+1,2};
                DFS(pp);
            }
            break;
            case 1:
            if(p.x+1<=n && arr[p.x+1][p.y] == 0){
                pipe pp = {p.x+1,p.y,p.dir};
                DFS(pp);
            }
            if(p.x+1<=n && p.y+1<=n && arr[p.x][p.y+1] == 0 && arr[p.x+1][p.y] == 0 && arr[p.x+1][p.y+1] == 0){
                pipe pp = {p.x+1,p.y+1,2};
                DFS(pp);
            }
            break;
            case 2:
            if(p.x+1<=n && arr[p.x+1][p.y] == 0){
                pipe pp = {p.x+1,p.y,1};
                DFS(pp);
            }
            if(p.y+1<=n && arr[p.x][p.y+1] == 0){
                pipe pp = {p.x,p.y+1,0};
                DFS(pp);
            }
            if(p.x+1<=n && p.y+1<=n && arr[p.x][p.y+1] == 0 && arr[p.x+1][p.y] == 0 && arr[p.x+1][p.y+1] == 0){
                pipe pp = {p.x+1,p.y+1,2};
                DFS(pp);
            }
            break;
        }
    }
}
 
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    pipe p = {1,2,0};
    DFS(p);
    cout<<cnt;

    return 0;
}