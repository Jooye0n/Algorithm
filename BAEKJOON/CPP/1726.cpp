/*
https://www.acmicpc.net/problem/1726
*/

#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
struct point{
    int x;
    int y;
    int dir;
};

int dx[5] = {0,0,0,1,-1};
int dy[5] = {0,1,-1,0,0};
int arr[101][101];
bool chk[101][101][5];

int n,m;
point startP, endP;

bool testNP(int cx, int cy, int cd, int k){
    for(int t=1; t<=k; t++)
        if(arr[cx+dx[cd]*t][cy+dy[cd]*t]==1) return false;
    return true;
}

bool outDir(int cd, int nd){
    if(cd==1 && nd==2) return true;
    if(cd==2 && nd==1) return true;
    if(cd==3 && nd==4) return true;
    if(cd==4 && nd==3) return true;
    return false;
}

int BFS(){
    int result = 0;
    chk[startP.x][startP.y][startP.dir] = true;
    queue<point> q;
    q.push(startP);

    while(q.empty()==false){
        int size = q.size();

        while(size--){
            int cx = q.front().x;
            int cy = q.front().y;
            int cd = q.front().dir; q.pop();

            if(cx==endP.x && cy==endP.y && cd==endP.dir){
                return result;
            }

            //회전
            for(int i=1; i<5; i++){
                if(outDir(cd,i)==true) continue;
                if(chk[cx][cy][i]==true) continue;

                point np = {cx,cy,i};
                chk[cx][cy][i] = true;
                q.push(np);
            }

            //k 만큼 전진
            for(int k=1; k<=3; k++){
                if(testNP(cx,cy,cd,k)==false) break;
                
                int nx = cx+dx[cd]*k;
                int ny = cy+dy[cd]*k;

                if(nx>0 && ny>0 && nx<=n && ny<=m && arr[nx][ny]==0 && chk[nx][ny][cd]==false){
                    chk[nx][ny][cd]= true;
                    point np = {nx,ny,cd};
                    q.push(np);
                }
            }
        }
        result++;
    }
}


int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }

    cin>>startP.x>>startP.y>>startP.dir;
    cin>>endP.x>>endP.y>>endP.dir;

    cout<<BFS();
    return 0;
}