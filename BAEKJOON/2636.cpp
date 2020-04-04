/*
https://www.acmicpc.net/problem/2636
*/

#include <cstdio>
#include <queue>
#include <iostream>
#include <memory.h>

using namespace std;

struct point{
    int x;
    int y;
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int arr[101][101];
bool chk[101][101];
int n, m;
int allTime;

int melttingCheeze(int x, int y){

    int cnt = 0;

    chk[x][y] = true;
    point p = {x,y};
    queue<point> q;
    q.push(p);

    while(q.empty() == false){
        int cx = q.front().x;
        int cy = q.front().y; q.pop();

        for(int i=0; i<4; i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m && chk[nx][ny] == false){
                if((arr[cx][cy] == 0 && arr[nx][ny] == 1) || (arr[cx][cy] == 0 && arr[nx][ny] == 0)){
                    chk[nx][ny] = true;
                    point np = {nx,ny};
                    q.push(np);

                    if(arr[nx][ny] == 1) cnt++;
                }
            }
        }
    }

    return cnt;

}

void eraseCheeze(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 1 && chk[i][j] == true){
                arr[i][j] = 0;
            }
        }
    }
}


int main(){
    cin>>n>>m;
    int cheezeCnt = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 1){
                cheezeCnt++;
            }
        }
    }

    while(true){
        //전체 한번 치즈판 돌리며 공기와 접촉시킨다.
        allTime++;
        memset(chk,false,sizeof(chk));
        int tempCnt = melttingCheeze(0,0);
        if(tempCnt == cheezeCnt) break;
        else {
            cheezeCnt-=tempCnt;
            eraseCheeze();
        }
    }

    cout<<allTime<<'\n'<<cheezeCnt;

    return 0;
}