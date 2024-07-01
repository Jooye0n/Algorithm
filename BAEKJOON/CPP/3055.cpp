/*
https://www.acmicpc.net/problem/3055
3 3
D.*
...
.S.
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct point{
    int x;
    int y;
};

int n,m;
queue<point> water;
queue<point> q;
point dest;
int cntBlank;

char arr[51][51];
int chk[51][51];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void printAll(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<chk[i][j];
        }cout<<'\n';
    }cout<<'\n';
}

void BFS(){
    while(true){
        //1분간 물의 이동
        int size = water.size();
        while(size--){
            int cx = water.front().x;
            int cy = water.front().y; water.pop();

            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m && arr[nx][ny]=='.'){
                    arr[nx][ny] = '*';
                    cntBlank--;
                    point np = {nx,ny};
                    water.push(np);
                }
            }
        }

        int qsize = q.size();
        while(qsize--){
            int cx = q.front().x;
            int cy = q.front().y; q.pop();

            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m && arr[nx][ny]!='*' && arr[nx][ny] !='X'){
                    if(chk[nx][ny]==0 || chk[nx][ny]>chk[cx][cy]+1){
                        chk[nx][ny] = chk[cx][cy]+1;
                        point np = {nx,ny};
                        q.push(np);
                    }
                }
            }
        }

        if(chk[dest.x][dest.y]>0){
            cout<<chk[dest.x][dest.y];
            break;
        }

        if(cntBlank==0 || q.size()==0){
            cout<<"KAKTUS";
            break;
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<s.size(); j++){
            arr[i][j] = s[j];
            if(arr[i][j]=='*'){
                point p = {i,j};
                water.push(p);
            }else if(arr[i][j]=='S'){
                arr[i][j] = '.';
                point p = {i,j};
                q.push(p);
            }else if(arr[i][j]=='D'){
                dest.x = i;
                dest.y = j;
            }else if(arr[i][j]=='.'){
                cntBlank++;
            }
        }
    }

    BFS();
    return 0;
}
