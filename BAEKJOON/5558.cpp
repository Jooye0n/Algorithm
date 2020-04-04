/*
https://www.acmicpc.net/problem/5558
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

struct point{
    int x; int y;
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

point start;
int arr[1001][1001];
bool chk[1001][1001];
int n,m,k;
int result;

int found(int x){
    //start 부터 시작해서 x 찾는 BFS
    chk[start.x][start.y] = true;
    queue<point> q;
    q.push(start);
    int dist = 1;

    while(q.empty() == false){
        int size = q.size();

        while(size--){
            int cx = q.front().x;
            int cy = q.front().y; q.pop();

            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m && arr[nx][ny]!=-1 && chk[nx][ny] == false){//장애물로 못간다.
                    //만약 쥐보다 치즈가 크면, 무시하고 간다.
                    chk[nx][ny] = true;
                    point np = {nx,ny};
                    q.push(np);

                    if(arr[nx][ny] == x){
                        //만약 쥐=치즈면, BFS종료.
                        start.x = nx;
                        start.y = ny;
                        return dist;
                    }
                    
                }
            }
        }

        dist++;
    }
}


int main(){
    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char temp;
            cin>>temp;
            if(temp == '.'){
                arr[i][j] = 0;
            }else if(temp == 'S'){
                start.x = i;
                start.y = j;
                arr[i][j] = 0;
            }else if(temp == 'X'){
                arr[i][j] = -1;
            }else{
                arr[i][j] = temp-'0';
            }
        }
    }

    for(int i=1; i<=k; i++){
        //1부터 k까지 찾는다.
        memset(chk,false,sizeof(chk));
        result +=found(i);
    }

    cout<<result;
    return 0;
}