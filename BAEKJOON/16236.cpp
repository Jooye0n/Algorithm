/*
https://www.acmicpc.net/problem/16236
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

struct point{
    int x;
    int y;
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int arr[21][21];
bool chk[21][21];
int n;
point shark;
int sharkSize = 2;
int sharkFishCnt = 0;
int fishNumber;

int result;


void BFS(){
    //한 물고기를 잡아먹는 과정
    point eatFish = {n,n};
    int tempResult=0;
    queue<point> q;
    q.push(shark);
    chk[shark.x][shark.y] = true;

    while(q.empty() == false){
        int size = q.size();
        while(size--){
            int cx = q.front().x;
            int cy = q.front().y; q.pop();

            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<n && chk[nx][ny]==false && arr[nx][ny]<=sharkSize){
                    if(arr[nx][ny] !=0 && arr[nx][ny]<sharkSize){
                        if(nx<eatFish.x){
                            eatFish.x = nx;
                            eatFish.y = ny;
                        }else if(nx==eatFish.x && ny<eatFish.y){
                            eatFish.x = nx;
                            eatFish.y = ny;
                        }
                    }
                    chk[nx][ny] = true;
                    point np = {nx,ny};
                    q.push(np);
                }
            }
        }

        tempResult++;

        if(eatFish.x !=n && eatFish.y !=n){
            //먹을 물고기 있음
            arr[eatFish.x][eatFish.y] = 0;
            sharkFishCnt++;
            result +=tempResult;

            if(sharkFishCnt == sharkSize) {
                sharkSize++;
                sharkFishCnt=0;
            }

            shark.x = eatFish.x;
            shark.y = eatFish.y;
            
            memset(chk,false,sizeof(chk));
            while(q.empty() == false) q.pop();

            tempResult = 0;
            eatFish.x = n;
            eatFish.y = n;
                
            q.push(shark);
            chk[shark.x][shark.y] = true;
            

        }
    }


}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]==9){
                shark.x = i;
                shark.y = j;
                arr[i][j] = 0;
            }
        }
    }

    BFS();
    cout<<result;

    return 0;
}