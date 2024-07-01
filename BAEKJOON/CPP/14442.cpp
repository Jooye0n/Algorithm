/*
https://www.acmicpc.net/problem/14442
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

struct point{
    int x;
    int y;
    int num;//지금까지 문 연 수
};

int arr[1001][1001];
int chk[1001][1001][11];
int n,m,k;
int result = 987987987;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void BFS(){
    point p = {0,0,0};
    queue<point> q;
    q.push(p);
    chk[0][0][0] = 1;

    while(q.empty() == false){
        int cx = q.front().x;
        int cy = q.front().y; 
        int cn = q.front().num; q.pop();

        for(int i=0; i<4; i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            

            if(nx>=0 && ny>=0 && nx<n && ny<m){
                if(arr[nx][ny]==1 && (chk[nx][ny][cn+1]==0 || chk[nx][ny][cn+1]>chk[cx][cy][cn]+1) && cn+1<=k){
                    chk[nx][ny][cn+1] = chk[cx][cy][cn]+1;
                    point np = {nx,ny,cn+1};
                    
                    q.push(np);
                }
                if(arr[nx][ny]==0 && (chk[nx][ny][cn]==0 || chk[nx][ny][cn]>chk[cx][cy][cn]+1)){
                    chk[nx][ny][cn]=chk[cx][cy][cn]+1;
                    point np = {nx,ny,cn};
                    q.push(np);
                }
            }
        }
    }
}

void getResult(){
    for(int i=0; i<=k; i++){
        if(chk[n-1][m-1][i] != 0 && chk[n-1][m-1][i]<result){
            result = chk[n-1][m-1][i];
        }
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<s.size(); j++){
            arr[i][j] = s[j]-'0';
        }
    }

    BFS();
    getResult();

    if(result != 987987987) cout<<result;
    else cout<<-1;

    return 0;
}