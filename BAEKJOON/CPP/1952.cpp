/*
달팽이2
https://www.acmicpc.net/problem/1952
*/

#include <cstdio>
#include <iostream>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int arr[101][101];
bool chk[101][101];

int m,n;

int main(){
    cin>>m>>n;//m이 x

    int cx = 0;
    int cy = 0;
    int num = n*m;

    int c = 0;
    int dir = 0;

    while(true){

        chk[cx][cy] = true;
        arr[cx][cy] = num;

        if(num == 1) break;

        int nx = cx + dx[dir];
        int ny = cy + dy[dir];

        if(nx>=0 && ny>=0 && nx<m && ny<n && chk[nx][ny] == false){
            cx = nx;
            cy = ny;
            num--;
        }else{
            dir = (dir+1)%4;
            c++;
        }
    }

    cout<<c;
    return 0;
}