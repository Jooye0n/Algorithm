/*
[ 토마토 ]
https://www.acmicpc.net/problem/7576
6 4
1 -1 0 0 0 0
0 -1 0 0 0 0
0 0 0 0 -1 0
0 0 0 0 -1 1
6
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct point{
    int x;
    int y;
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int arr[1001][1001];
bool chk[1001][1001];
queue<point> q;
int totalSize;
int countSize;
int result = -1;

int n,m;

void BFS(){
    while(q.empty() == false){
        int size = q.size();
        result++;
        for(int i=0; i<size; i++){
            point current = q.front(); q.pop();

            for(int j=0; j<4; j++){
                int nx = current.x+dx[j];
                int ny = current.y+dy[j];

                if(nx>=0 && ny>=0 && nx<n &&ny<m){
                    if(chk[nx][ny] == false && arr[nx][ny] == 0){
                        point t = {nx,ny};
                        chk[nx][ny] = true;
                        q.push(t);
                        countSize++;
                    }
                }
            }
        }
    }
}

int main(){
    cin>>m>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j] != -1){
                totalSize++;
                if(arr[i][j] == 1){
                    point p = {i,j};
                    chk[i][j] = true;
                    q.push(p);
                    countSize++;
                }
            }
        }
    }


    BFS();

    if(totalSize == countSize){
        cout<<result;
    }else{
        cout<<-1;
    }

    return 0;
}
