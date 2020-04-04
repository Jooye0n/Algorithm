/*
https://www.acmicpc.net/problem/3709

2 //테스트케이스 개수
2 3 //보드크기 거울개수
1 1
1 2
2 2
3 1 //레이저 위치
*/

#include <cstdio>
#include <iostream>
#include <memory.h>

using namespace std;
int n,r;
bool arr[52][52];

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};

int initMirror(int x, int y){
    if(x == 0) return 2;
    else if(x == n+1) return 0;
    else if(y == 0) return 1;
    else if(y == n+1) return 3;
}

int main(){
    int T; cin>>T;
    while(T--){
        memset(arr,0,sizeof(arr));
        cin>>n>>r;
        
        while(r--){
            int x,y;
            cin>>x>>y;
            arr[x][y] = true;//거울
        }

        int cx,cy;
        cin>>cx>>cy;

        int dir = initMirror(cx,cy);
        int nx,ny;
        int idx = 0;
        while(true){
            nx = cx+dx[dir];
            ny = cy+dy[dir];

            if(nx<1 || ny<1 || nx>n || ny>n){
                cout<<nx<<' '<<ny<<'\n';
                break;
            }

            if(arr[nx][ny] == true){//거울이면,
                dir = (dir+1) % 4;
            }

            cx = nx;
            cy = ny;
            idx++;
            if(idx>987987){
                cout<<"0 0\n";
                break;
            }
        }
    }
    return 0;
}