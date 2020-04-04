/*
https://www.acmicpc.net/problem/2234
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>

#define T true
#define F false

using namespace std;

struct point{
    int x;
    int y;
};

int arr[51][51];
int numArr[51][51];
int n,m;
vector<int> RoomSize;
int roomNum;
int resultSize;
int maxSizeRoom;

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

bool dirArr[4][16]={
    {F,T,F,T,F,T,F,T,F,T,F,T,F,T,F,T},
    {F,F,T,T,F,F,T,T,F,F,T,T,F,F,T,T},
    {F,F,F,F,T,T,T,T,F,F,F,F,T,T,T,T},
    {F,F,F,F,F,F,F,F,T,T,T,T,T,T,T,T}
};
//dirArr[cur][dir] : 숫자 cur와 방향dir에 벽이 있는지


void finalFun(){
    //하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
    //방 하나마다 4 방향을 보면서 1. 벽이고 2. 다른 그룹이면 합쳐서 resultSize 업데이트

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int d=0; d<4; d++){
                int nx = i+dx[d];
                int ny = j+dy[d];

                if(nx>=0 && ny>=0 && nx<n && ny<m && dirArr[d][arr[i][j]]==true && numArr[nx][ny] != numArr[i][j]){
                    int temp = RoomSize[numArr[nx][ny]]+ RoomSize[numArr[i][j]];
                    if(temp>resultSize)resultSize = temp;
                }
            }
        }
    }

}

int foundGroup(int x, int y, int num){
    //num[x][y]에 num=방넘버 적는 함수 + 방의 개수 return

    int result = 1;

    queue<point> q;
    point p = {x,y};
    q.push(p);
    numArr[x][y] = num;

    while(q.empty() == false){
        int cx = q.front().x;
        int cy = q.front().y; q.pop();

        for(int i=0; i<4; i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m && dirArr[i][arr[cx][cy]]==false && numArr[nx][ny]==-1){
                numArr[nx][ny] = num;
                result++;
                point np = {nx,ny};
                q.push(np);
            }
        }
    }


    return result;
}

int main(){
    cin>>m>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    
    memset(numArr,-1,sizeof(numArr));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(numArr[i][j]==-1){
                int size = foundGroup(i,j,roomNum);
                if(size>maxSizeRoom) maxSizeRoom = size;
                RoomSize.push_back(size);
                roomNum++;
            }
        }
    }

    finalFun();

    cout<<roomNum<<'\n';
    cout<<maxSizeRoom<<'\n';
    cout<<resultSize<<'\n';



    return 0;
}