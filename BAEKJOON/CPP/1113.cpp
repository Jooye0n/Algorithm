/*
https://www.acmicpc.net/problem/1113
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <memory.h>

using namespace std;

struct point{
    int x;
    int y;
};

int n,m;
int arr[52][52];
bool chk[52][52];
int result = 0;
bool flag = false;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int getSwimmingPool(int x, int y, int h){
    queue<point> q;
    chk[x][y] = true;
    point p = {x,y};
    q.push(p);
    int tempResult = 1;

    while(q.empty()==false){
        int cx = q.front().x;
        int cy = q.front().y; q.pop();
        for(int i=0; i<4; i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(nx>=0 && ny>=0 && nx<=n+1 && ny<=m+1 && chk[nx][ny]==false){
                if(arr[nx][ny]==h){
                    chk[nx][ny] = true;
                    point np = {nx,ny};
                    q.push(np);
                    tempResult++;
                }
                else if(arr[nx][ny]<h){
                    flag = true;
                }
            }
        }
    }
    return tempResult;
}

void fillWater(int x, int y, int h){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(chk[i][j]==true){
                arr[i][j] = h;
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        string s; cin>>s;
        for(int j=0; j<s.size(); j++){
            arr[i][j+1] = s[j]-'0';
        }
    }

    for(int h=1; h<=9; h++){
        memset(chk,false,sizeof(chk));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(arr[i][j]==h && chk[i][j]==false){
                    flag = false;
                    int temp = getSwimmingPool(i,j,h);
                    if(flag ==false){
                        fillWater(i,j,h+1);
                        result += temp;
                    }
                }
            }
        }
    }
    cout<<result;
    return 0;
}