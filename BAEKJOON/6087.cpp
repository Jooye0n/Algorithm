/*
https://www.acmicpc.net/problem/6087
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#define MAX 987987987

using namespace std;

struct point{
    int x;
    int y;
};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int result = MAX;
int n,m;
char arr[101][101];
int chk[101][101][4];

point starC[2];
vector<point> pointC;

void printA(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<chk[i][j][0]<<' ';
        }cout<<'\n';
    }cout<<'\n';
}

void BFS(){
    for(int i=0; i<4; i++){
        chk[pointC[0].x][pointC[0].y][i] = 0;
    }
    queue<point> q;
    q.push(pointC[0]);

    while(q.empty() == false){
        int cx = q.front().x;
        int cy = q.front().y; 
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m && arr[nx][ny] !='*'){

                int temp1 = min(chk[cx][cy][(i+1)%4],chk[cx][cy][(i+3)%4]) + 1;
                int temp2 = chk[cx][cy][i];
                int tempResult = min(temp1, temp2);

                if(tempResult != MAX && chk[nx][ny][i]>tempResult){
                    point np = {nx,ny};
                    q.push(np);
                    chk[nx][ny][i] = tempResult;
                }
            }
        }
    }
}

int main(){

    cin>>m>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int d=0; d<4; d++){
                chk[i][j][d] = MAX;
            }
        }
    }

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<s.size(); j++){
            arr[i][j] = s[j];
            if(arr[i][j]=='C'){
                point p = {i,j};
                pointC.push_back(p);
            }
        }
    }

    BFS();

    for(int i=0; i<4; i++){
        if(chk[pointC[1].x][pointC[1].y][i]<result){
            result = chk[pointC[1].x][pointC[1].y][i];
        }
    }

    cout<<result;

    return 0;
}