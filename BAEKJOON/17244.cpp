/*
https://www.acmicpc.net/problem/17244
*/

#include <cstdio>
#include <iostream>
#include <memory.h>
#include <string>
#include <queue>
#include <math.h>

using namespace std;

struct point{
    int x;
    int y;
    bool flag[6];
};

char arr[50][50];
bool chk[50][50][32];//0 1 2 3 4 5( 챙긴 물건)
int n,m;
int cntX = 1;
int answer;
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};


bool visitChk(bool flag[], int nx, int ny){
    for(int i=0; i<cntX; i++){
        if(flag[i] != chk[nx][ny][i]) return false;
    }
    return true;
}

int keyToBinary(bool key[]){
    int tempResult = 0;
    int idx = 1;
    for(int i=1; i<cntX; i++){
        if(key[i] == true){
            tempResult +=idx;
        }
        idx*=2;
    }
    return tempResult;
}

int BFS(int x, int y){
    int result = 0;
    queue<point> q;
    point p = {x,y,{true,false,false,false,false,false}};
    chk[x][y][0] = true;
    q.push(p);

    while(q.empty() == false){
        int size = q.size();
        while(size--){
            int cx = q.front().x;
            int cy = q.front().y; 
            int cb = keyToBinary(q.front().flag);
            bool cflag[6];
            for(int j=0; j<cntX; j++){
                cflag[j] = q.front().flag[j];
            }
            q.pop();

            if(arr[cx][cy] == 'E' && cb == answer){
                return result;
            }

            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;

                if(arr[nx][ny] !='#' && chk[nx][ny][cb] == false){
                    if(arr[nx][ny] == '.' || arr[nx][ny] == 'E'){
                        point np = {nx,ny,{cflag[0],cflag[1],cflag[2],cflag[3],cflag[4],cflag[5]}}; 
                        chk[nx][ny][cb] = true;
                        q.push(np);
                    }else{
                        point np = {nx,ny,{cflag[0],cflag[1],cflag[2],cflag[3],cflag[4],cflag[5]}}; 
                        np.flag[arr[nx][ny]-'0'] = true;
                        int cbt = keyToBinary(np.flag);
                        chk[nx][ny][cbt] = true;
                        q.push(np);
                    }
                }
            }
        }
        result++;
    }
}

int main(){
    int startX, startY;
    cin>>m>>n;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<m; j++){
            arr[i][j] = s[j];
            if(arr[i][j] == 'X'){
                arr[i][j] = cntX+'0';
                cntX++;
            }else if(arr[i][j] == 'S'){
                startX = i;
                startY = j;
                arr[i][j] = '.';
            }
        }
    }

    if(cntX != 1) {
        for(int i=0; i<cntX-1; i++){
            answer += pow(2,i);
        }
    }
    cout<<BFS(startX,startY);
    return 0;
}
