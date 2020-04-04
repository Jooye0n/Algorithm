/*
11403 경로찾기
*/

#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>

struct point{
    int x;
    int y;
};

using namespace std;
int n;
int arr[101][101];
int result[101][101];
queue<point> q;

int main(){
    cin>>n;
    for(int i=0 ;i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 1){
                point p = {i,j};
                result[i][j] = 1;
                q.push(p);
            }
        }
    }

    while(q.empty() == false){
        //1이면 q에 안넣고 0이면 1로 바꾼후에 q에 넣는다
        int qx = q.front().x;
        int qy = q.front().y;
        q.pop();

        for(int i=0; i<n; i++){
            if(arr[qy][i] == 1 && result[qx][i] == 0){
                point p = {qx,i};
                result[qx][i] = 1;
                q.push(p);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<result[i][j]<<' ';
        }
        cout<<'\n';
    }
    

    return 0;
}