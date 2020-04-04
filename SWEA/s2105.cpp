/*
디저트 카페
1-100정수 디저트종류

10
4  
9 8 9 8
4 6 9 4
8 7 7 8
4 5 3 5
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,T;
int arr[21][21];
bool desert[101];

int dx[4] = {1,-1,-1,1};
int dy[4] = {1,1,-1,-1};
int maxNum;

void makeRoute(int x, int y, int startx, int starty, int dir, int cnt){
    //i,j에서 시작해서 경로 탐색
    if(x == startx && y == starty && dir == 3){
        if(maxNum<cnt){
            maxNum = cnt;
        }
    }else{
        
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        
        if(nx>=0 && ny>=0 && nx<n && ny<n && desert[arr[nx][ny]] == false){
            desert[arr[nx][ny]] = true; 
            makeRoute(nx,ny,startx,starty,dir,cnt+1);
            desert[arr[nx][ny]] = false;
        }

        nx = x+dx[dir+1];
        ny = y+dy[dir+1];
        
        if(nx>=0 && ny>=0 && nx<n && ny<n && desert[arr[nx][ny]] == false ){
            desert[arr[nx][ny]] = true; 
            makeRoute(nx,ny,startx,starty,dir+1,cnt+1);
            desert[arr[nx][ny]] = false;
        }
    }
}

int main(){
    cin>>T;
    for(int t=1; t<=T; t++){
        maxNum = 0;
        cin>>n;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>arr[i][j];
            }
        }

        //각 모서리와 맨 밑줄 제외
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n; j++){
                if((i==0 && j==0) || (i==0 && j==n-1))
                    continue;
                else{
                    fill(desert, desert+101, false);
                    //cout<<"i:"<<i<<' '<<"j:"<<j<<' ';
                    makeRoute(i,j,i,j,0,0);
                }
                
            }
        }

        if(maxNum == 0) cout<<"#"<<t<<' '<<-1<<'\n';
        else cout<<"#"<<t<<' '<<maxNum<<'\n';

    }
    

    return 0;
}