/*
[ 안전 영역 ]
https://www.acmicpc.net/problem/2468

5
6 8 2 6 2
3 2 3 4 6
6 7 3 3 2
7 2 5 3 6
8 9 5 2 7

5
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct point{
    int x;
    int y;
};

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int n;
int k;
int arr[101][101];
bool chk[101][101];
int result = 1;
queue<point> q;

void BFS(int x, int y){
    chk[x][y] = true;
    point p = {x,y};
    q.push(p);

    while(q.empty() == false){
        int size = q.size();
        for(int i=0; i<size; i++){
            point current = q.front(); q.pop();
            for(int j=0; j<4; j++){
                int nx = current.x+dx[j];
                int ny = current.y+dy[j];

                if(nx>=0 && ny>=0 && nx<n && ny<n){
                    if(chk[nx][ny] == false && arr[nx][ny]>k){
                        point next = {nx,ny};
                        q.push(next);
                        chk[nx][ny] = true;
                    }
                }
            }
        }

    }

}


int main(){
    int minNum = 100; int maxNum = 0;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]<=minNum) minNum = arr[i][j];
            if(arr[i][j]>=maxNum) maxNum = arr[i][j];
        }
    }

    for(k=minNum; k<=maxNum; k++){
        fill(&chk[0][0], &chk[100][101], false);
        int temp = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j]>k && chk[i][j] == false){
                    temp++;
                    BFS(i,j);
                }
            }
        }
        if(result<temp){
            result = temp;
        }
        
    }
    cout<<result;
    return 0;
}