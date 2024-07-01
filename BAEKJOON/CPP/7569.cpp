/*
[ 토마토 ]
https://www.acmicpc.net/problem/7569
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point{
    int x;
    int y;
    int z;
};

int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0,0,0,1,-1};

int n,m,h;
int arr[102][102][102];
bool chk[102][102][102];
queue<point> q;
int result = -1;
int total;

int main(){
    cin>>m>>n>>h;
    total = n*m*h;
    for(int k=h-1; k>=0; k--){
        for(int i=0 ;i<n; i++){
            for(int j=0; j<m; j++){
                cin>>arr[i][j][k];
                if(arr[i][j][k] == 1){
                    point p = {i,j,k};
                    q.push(p);
                    total--;
                    chk[i][j][k] = true;
                }else if(arr[i][j][k] == -1){
                    total--;
                }
            }
        }
    }

    while(q.empty() == false){
        int size = q.size();
        result++;
        for(int i=0; i<size; i++){
            int cx = q.front().x;
            int cy = q.front().y;
            int cz = q.front().z;
            q.pop();

            for(int j=0; j<6; j++){
                int nx = cx + dx[j];
                int ny = cy + dy[j];
                int nz = cz + dz[j];
                if(nx>=0 && ny>=0 && nz>=0 && nx<n && ny<m && nz<h){
                    if(chk[nx][ny][nz] == false && arr[nx][ny][nz] == 0){
                        chk[nx][ny][nz] = true;
                        arr[nx][ny][nz] = 1;
                        total--;
                        point p = {nx,ny,nz};
                        q.push(p);
                    }
                }
            }
        }
    }

    if(total == 0){
        cout<<result;
    }else{
        cout<<-1;
    }


    return 0;
}