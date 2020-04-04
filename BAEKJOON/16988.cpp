/*
https://www.acmicpc.net/problem/16988
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

int arr[20][20];
bool chk[20][20];
int n,m;
int result;

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

int BFS(int x, int y){
    int tempResult = 1;//한 집단의 값
    bool flag = false;
    queue<point> q;
    point p = {x,y};
    q.push(p);
    chk[x][y] = true;

    while(q.empty() == false){
            int cx = q.front().x; 
            int cy = q.front().y; q.pop();
            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m && chk[nx][ny] == false){
                    if(arr[nx][ny] == 2){
                        tempResult++;
                        point np = {nx,ny};
                        chk[nx][ny] = true;
                        q.push(np);
                    }else if(arr[nx][ny] == 0){
                        flag = true;
                    }
                }
            }
        
    }
    if(flag == true) return 0;
    else return tempResult;
}

void updateResult(){
    int tempResult = 0;
    memset(chk,false,sizeof(chk));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 2 && chk[i][j] == false){
                tempResult += BFS(i,j);
            }
        }
    }

    if(result<tempResult) result = tempResult;
}

void choice(int x, int k){
    if(x == 2){
        updateResult();
    }else{
        for(int i=k; i<n*m; i++){
            int cx = i/m;
            int cy = i%m;
            if(arr[cx][cy] == 0){
                arr[cx][cy] = 1;
                choice(x+1,i+1);
                arr[cx][cy] = 0;
            }
        } 
    }
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    choice(0,0);
    cout<<result;
    return 0;
}