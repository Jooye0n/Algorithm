/*
https://www.acmicpc.net/problem/17406
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

struct spin{
    int x; 
    int y;
    int half;
};

int n,m,k;
int temp[50][50];
int arr[50][50];
bool chk[6];
vector<spin> v;
vector<int> spinNum;
int minNum = 987987987;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void getArrValue(){

    for(int i=0; i<n; i++){
        int tempResult = 0;
        for(int j=0; j<m; j++){
            tempResult += temp[i][j];
        }
        minNum = min(minNum,tempResult);
    }
}

void changeArr(int cx, int cy, int half){
    
    int tempDir = 0;
    int x = cx;
    int y = cy;
    cx = cx-half;
    cy = cy-half;

    int tempValue = temp[cx][cy];

    while(tempDir<4){
        int nx = cx+dx[tempDir];
        int ny = cy+dy[tempDir];
        if(nx>=x-half && nx<=x+half && ny>=y-half && ny<=y+half){
            temp[cx][cy] = temp[nx][ny];
            cx = nx;
            cy = ny;
        }else{
            tempDir++;
        }
    }
    temp[x-half][y-half+1] = tempValue;
}

void choice(int x){
    if(x == k){
        //회전 순서 다정함.
        memcpy(temp,arr,sizeof(arr));

        for(int i=0; i<k; i++){
            int idx = spinNum[i];
            for(int j=1; j<=v[idx].half; j++){//그룹
                changeArr(v[idx].x,v[idx].y,j);
            }
        }

        getArrValue();

    }else{
        for(int i=0; i<k; i++){
            if(chk[i] == false){
                chk[i] = true;
                spinNum.push_back(i);

                choice(x+1);

                chk[i] = false;
                spinNum.pop_back();
            }
        }
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<k; i++){
        spin s;
        
        cin>>s.x>>s.y>>s.half;
        s.x--; s.y--;
        v.push_back(s);
    }

    choice(0);
    cout<<minNum;

    return 0;
}
