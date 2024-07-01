/*
https://www.acmicpc.net/problem/16985
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <memory.h>
#include <algorithm>
#define MAX 987987987

using namespace std;

struct point{
    int x;
    int y;
    int z;
};

int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {1,-1,0,0,0,0};
bool chkTemp[5];
bool arr[5][5][5];
bool chk[5][5][5];
vector<int> turnArr;
vector<int> turnDir;

bool maze[5][5][5];
int result = MAX;

int goOut(){
    int tempResult = 0;
    chk[0][0][0] = true;
    point p = {0,0,0};
    queue<point> q;
    q.push(p);

    while(q.empty()==false){
        int size = q.size();
        while(size--){
            int cx = q.front().x;
            int cy = q.front().y;
            int cz = q.front().z; q.pop();

            if(cx==4 && cy==4 && cz==4) return tempResult;

            for(int i=0; i<6; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                int nz = cz+dz[i];

                if(nx>=0 && ny>=0 && nz>=0 && nx<5 && ny<5 && nz<5 && chk[nx][ny][nz]==false && maze[nx][ny][nz]==1){
                    point np = {nx,ny,nz};
                    q.push(np);
                    chk[nx][ny][nz] = true;
                }
            }
        }
        tempResult++;
    }

    return MAX;

}

void makeMaze(int x){
    if(x==5){
        for(int idx=0; idx<turnArr.size(); idx++){
            //idx번째 turnArr idx번째 turnDir만큼 회전해서 maze에 넣기
            bool temp[5][5];

            //arr 옮겨온 후
            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    temp[i][j] = arr[i][j][turnArr[idx]];
                }
            }

            //idx만큼 회전
            int size = turnDir[idx];
            while(size--){
                bool temp2[5][5];
                for(int i=0; i<5; i++){
                    for(int j=0; j<5; j++){
                        temp2[4-j][i] = temp[i][j];
                    }
                }
                memcpy(temp,temp2,sizeof(temp));
            }


            //maze채우기
            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    maze[i][j][idx] = temp[i][j];
                }
            }
        }

        //탈출
        if(maze[0][0][0] == 1 && maze[4][4][4] == 1){
            memset(chk,false,sizeof(chk));
            int resultTemp = goOut();
            if(resultTemp < result) result = resultTemp;
        }
    }else{
        for(int i=0; i<4; i++){
            turnDir.push_back(i);
            makeMaze(x+1);
            turnDir.pop_back();
        }
    }
}

void getTurn(int x){
    //순서 정하기(0 1 2 3 4)
    if(x == 5){
        makeMaze(0);
    }else{
        for(int i=0; i<5; i++){
            if(chkTemp[i] == false){
                chkTemp[i] = true;
                turnArr.push_back(i);
                getTurn(x+1);
                chkTemp[i] = false;
                turnArr.pop_back();
            }
            
        }
    }
}

int main(){
    for(int h=0; h<5; h++){
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                cin>>arr[i][j][h];
            }
        }
    }

    getTurn(0);

    result == MAX ? cout<<-1 : cout<<result;
    return 0;
}