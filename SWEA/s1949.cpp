/*
등산로 조성

10        
5 1       
9 3 2 3 2 
6 3 1 7 5
3 4 8 9 9
2 3 7 7 7
7 6 5 5 8
*/

#include <cstdio>
#include <iostream>
#include <memory.h>
#include <algorithm>


using namespace std;
int n,k,T;
int result;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int arr[8][8];
bool chk[8][8];

void found(int x, int y, bool flag, int cnt){
    if(cnt > result){
        result = cnt;
    }

    chk[x][y] = true;

    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0 && ny>=0 && nx<n && ny<n && chk[nx][ny] == false){
            if(arr[nx][ny]< arr[x][y]){//안깎아도된다
                found(nx,ny,flag,cnt+1);
            }        
        
            if(flag == false && arr[nx][ny]>=arr[x][y] && arr[nx][ny] - arr[x][y] + 1 <= k){//처음깎기
                int temp  = arr[nx][ny] - arr[x][y];
                arr[nx][ny]-= (temp + 1);
                found(nx,ny,true,cnt+1);
                arr[nx][ny]+= (temp + 1);
            }
        }
    }
    
    chk[x][y] = false;

}
int main(){
    cin>>T;
    for(int t=1; t<=T; t++){
        cin>>n>>k;
        int maxNum=0;
        result = 1;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>arr[i][j];
                if(maxNum<arr[i][j]){
                    maxNum = arr[i][j];
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j] == maxNum){
                    memset(chk,false, sizeof(chk));
                    found(i,j,false,1);
                }
            }
        }

        cout<<"#"<<t<<' '<<result<<'\n';
        // for(int i=0; i<n;i++){
        //     for(int j=0; j<n; j++){
        //         cout<<arr[i][j]<<' ';
        //     }cout<<'\n';
        // }

    }

    return 0;
}
