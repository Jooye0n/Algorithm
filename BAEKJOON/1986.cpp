/*
https://www.acmicpc.net/problem/1986
*/


#include <cstdio>
#include <iostream>

using namespace std;

bool chk[1001][1001];
int arr[1001][1001];
int n,m;
int result;

int dx[8] = {2,2,1,1,-2,-2,-1,-1};
int dy[8] = {1,-1,2,-2,1,-1,2,-2};

void findUnSafe(int x, int y, int val){
    switch(val){
        case 1://Q
        for(int i=x-1; i>=1; i--) 
            if(arr[i][y]==0) chk[i][y] = true;
            else break;

        for(int i=x+1; i<=n; i++) 
            if(arr[i][y]==0) chk[i][y] = true;
            else break;
        
        for(int i=y-1; i>=1; i--){
            if(arr[x][i]==0) chk[x][i] = true;
            else break;
        }

        for(int i=y+1; i<=m; i++){
            if(arr[x][i]==0) chk[x][i] = true;
            else break;
        }

        for(int i=1; i<1001; i++){
            if(x+i<=n && y+i<=m && arr[x+i][y+i]==0) chk[x+i][y+i] = true;
            else break;
        }

        for(int i=1; i<1001; i++){
            if(x-i>0 && y-i>0 && arr[x-i][y-i]==0) chk[x-i][y-i] = true;
            else break;
        }

        for(int i=1; i<1001; i++){
            if(x+i<=n && y-i>0 && arr[x+i][y-i]==0) chk[x+i][y-i] = true;
            else break;
        }

        for(int i=1; i<1001; i++){
            if(x-i>0 && y+i<=m && arr[x-i][y+i]==0) chk[x-i][y+i] = true;
            else break;
        }
        break;

        case 2:
        for(int i=0; i<8; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>0 && ny>0 && nx<=n && ny<=m) chk[nx][ny] = true;
        }
        break;

        case 3:
        chk[x][y] = true;
        break;
    }

}

void countSafe(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(chk[i][j] == false) result++;
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=3; i++){
        int num;
        cin>>num;
        for(int j=0; j<num; j++){
            int x, y;
            cin>>x>>y;
            arr[x][y] = i;
            chk[x][y] = true;
        }
    }


    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i][j] != 0){
                findUnSafe(i,j,arr[i][j]);
            }
        }
    }
    
    countSafe();
    cout<<result;
    return 0;
}