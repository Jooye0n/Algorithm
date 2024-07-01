/*
https://www.acmicpc.net/problem/17136
*/
#include <cstdio>
#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

struct point{
    int x;
    int y;
};

int arr[10][10];
int cnt[6] = {0,5,5,5,5,5};
bool chk[10][10];
int n=10;
int result = 100;
vector<point> v;
vector<int> maxP;

bool testPaper(int psize, int idx){
    //들어갈 수 있는지 조사
    int cx = v[idx].x;
    int cy = v[idx].y;

    for(int i=cx; i<cx+psize; i++){
        for(int j=cy; j<cy+psize; j++){
            if(i>=n || j>=n || arr[i][j]==0 || chk[i][j]==true) return false;
        }
    }

    return true;
}

void pushPaper(int psize, int idx, bool flag){
    //종이 넣기
    int cx = v[idx].x;
    int cy = v[idx].y;

    for(int i=cx; i<cx+psize; i++){
        for(int j=cy; j<cy+psize; j++){
            chk[i][j] = flag;
        }
    }
}

void DFS(int idx, int tempResult){
    //DFS로 test
    //v[i]에 가능한거 전부 넣어본다.
    if(cnt[1]<0 || cnt[2]<0 || cnt[3]<0 || cnt[4]<0 || cnt[5]<0) return;
    if(idx == v.size()){
        if(tempResult<result) result = tempResult;
        return;
    }
    if(chk[v[idx].x][v[idx].y]==true){
        DFS(idx+1,tempResult);
    }
    
    for(int i=maxP[idx]; i>0; i--){
        if(testPaper(i,idx)==true){
            pushPaper(i,idx,true);
            cnt[i]--;
            DFS(idx+1,tempResult+1);
            cnt[i]++;
            pushPaper(i,idx,false);
        }
    }
}

int main(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                point p = {i,j};
                v.push_back(p);
            }
        }
    }

    for(int i=0; i<v.size(); i++){
        for(int p=5; p>0; p--){
            if(testPaper(p,i)==true){
                maxP.push_back(p);
                break;
            }
        }
    }

    DFS(0,0);
    
    if(result != 100) cout<<result;
    else cout<<-1;

    return 0;
}