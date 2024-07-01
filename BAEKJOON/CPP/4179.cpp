/*
https://www.acmicpc.net/problem/4179
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <memory.h>

using namespace std;

struct point{
    int x;
    int y;
};

int n,m;
char arr[1004][1004];
bool chk[1004][1004];
queue<point> jihoon;
queue<point> fire;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int BFS(){
    int cnt = 0;
    while(true){

        //1초간 불 이동
        int fireSize = fire.size();
        while(fireSize--){
            int cx = fire.front().x;
            int cy = fire.front().y; fire.pop();

            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];

                if(nx>=1 && ny>=1 && nx<=n && ny<=m && arr[nx][ny]=='.'){
                    point np = {nx,ny};
                    fire.push(np);
                    arr[nx][ny]='F';
                }
            }
        }

        int jihoonSize = jihoon.size();
        while(jihoonSize--){
            int cx = jihoon.front().x;
            int cy = jihoon.front().y; jihoon.pop();

            if(arr[cx][cy]=='$') return cnt;

            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];

                if(nx>=0 && ny>=0 && nx<n+2 && ny<m+2 && chk[nx][ny]==false && arr[nx][ny] != '#' && arr[nx][ny] !='F'){
                    chk[nx][ny] = true;
                    point np = {nx,ny};
                    jihoon.push(np);
                }
            }
        }

        if(jihoon.empty()==true) return -1;
        else cnt++;
    }
}
int main(){
    cin>>n>>m;
    for(int i=0; i<=n+1; i++){
        string s;
        if(i !=0 && i != n+1) cin>>s;
        for(int j=0; j<=m+1; j++){
            if(i==0 || j==0 || i==n+1 || j==m+1) arr[i][j] = '$';
            else{
                arr[i][j] = s[j-1];
                if(arr[i][j]=='J'){
                    point p = {i,j};
                    chk[i][j] = true;
                    jihoon.push(p);
                    arr[i][j] = '.';
                }

                if(arr[i][j]=='F'){
                    point p = {i,j};
                    fire.push(p);
                }
            }
        }
    }
    int temp = BFS();
    if(temp == -1) cout<<"IMPOSSIBLE";
    else cout<<temp;

    return 0;
}