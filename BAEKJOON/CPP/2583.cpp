/*
https://www.acmicpc.net/problem/2583
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int n,m,k;
int arr[101][101];
bool chk[101][101];
int group;
int temp;
vector<int> v;

void DFS(int x, int y){
    chk[x][y] = true;
    temp++;
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(chk[nx][ny] == false && arr[nx][ny] == 0 && nx>=0 && ny>=0 && nx<m &&ny<n){
            DFS(nx,ny);
        }
    }
}


int main(){
    cin>>m>>n>>k;
    for(int i=0; i<k; i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        for(int x=a; x<c; x++){
            for(int y=b; y<d; y++){
                arr[y][x] = 1;
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(chk[i][j] == false && arr[i][j] == 0){
                temp = 0;
                DFS(i,j);
                v.push_back(temp);
                group++;
            }
        }
    }

    sort(v.begin(), v.end());
    cout<<group<<'\n';
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<' ';
    }


    return 0;
}