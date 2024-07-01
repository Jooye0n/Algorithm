/*
https://www.acmicpc.net/problem/2573
*/
#include <cstdio>
#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

struct point{
    int x;
    int y;
};

int n,m;
int arr[301][301];
bool chk[301][301];
int meltCnt[301][301];
int result = 0;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int countWater(int x, int y){
    int cnt = 0;
    for(int i=0; i<4; i++){
        if(arr[x+dx[i]][y+dy[i]]==0)cnt++;
    }
    return cnt;
}

void melting(){
    for(int i=1; i<n-1; i++){
        for(int j=1; j<m-1; j++){
            arr[i][j]-=meltCnt[i][j];
            if(arr[i][j]<0) arr[i][j] = 0;
        }
    }
}

void BFS(int x, int y){
    chk[x][y]= true;
    meltCnt[x][y] = countWater(x,y);
    point p = {x,y};
    queue<point> q;
    q.push(p);

    while(q.empty()==false){
        int cx = q.front().x;
        int cy = q.front().y; q.pop();

        for(int i=0; i<4; i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(nx>=1 && ny>=1 && nx<n-1 && ny<m-1 && chk[nx][ny]==false && arr[nx][ny] != 0){
                meltCnt[nx][ny] = countWater(nx,ny);
                chk[nx][ny] = true;
                point np = {nx,ny};
                q.push(np);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if (i==0 || i==n-1 || j==0 || j==m-1) arr[i][j] = 0;
        }
    }

    while(true){

        int groupNum = 0;
        memset(chk,false,sizeof(chk));
        memset(meltCnt,0,sizeof(meltCnt));

        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(arr[i][j] !=0 && chk[i][j]==false){
                    groupNum++;
                    BFS(i,j);
                }
            }
        }
        melting();
        result++;

        if(groupNum >1){
            result--;
            break;
        }else if(groupNum==0){
            result = 0;
            break;
        }
    }

    cout<<result;
    return 0;
}