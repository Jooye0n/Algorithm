/*
[ 벽 부수고 이동하기 ]
https://www.acmicpc.net/problem/2206

(1, 1)에서 (N, M)의 위치까지 이동
불가능할 때는 -1을 출력한다.

6 4
0100
1110
1000
0000
0111
0000

15
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;


struct point{
    int x;
    int y;
    bool flag;
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int n,m;
int result;
int arr[1001][1001];
int chk[1001][1001][2];//0은 벽x  1은 벽ㅇ
//queue에 넣을 때 chk
queue<point> q;

int main(){
    cin>>n>>m; 

    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        for(int j=0; j<m; j++){
            arr[i][j+1] = s[j]-'0';
        }
    }
    point p = {1,1,false};
    q.push(p);
    chk[1][1][0] = 1;

    while(q.empty() == false){
        int size = q.size();
        for(int i=0; i<size; i++){

            int cx = q.front().x;
            int cy = q.front().y;
            bool flagTemp = q.front().flag;
            q.pop();

            if(cx == n && cy == m){
                int minNum = min(chk[cx][cy][0],chk[cx][cy][1]);
                int maxNum = max(chk[cx][cy][0],chk[cx][cy][1]);
                if(maxNum == 0 && minNum == 0) cout<<-1;
                else if(minNum != 0) cout<<minNum;
                else if(minNum == 0 && maxNum != 0) cout<<maxNum;
                return 0;
            }
            
            for(int j=0; j<4; j++){
                int nx = cx+dx[j];
                int ny = cy+dy[j];
                int nextWall = arr[nx][ny];
                
                if(nx>0 && ny>0 && nx<=n && ny<=m){
                    if(flagTemp == false && nextWall == 1 && chk[nx][ny][1]==0){//벽 깬적이 없고 벽일 때
                        chk[nx][ny][1] = chk[cx][cy][0]+1;
                        point temp = {nx,ny,true};
                        q.push(temp);
                    }else if(flagTemp == false && nextWall == 0 && chk[nx][ny][0]==0){//벽 깬적이 없고 벽이 아닐 때
                        chk[nx][ny][0] = chk[cx][cy][0]+1;
                        point temp = {nx,ny,flagTemp};
                        q.push(temp);
                    }else if(flagTemp == true && nextWall == 0 && chk[nx][ny][1]==0){//벽 깬적이 있고 벽이 아닐 때
                        chk[nx][ny][1] = chk[cx][cy][1]+1;
                        point temp = {nx,ny,flagTemp};
                        q.push(temp);
                    }
                }
            }
        }
    }
    cout<<-1;
    return 0;
}