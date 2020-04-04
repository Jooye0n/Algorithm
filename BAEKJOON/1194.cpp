/*
https://www.acmicpc.net/problem/1194
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <memory.h>
#include <string>

using namespace std;
struct point{
    int x;
    int y;
    bool key[6];
};

int n,m;
queue<point> q;
int arr[51][51];
bool chk[51][51][64];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int keyTobinary(bool key[]){
    int bin=1;
    int idx=1;
    for(int i=5; i>=0; i--){
        bin +=idx*key[i];
        idx*=2;
    }
    return bin;
}

int BFS(){
    int result = 0;
    while(q.empty()==false){
        int size = q.size();
        while(size--){
            int cx = q.front().x;
            int cy = q.front().y;
            bool ckey[6];
            for(int i=0; i<6; i++){
                ckey[i] = q.front().key[i];
            }
            int cb = keyTobinary(ckey);
            q.pop();

            if(arr[cx][cy]=='1') return result;

            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && chk[nx][ny][cb]==false && arr[nx][ny] !='#'){
                    if(arr[nx][ny]>='a' && arr[nx][ny]<='f'){
                        int Idx = arr[nx][ny]-'a';
                        point np = {nx,ny,{ckey[0],ckey[1],ckey[2],ckey[3],ckey[4],ckey[5]}};
                        np.key[Idx] = true;
                        int chkIdx = keyTobinary(np.key);
                        chk[nx][ny][chkIdx] = true;
                        q.push(np);
                    }else if(arr[nx][ny]>='A' && arr[nx][ny]<='F'){
                        int Idx = arr[nx][ny]-'A';
                        if(ckey[Idx]==false){
                            continue;
                        }else{
                            chk[nx][ny][cb] = true;
                            point np = {nx,ny,{ckey[0],ckey[1],ckey[2],ckey[3],ckey[4],ckey[5]}};
                            q.push(np);
                        }
                    }else{//벽과 탈출구
                        chk[nx][ny][cb] = true;
                        point np = {nx,ny,{ckey[0],ckey[1],ckey[2],ckey[3],ckey[4],ckey[5]}};
                        q.push(np);
                    }
                }
            }
        }
        result++;
    }
    return -1;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<m; j++){
            arr[i][j] = s[j];
            if(arr[i][j]=='0'){
                point p = {i,j,{false,false,false,false,false,false}};
                chk[i][j][0] = true;
                q.push(p);
                arr[i][j] = '.';
            }
        }
    }

    cout<<BFS();
    return 0;
}