/*
https://www.acmicpc.net/problem/17135
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

struct point{
    int x;
    int y;
};

int n,m,d;
int arr[15][15];
int chk[300];//죽을 적 chk
vector<point> v;//적
vector<point> v2;//적 temp
vector<int> gs;//궁수
int maxResult = 0;
bool flag;

void enemyTemp(){
    v.clear();
    for(int i=0; i<v2.size(); i++){
        v.push_back(v2[i]);
    }
}

int getDistance(point p, point q){
    int dis = (max(p.x,q.x)-min(p.x,q.x)) + (max(p.y,q.y)-min(p.y,q.y));
    return dis;
}

int moveEnermy(){
    int tempEnermy = 0;//죽인 적의 수
    int cnt = 0;
    for(int i=0; i<v.size(); i++){
        if(chk[i]==0){
            cnt++;
            v[i].x++;
            if(v[i].x>=n){
                cnt--;
                chk[i]=2;
            }
        }else if(chk[i]==1){
            tempEnermy++;
        }else if(chk[i]==3){
            chk[i]=1;
            tempEnermy++;
        }
    }
    if(cnt==0) flag = true;
   return tempEnermy; 
}

void choiceKillEnermy(int x){
    //x = 골라진 0-m중에서의 궁수 위치
    //전체 적들 보면서 죽일 적 하나 골라서 chk true로 바꿈
    point p = {n,x};
    int resultDistance = 987987;
    int resultY = 987987;
    int resultIdx = 299;

    for(int i=0; i<v.size(); i++){
        if(chk[i]==0 || chk[i]==3){
            int tempDistance = getDistance(p,v[i]);
            if(tempDistance<=d){
                if(tempDistance<resultDistance || (tempDistance==resultDistance && v[i].y<resultY)){
                    resultDistance = tempDistance;
                    resultY = v[i].y;
                    resultIdx = i;
                }
            }
        }
    }

    chk[resultIdx] = 3;
}


void choice(int x, int k){
    //궁수 3개 고른다.
    if(x==3){
        memset(chk,0,sizeof(chk));
        enemyTemp();
        flag = false;

        while(flag==false){
            for(int i=0; i<3; i++){
                choiceKillEnermy(gs[i]);
            }
            int temp = moveEnermy();
            if(maxResult<temp) maxResult = temp;
        }

    }else{
        for(int i=k; i<m; i++){
            gs.push_back(i);
            choice(x+1,i+1);
            gs.pop_back();
        }
    }
}

int main(){
    cin>>n>>m>>d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                point p = {i,j};
                v.push_back(p);
                v2.push_back(p);
            }
        }
    }

    choice(0,0);
    cout<<maxResult;

    return 0;
}