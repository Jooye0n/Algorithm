/*
https://www.acmicpc.net/problem/2665
0은 검은 방, 1은 흰 방을 나타낸다.
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct point{
    int x; 
    int y;
};

int n;
int num;
int test = 50;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int arr[51][51];
int chk[51][51];//arr[i][j]까지 오는데에 최소로 부신벽 개수 적으면서 나아가자!

queue<point> q;
queue<point> temp;

void BFS(){
    //chk 배열에 몇개의 벽 깼는지 적는다.
    
    while(q.empty() == false){
        int size = q.size();
        for(int i=0; i<size; i++){
            int cx = q.front().x;
            int cy = q.front().y; q.pop();

            for(int j=0; j<4; j++){
                int nx = cx+dx[j];
                int ny = cy+dy[j];

                if(nx>=0 && ny>=0 && nx<n && ny<n){
                    if(chk[nx][ny]>chk[cx][cy]){
                        if(arr[nx][ny] == 0){
                            chk[nx][ny] = chk[cx][cy]+1;
                            point p = {nx,ny};
                            q.push(p);
                        }else if(arr[nx][ny] == 1){
                            chk[nx][ny] = chk[cx][cy];
                            point p = {nx,ny};
                            q.push(p);
                        }
                    }
                }
            }
        }
    }    
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<s.size(); j++){
            arr[i][j] = s[j]-'0';
            if(arr[i][j] == 0){
                num++;
            }
        }
    }

    fill(&chk[0][0], &chk[50][51],987987987);

    point p = {0,0};
    chk[0][0] = 0;
    q.push(p);

    BFS();

    cout<<chk[n-1][n-1];
    
    return 0;
}