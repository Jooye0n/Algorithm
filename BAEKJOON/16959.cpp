/*
https://www.acmicpc.net/problem/16959
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

struct point{
    int x;
    int y;
    int num;
    int cur;//1은 비숍 2는 룩 3은 나이트
};
int arr[11][11];
bool chk[11][11][4][122];
int n;
queue<point> q;

int dx[8] = {-1, 1, -1, 1, 2, 2, -2, -2};
int dy[8] = {2, 2, -2, -2, -1, 1, -1, 1};

int bx[4] = {1,1,-1,-1};
int by[4] = {-1,1,1,-1};

int rx[4] = {0,1,-1,0};
int ry[4] = {-1,0,0,1};

bool pushQueue(int nx, int ny, int cn, int cc){
    if(arr[nx][ny] == cn+1 && chk[nx][ny][cc][cn+1] == false){
        chk[nx][ny][cc][cn] = true;
        chk[nx][ny][cc][cn+1] = true;
        point np = {nx,ny,cn+1,cc};
        q.push(np);
        return true;
    }else if(arr[nx][ny] != cn+1 && chk[nx][ny][cc][cn] == false) {
        chk[nx][ny][cc][cn] = true;
        point np = {nx,ny,cn,cc};
        q.push(np);
        return false;
    }
}

int BFS(){
    int result = 0;
    while(q.empty() == false){
        int size = q.size(); 
        while(size--){
            int cx = q.front().x;
            int cy = q.front().y;
            int cn = q.front().num; //찾은 수
            int cc = q.front().cur; //현재 말
            q.pop();

            if(cn == n*n) return result;
            
            if(cc == 1){ 
                for(int i=0; i<4; i++){//비숍
                    int j=1;
                    while(true){
                        int nx = cx+bx[i]*j;
                        int ny = cy+by[i]*j;
                        if(nx>0 && ny>0 && nx<=n && ny<=n){
                            if(arr[nx][ny] == cn+1 && chk[nx][ny][cc][cn+1] == false){
                                chk[nx][ny][cc][cn] = true;
                                chk[nx][ny][cc][cn+1] = true;
                                point np = {nx,ny,cn+1,cc};
                                q.push(np);
                                i=5; break;
                            }else if(arr[nx][ny] != cn+1 && chk[nx][ny][cc][cn] == false) {
                                chk[nx][ny][cc][cn] = true;
                                point np = {nx,ny,cn,cc};
                                q.push(np);
                            }
                            j++;
                        }else break;
                    }
                }
            }else if(cc == 2){
                for(int i=0; i<4; i++){//룩
                    int j=1;
                    while(true){
                        int nx = cx+rx[i]*j;
                        int ny = cy+ry[i]*j;
                        if(nx>0 && ny>0 && nx<=n && ny<=n){
                            if(arr[nx][ny] == cn+1 && chk[nx][ny][cc][cn+1] == false){
                                chk[nx][ny][cc][cn] = true;
                                chk[nx][ny][cc][cn+1] = true;
                                point np = {nx,ny,cn+1,cc};
                                q.push(np);
                                i=5; break;
                            }else if(arr[nx][ny] != cn+1 && chk[nx][ny][cc][cn] == false) {
                                chk[nx][ny][cc][cn] = true;
                                point np = {nx,ny,cn,cc};
                                q.push(np);
                            }
                            j++;
                        }else break;
                    }
                }
            }else if(cc == 3){
                for(int i=0; i<8; i++){//나이트
                    int nx = cx+dx[i];
                    int ny = cy+dy[i];
                    if(nx>0 && ny>0 && nx<=n && ny<=n){
                        if(arr[nx][ny] == cn+1 && chk[nx][ny][cc][cn+1] == false){
                            chk[nx][ny][cc][cn] = true;
                            chk[nx][ny][cc][cn+1] = true;
                            point np = {nx,ny,cn+1,cc};
                            q.push(np);
                            i=9; break;
                        }else if(arr[nx][ny] != cn+1 && chk[nx][ny][cc][cn] == false) {
                            chk[nx][ny][cc][cn] = true;
                            point np = {nx,ny,cn,cc};
                            q.push(np);
                        }
                    }    
                }
            }

            for(int i=1; i<=3; i++){
                if(cc != i && chk[cx][cy][i][cn]==false){
                    point np = {cx,cy,cn,i};
                    chk[cx][cy][i][cn] = true;
                    q.push(np);
                }
            }
        }
        result++;
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 1){
                point p1 = {i,j,1,1};
                point p2 = {i,j,1,2};
                point p3 = {i,j,1,3};

                chk[i][j][1][1] = true;
                chk[i][j][2][1] = true;
                chk[i][j][3][1] = true;

                q.push(p1);
                q.push(p2);
                q.push(p3);
            }
        }
    }

    cout<<BFS()<<'\n';
    return 0;
}