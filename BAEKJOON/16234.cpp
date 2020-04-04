/*
[ 인구이동 ]
https://www.acmicpc.net/problem/16234
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct point{
    int x;
    int y;
};

int n,L,R;
int arr[51][51];
bool chk[51][51];

bool flag = false;
int total;
int result;

queue<point> q;
queue<point> temp;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void fillArr(){
    //인구이동후 통일시키기 ->flag변형
    int size = temp.size();
    if(size<=1) {
        while(temp.empty() == false) temp.pop();
        return;
    }
    int allNum = total/size;

    while(temp.empty() == false){
        point tp = temp.front(); temp.pop();
        if(arr[tp.x][tp.y] != allNum){
            arr[tp.x][tp.y] = allNum;
            flag = true;
        }
    }
}

void BFS(){
    //인구이동
    while(q.empty() == false){
        
        point p = q.front();
        q.pop();
        total+=arr[p.x][p.y];
        temp.push(p);
        
        for(int i=0; i<4; i++){
            int nx = p.x+dx[i];
            int ny = p.y+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<n && chk[nx][ny] == false){
                int sub = max(arr[p.x][p.y],arr[nx][ny]) - min(arr[p.x][p.y],arr[nx][ny]);
                if(sub>=L && sub<=R){
                    chk[nx][ny] = true;
                    point np = {nx,ny};
                    q.push(np);
                }
            }
        }
    }
}

void move(){
    //이동했으면 ture아니면 false
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(chk[i][j] == false){
                point p = {i,j};
                chk[i][j] = true;
                q.push(p);
                total=0;
                BFS();
                fillArr();
            }
        }
    }
}

int main(){
    cin>>n>>L>>R;
    for(int i=0 ; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    while(true){
        flag = false;
        fill(&chk[0][0],&chk[50][51],false);
        move();
        if(flag == true) {
            result++;
        }
        else break;
    }
    
    cout<<result;
    return 0;
}