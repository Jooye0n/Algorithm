/*
https://www.acmicpc.net/problem/5427
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
char arr[1002][1002];
bool chk[1002][1002];//상근이
queue<point> q;//상근이
queue<point> fire;
int T;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int move(){
    int cnt = 0;
    while(true){
        //불 움직이기
        int fireSize = fire.size();
        while(fireSize--){
            int cx = fire.front().x;
            int cy = fire.front().y; fire.pop();

            for(int i=0 ;i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];

                if(nx>0 && ny>0 && nx<n+1 && ny<m+1 && arr[nx][ny]=='.'){
                    arr[nx][ny] = '*';
                    point np = {nx,ny};
                    fire.push(np);
                }
            }
        }

        //상근 움직이기
        int size = q.size();
        while(size--){
            int cx = q.front().x;
            int cy = q.front().y; q.pop();

            if(arr[cx][cy] == '$') return cnt;

            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];

                if(nx>=0 && ny>=0 && nx<n+2 && ny<m+2 && arr[nx][ny] != '*' && arr[nx][ny] !='#' && chk[nx][ny]==false){
                    point np = {nx,ny};
                    chk[nx][ny] = true;
                    q.push(np);
                }
            }
        }

        if(q.empty()==true) return -1;
        else cnt++;
    }
}

int main(){
    cin>>T;
    while(T--){

        while(q.empty()==false) q.pop();
        while(fire.empty()==false) fire.pop();
        memset(chk,false, sizeof(chk));

        cin>>m>>n;

        for(int i=0; i<n+2; i++){
            string s; 
            if(i !=0 && i !=n+1) cin>>s;
            for(int j=0; j<m+2; j++){
                if(i==0 || j==0 || i==n+1 || j==m+1) arr[i][j] = '$';
                else{
                    arr[i][j] = s[j-1];
                    if(arr[i][j]=='@'){
                        point p = {i,j};
                        q.push(p);
                        chk[i][j] = true;
                        arr[i][j] = '.';
                    }else if(arr[i][j]=='*'){
                        point p = {i,j};
                        fire.push(p);
                    }
                }
            }
        }
        
        int result = move();
        result==-1 ? cout<<"IMPOSSIBLE"<<'\n' : cout<<result<<'\n';
    }

    return 0;
}