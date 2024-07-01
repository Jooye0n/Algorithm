/*
https://www.acmicpc.net/problem/17141
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct point{
    int x;
    int y;
};

int n;
int k;//virus
int arr[52][52];

vector<point> v;
bool vectorChk[10];
int minNum = 987987987;
int result = -1;
int total;
queue<point> q;
queue<point> temp;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool spread(int tx){
    //virus=3 퍼트리면서 초세기
    while(q.empty() == false){
        int size = q.size();
        for(int i=0; i<size; i++){
            point cp = q.front(); q.pop();
            for(int j=0; j<4; j++){
                int nx = cp.x+dx[j];
                int ny = cp.y+dy[j];

                if(nx>=0 && ny>=0 && nx<n && ny<n){
                    if(arr[nx][ny] == 0 || arr[nx][ny] == 2){
                        arr[nx][ny] = 3;
                        tx++;
                        point p = {nx,ny};
                        q.push(p);
                    }
                }
            }
        }
        result++;
    }
    //cout<<result<<' ';

    if(tx == n*n){
        return true;
    }else{
        return false;
    }
    
}

void found(int x, int a){
    //v에서 가능성 k개 고르기
    if(x == k){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j] != 1){
                    arr[i][j] = 0;
                }
            }
        }
        
        for(int i=0; i<v.size(); i++){
            if(vectorChk[i] == true) {
                q.push(v[i]);
                arr[v[i].x][v[i].y] = 3;
            }
        }

        result = -1;
        bool chk = spread(total+q.size());

        if(minNum >result && chk == true){
            minNum = result;
        }

    }else{
        for(int i=a; i<v.size(); i++){
            if(vectorChk[i] == false){
                vectorChk[i] = true;
                found(x+1,i+1);
                vectorChk[i] = false;
            }
        }
    }
}

int main(){
    cin>>n>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 2){
                point p = {i,j};
                v.push_back(p);
            }
            if(arr[i][j]==1){
                total++;
            }
        }
    }

    found(0,0);

    if(minNum == 987987987){
        cout<<-1;
    }else{
        cout<<minNum;
    }


    return 0;
}