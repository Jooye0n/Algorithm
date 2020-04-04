/*
https://www.acmicpc.net/problem/9944
5 5
**...
.....
....*
..*..
.....
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>

#define MAX 987987987

using namespace std;

struct point{
    int x;
    int y;
};

char arr[31][31];
bool chk[31][31];
int n,m;
int minNum = MAX;
vector<point> v;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void init(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            chk[i][j] = false;
        }
    }
}

void printAll(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<chk[i][j];
        }cout<<'\n';
    }cout<<'\n';
}

void DFS(int cx, int cy, int dir, int cnt, int div){
    if(div==0){
        if(cnt<minNum){
            minNum = cnt;
            //printAll();
            return;
        }
    }else{
        int nx = cx+dx[dir];
        int ny = cy+dy[dir];

        if(nx>=0 && ny>=0 && nx<n && ny<m && arr[nx][ny]=='.' && chk[nx][ny]==false){
            chk[nx][ny] = true;
            DFS(nx,ny,dir,cnt,div-1);
            chk[nx][ny] = false;
        }else{
            for(int i=0; i<4; i++){
                if(i==dir) continue;
                nx = cx+dx[i];
                ny = cy+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && arr[nx][ny]=='.' && chk[nx][ny]==false){
                    chk[nx][ny] = true;
                    DFS(nx,ny,i,cnt+1,div-1);
                    chk[nx][ny] = false;
                }
            }
        }
    }
}

int main(){
    int t=0;
    while(cin>>n>>m){
        t++;
        minNum = MAX;
        v.clear();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>arr[i][j];
                if(arr[i][j]=='.'){
                    point p = {i,j};
                    v.push_back(p);
                }
            }
        }
        if(v.size()==1){
            printf("Case %d: 0\n",t);
            continue;
        }

        for(int i=0; i<v.size(); i++){
            for(int d=0; d<4; d++){
                init();
                chk[v[i].x][v[i].y] = true;
                DFS(v[i].x,v[i].y,d,1,v.size()-1);
                chk[v[i].x][v[i].y] = false;
            }
        }
        if(minNum==MAX) printf("Case %d: -1\n",t);
        else printf("Case %d: %d\n",t,minNum);
    }
    return 0;
}