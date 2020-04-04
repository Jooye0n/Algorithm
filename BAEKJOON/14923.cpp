/*
https://www.acmicpc.net/problem/14923
*/


#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

struct point{
    int x;
    int y;
    bool flag;
};

int n,m;
int arr[1001][1001];
int chk[1001][1001][2];//0이 벽 뚫지 않은 거

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

point startP, endP;

void foundRoute(){
    queue<point> q;
    chk[startP.x][startP.y][0] = 0;
    q.push(startP);

    while(q.empty() == false){
        int size = q.size();
        while(size--){
            int cx = q.front().x;
            int cy = q.front().y; 
            bool cflag = q.front().flag; q.pop();

            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                
                if(nx>0 && ny>0 && nx<=n && ny<=m){

                    if(arr[nx][ny]==1 && cflag==0){ //벽
                        if(chk[nx][ny][1]==0 || chk[nx][ny][1]>chk[cx][cy][0]+1){
                            chk[nx][ny][1] = chk[cx][cy][0]+1;
                            if(nx==endP.x && ny==endP.y) return;
                            point np = {nx,ny,1};
                            q.push(np);
                        }

                    }else if(arr[nx][ny]==0){
                        if(chk[nx][ny][cflag]==0 || chk[nx][ny][cflag]>chk[cx][cy][cflag]+1){
                            chk[nx][ny][cflag] = chk[cx][cy][cflag]+1;
                            if(nx==endP.x && ny==endP.y) return;
                            point np = {nx,ny,cflag};
                            q.push(np);
                        }
                    }
                }
            }
        }
    }

}

int main(){
    cin>>n>>m;
    cin>>startP.x>>startP.y>>endP.x>>endP.y;

    startP.flag = false;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }


    foundRoute();

    if(chk[endP.x][endP.y][0]== 0 && chk[endP.x][endP.y][1]==0){
        cout<<-1;
    }else if(min(chk[endP.x][endP.y][0],chk[endP.x][endP.y][1])!=0){
        cout<<min(chk[endP.x][endP.y][0],chk[endP.x][endP.y][1]);
    }else{
        cout<<max(chk[endP.x][endP.y][0],chk[endP.x][endP.y][1]);
    }
    

    return 0;
}