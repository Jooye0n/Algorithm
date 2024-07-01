/*
https://www.acmicpc.net/problem/11559

......
......
......
......
......
......
......
......
.Y....
.YG...
RRYG..
RRYGG.
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <memory.h>
#include <vector>
#include <string>

using namespace std;

struct point{
    int x;
    int y;
};

int n=12;
int m=6;
char arr[12][6];
bool chkBomb[12][6];
vector<point> v;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bomb(int x, int y){
    for(int i=0; i<v.size(); i++){
        int cx = v[i].x;
        int cy = v[i].y;
        arr[cx][cy] = '.';
    }
}

bool isItBomb(int x, int y){
    
    int cnt = 1;
    v.clear();
    queue<point> q;
    point p = {x,y};
    q.push(p);
    v.push_back(p);
    chkBomb[x][y] = true;

    while(q.empty() == false){
        int cx = q.front().x;
        int cy = q.front().y; q.pop();

        for(int i=0; i<4; i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m && arr[nx][ny] == arr[cx][cy] && chkBomb[nx][ny]==false){
                cnt++;
                chkBomb[nx][ny] = true;
                point np = {nx,ny};
                q.push(np);
                v.push_back(np);
            }
        }
    }

    if(cnt>=4) return true;
    else return false;   
}

void down(){
    for(int j=0 ;j<m; j++){
        queue<char> temp;
        for(int i=n-1; i>=0; i--){
            if(arr[i][j]!='.'){
                temp.push(arr[i][j]);
            }
        }
        int size= temp.size();

        for(int i=n-1; i>n-1-size; i--){
            arr[i][j] = temp.front(); temp.pop();
        }
        for(int i=n-1-size; i>=0; i--){
            arr[i][j] = '.';
        }
    }
}

int main(){

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<m; j++){
            arr[i][j] = s[j];
        }
    }

    int cnt = 0;

    while(true){

        bool flag = false;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] !='.' && chkBomb[i][j]==false){
                    if(isItBomb(i,j)==true){
                        bomb(i,j);
                        flag = true;
                    }
                }
            }
        }

        if(flag == false) break;
        else{
            cnt++;
            down();
            memset(chkBomb,false,sizeof(chkBomb));
        }
    }

    cout<<cnt;
    return 0;
}