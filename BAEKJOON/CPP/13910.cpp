/*
https://www.acmicpc.net/problem/13901

3 3
1
1 0
1 1
1 2 3 4
*/
#include <cstdio>
#include <iostream>

using namespace std;

int n,m;
int k;
int arr[1000][1000];
bool chk[1000][1000];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int cx,cy;
int dir[4];

void move(){
    int cd =0;
    int cnt = 0;

    while(cnt<4){
        int nx = cx+dx[dir[cd]-1];
        int ny = cy+dy[dir[cd]-1];

        if(nx>=0 && ny>=0 && nx<n && ny<m && arr[nx][ny]==0 && chk[nx][ny]==false){
            cx=nx;
            cy=ny;
            chk[cx][cy] = true;
            cnt=0;
        }else{
            cd = (cd+1)%4;
            cnt++;
        }
    }
}

int main(){
    cin>>n>>m;
    cin>>k;
    while(k--){
        int x, y;
        cin>>x>>y;
        arr[x][y] = 1;
    }
    cin>>cx>>cy;
    chk[cx][cy] = true;

    for(int i=0 ; i<4; i++){
        cin>>dir[i];
    }

    move();
    cout<<cx<<' '<<cy;

    return 0;
}