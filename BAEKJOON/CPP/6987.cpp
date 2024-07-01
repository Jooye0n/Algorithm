/*
acmicpc.net/problem/6987
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

struct point{
    int x, y;
};

int T=4;
bool flag;
int answer[6][3];
int tempArr[6][3];
vector<int> temp;
vector<point> fight;

bool isItSame(){
    for(int i=0; i<6; i++){
        for(int j=0; j<3; j++){
            if(answer[i][j] != tempArr[i][j]) return false;
        }
    }
    return true;
}


void DFS(int x){
    if(x == 15){
        if(isItSame() == true){
            flag = true;
            return;
        }
    }else{
        int first = fight[x].x;
        int second = fight[x].y;

        tempArr[first][0]++;
        tempArr[second][2]++;
        DFS(x+1);

        tempArr[first][0]--;
        tempArr[second][2]--;
        tempArr[first][1]++;
        tempArr[second][1]++;
        DFS(x+1);

        tempArr[first][1]--;
        tempArr[second][1]--;
        tempArr[first][2]++;
        tempArr[second][0]++;
        DFS(x+1);
        tempArr[first][2]--;
        tempArr[second][0]--;
    }
}


void makeTable(int x, int k){
    if(x == 2){
        point p = {temp[0],temp[1]};
        fight.push_back(p);
    }else{
        for(int i=k; i<6; i++){
            temp.push_back(i);
            makeTable(x+1,i+1);
            temp.pop_back();
        }
    }
}

int main(){

    while(T--){
        flag = false;
        fight.clear();
        memset(tempArr,0,sizeof(tempArr));

        for(int i=0; i<6; i++){
            for(int j=0; j<3; j++){
                cin>>answer[i][j];
            }
        }
        
        makeTable(0,0);
        DFS(0);
        
        flag == true ? cout<<1<<' ' : cout<<0<<' ';
    }
    return 0;
}