/*
https://www.acmicpc.net/problem/2638
*/

#include <cstdio>
#include <iostream>
#include <queue>
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
int n,m;
int cnt1;
int result;

bool isItMelt(int x, int y){
    int cnt = 0;
    for(int i=0; i<4; i++){

        int nx = x+dx[i];
        int ny = y+dy[i];

        if(arr[nx][ny]==0 && chk[nx][ny]==true) cnt++;
    }

    if(cnt>=2) return true;
    else return false;
}

int BFS(){
    int tempResult=0;//이번 turn에 녹은 치즈 수

    chk[0][0] = true;
    point p = {0,0};
    queue<point> q;
    q.push(p);

    while(q.empty() == false){
        int cx = q.front().x; 
        int cy = q.front().y; q.pop();

        for(int i=0; i<4; i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m && chk[nx][ny] == false){
                if(arr[cx][cy]==0 && arr[nx][ny]==1){
                    
                    if(isItMelt(nx,ny)==true){
                        chk[nx][ny] = true;
                        tempResult++;
                    }
                }else if(arr[cx][cy]==0 && arr[nx][ny]==0){
                    chk[nx][ny] = true;
                    point np = {nx,ny};
                    q.push(np);
                }
            }
        }
    }

    return tempResult;
}

void eraseCheeze(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
           if(arr[i][j]==1 && chk[i][j]==true) arr[i][j]=0;
        }
    }
}


int main(){
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 1) cnt1++;
        }
    }

    if(cnt1==0){
        cout<<0;
        return 0;
    }

    while(true){
        memset(chk,false,sizeof(chk));
        int temp = BFS();
        result++;
        
        if(cnt1 == temp) break;

        eraseCheeze();
        cnt1 -= temp;
    }

    cout<<result;

    return 0;
}