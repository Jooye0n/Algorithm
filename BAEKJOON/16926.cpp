/*
    아래 오른쪽 위쪽 왼쪽 방향 구상
    0,0부터 1,1  2,2...벽에 닿으면 방향 바꾸기
    chk 된 곳으로 오면 1->2->3 
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {0,1,0,-1};//오 아 왼 위
int dy[4] = {1,0,-1,0};//0 1  2  3

int arr[301][301];
int n,m,r;//x,y,rotation

void arrRotation(int x){
    //x개의 그룹이 있다.
    bool chk[301][301] = {false, };

    for(register int i=0; i<x; i++){
        //겉에서부터 i 번째 그룹
        int cnt = 0;
        int cx = i;
        int cy = i;
        int dir = 0;

        int temp = arr[i][i];
    
        while(cnt<4){
            int nx = cx+dx[dir];
            int ny = cy+dy[dir];

            if(nx>=i && ny>=i && nx<n-i && ny<m-i){
                arr[cx][cy] = arr[nx][ny];
                cx = nx;
                cy = ny;

            }else{
                dir = (dir+1)%4;
                cnt++;
            }
        }

        arr[i+1][i] = temp;
    }

}

int main(){
    cin>>n>>m>>r;

    for(register int i=0; i<n; i++){
        for(register int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    int countRotation = min(n,m)/2;

    while(r--){
        arrRotation(countRotation);
    }

    for(register int i=0; i<n; i++){
        for(register int j=0; j<m; j++){
            cout<<arr[i][j]<<' ';
        }cout<<'\n';
    }

    return 0;
}




