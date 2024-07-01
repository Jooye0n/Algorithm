/*
[ 그림 ]
https://www.acmicpc.net/problem/1926

6 5
1 1 0 1 1
0 1 1 0 0
0 0 0 0 0
1 0 1 1 1
0 0 1 1 1
0 0 1 1 1

4
9
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

struct point{
    int x;
    int y;
};

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int n,m;
int arr[501][501];
bool chk[501][501];
int result;
int temp;
vector<point> v;
vector<int> maxVal;


void DFS(int cx, int cy){
    chk[cx][cy] = true;
    temp++;
    for(int i=0; i<4; i++){
        int nx = cx+dx[i];
        int ny = cy+dy[i];
        if(chk[nx][ny] == false&& arr[nx][ny] == 1 && nx>=0 && nx<n && ny>=0 && ny<m){
            DFS(nx,ny);
        }
    }
}

int main(){
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 1){
                point p = {i,j};
                v.push_back(p);
            }
        }
    }

    for(int i=0; i<v.size(); i++){
        int cx = v[i].x;
        int cy = v[i].y;

        if(chk[cx][cy] == false && arr[cx][cy] == 1){
            temp = 0;
            DFS(cx,cy);
            maxVal.push_back(temp);
            result++;
        }
    }

    cout<<result<<'\n';
    if(maxVal.size() != 0)
        cout<<*max_element(maxVal.begin(), maxVal.end());
    else
        cout<<'0';
    return 0;
}