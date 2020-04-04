/*
https://www.acmicpc.net/problem/1799
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>

using namespace std;
int result,idx;
int n;
int arr[10][10];
bool chk[10][10];
bool vchk[101];
bool canDoFlag;
int mid;
vector<pair<int, int> > v[2];//홀수칸

const int dx[4] = {1,1,-1,-1};
const int dy[4] = {1,-1,1,-1};

void canDo(int x);

void printAll(){
    cout<<'\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<chk[i][j];
        }cout<<'\n';
    }
}

void chkBishop(int x, int y, int X){
    //chk에 x,y의 비숍으로 인해 놓을 수 없어진 자리 모두 true 로 바꾼다.
    queue<pair<int, int> > chkV;
    int cx = x;
    int cy = y;
    chk[cx][cy] = true;
    chkV.push(make_pair(cx,cy));
    
    for(int i=0; i<4; i++){
        while(true){
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<n){
                if(arr[nx][ny] == 1 && chk[nx][ny] == false){
                    chk[nx][ny] = true;
                    chkV.push(make_pair(nx,ny));
                }
                cx = nx;
                cy = ny;
            }else break;
        }
    }

    canDo(X+1);

    while(chkV.empty() == false){
        int cx = chkV.front().first;
        int cy = chkV.front().second; chkV.pop();
        chk[cx][cy] = false;
    }
}

void canDo(int x){
    //arr에 mid 개의 비숍을 놓을 수 있다면 true
    if(x == mid){
        canDoFlag = true;
        return;
    }else{
        for(int i=0; i<v[idx].size(); i++){
            if(vchk[i] == true) continue;
            int cx = v[idx][i].first;
            int cy = v[idx][i].second;

            if(chk[cx][cy] == false){
                vchk[i] = true;
                chkBishop(cx,cy,x);
                vchk[i] = false;
            }
        }
    }
}
int main(){
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 1){
                int id = i*n+j;
                if(id % 2 == 1) v[0].push_back(make_pair(i,j));
                else v[1].push_back(make_pair(i,j));
            }
        }
    }

    for(idx=0; idx<2; idx++){
        int endB = v[idx].size();
        int startB = 0;
        memset(chk,false,sizeof(chk));
        memset(vchk,false,sizeof(vchk));
        if(idx == 0){
            for(int j=0; j<n*n; j++){
                if(j % 2 == 0){
                    int x = j/n;
                    int y = j%n;
                    chk[x][y] = true;
                }
            }
        }else{
            for(int j=0; j<n*n; j++){
                if(j % 2 == 1){
                    int x = j/n;
                    int y = j%n;
                    chk[x][y] = true;
                }
            }
        }

        while(startB+1<endB){
            canDoFlag = false;
            mid = (startB+endB) / 2;
            canDo(0);

            if(canDoFlag == true){
                startB = mid;
            }else{
                endB = mid;
            }
        }
        result += startB;
    }

    cout<<result;
    return 0;
}

