/*
https://www.acmicpc.net/problem/17837
4 4
0 0 2 0
0 0 1 0
0 0 1 2
0 2 0 0
2 1 1
3 2 3
2 2 1
4 1 2
*/

#include <cstdio>
#include <vector>
#include <iostream>
#include <memory.h>

using namespace std;

struct point{
    int x;
    int y;
    int dir;
};

int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};

int arr[12][12];
vector<point> v;//말 모음
vector<int> cnt[12][12];

int n,k;

int changeDir(int d){
    if(d == 1) return 2;
    else if(d == 2) return 1;
    else if(d == 4) return 3;
    else if(d == 3) return 4;
}

int found(int i, int cx, int cy){
    for(int j=0; j<cnt[cx][cy].size(); j++){
        if(cnt[cx][cy][j] == i) return j;
    }
}

int moveAll(){
    int result = 1;//턴의 수
    
    while(true){
        for(int i=0; i<v.size(); i++){//한 턴을 돈다. 현재 말의 번호가 i이다.
            int cx = v[i].x;
            int cy = v[i].y;
            int cd = v[i].dir;

            int nx = cx+dx[cd];
            int ny = cy+dy[cd];


            if(nx<0 || ny<0 || nx>=n || ny>=n || arr[nx][ny] == 2){
                v[i].dir = changeDir(cd);

                nx = cx+dx[v[i].dir];
                ny = cy+dy[v[i].dir];

                if(nx<0 || ny<0 || nx>=n || ny>=n || arr[nx][ny] ==2 ){
                    continue;
                }
            }

            if(arr[nx][ny] == 0){//흰
                int idx = found(i,cx,cy);
                
                for(int j=idx; j<cnt[cx][cy].size(); j++){
                    cnt[nx][ny].push_back(cnt[cx][cy][j]);
                    v[cnt[cx][cy][j]].x = nx; v[cnt[cx][cy][j]].y = ny;
                }

                if(cnt[nx][ny].size()>=4) return result;
                else{
                    cnt[cx][cy].erase(cnt[cx][cy].begin()+idx, cnt[cx][cy].end());
                }
            }else if(arr[nx][ny] == 1){//빨
                int idx = found(i,cx,cy);

                for(int j=cnt[cx][cy].size()-1; j>=idx; j--){
                    cnt[nx][ny].push_back(cnt[cx][cy][j]);
                    v[cnt[cx][cy][j]].x = nx; v[cnt[cx][cy][j]].y = ny;
                }
                if(cnt[nx][ny].size()>=4) return result;
                else{
                    cnt[cx][cy].erase(cnt[cx][cy].begin()+idx, cnt[cx][cy].end());
                }
            }
        }

        if(result>1000) return -1;
        else result++;
    }

    return result;
}

int main(){
    
    cin>>n>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<k; i++){
        point p; 
        cin>>p.x>>p.y>>p.dir;
        p.x--; p.y--;
        cnt[p.x][p.y].push_back(i);
        v.push_back(p);
    }
    
    cout<<moveAll();

    return 0;
}