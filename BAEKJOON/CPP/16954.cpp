/*
https://www.acmicpc.net/problem/16954
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct point{
    int x;
    int y;
};

int n = 8;
char arr[8][8];

const int dx[9] = {0,-1,-1,-1,0,0,1,1,1};
const int dy[9] = {0,-1,0,1,-1,1,-1,0,1};

queue<point> q;//욱재
queue<point> wall;//벽

bool move(){
    point startP = {7,0};
    q.push(startP);

    while(true){
        //욱재이동
        bool chk[8][8] = {false, };
        int size = q.size();
        while(size--){
            int cx = q.front().x;
            int cy = q.front().y; q.pop();
            if(arr[cx][cy] == '#') continue;    
            if(cx == 0 && cy == 7) return true;

            for(int i=0; i<9; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<n && arr[nx][ny] != '#' && chk[nx][ny] == false){
                    chk[nx][ny] = true;
                    point np = {nx,ny};
                    q.push(np);
                }

            }
        }

        if(q.empty() == true) return false;

        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[i][j] = '.';
            }
        }

        //벽이동
        int wsize = wall.size();
        while(wsize--){
            int cx = wall.front().x;
            int cy = wall.front().y; wall.pop();

            int nx = cx+1;
            int ny = cy;

            if(nx<n){ 
                arr[nx][ny] = '#';
                point np = {nx,ny};
                wall.push(np);
            }
        }
    }
}

int main(){
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<n; j++){
            arr[i][j] = s[j];
            if(arr[i][j] == '#'){
                point p = {i,j};
                wall.push(p);
            }
        }
    }

    cout<<move();
    return 0;
}