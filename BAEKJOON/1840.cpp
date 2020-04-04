/*
https://www.acmicpc.net/problem/1840
*/

#include <cstdio>
#include <iostream>
#include <memory.h>

using namespace std;

int n = 9;
int arr[10][10];//스도쿠 맵
int cnt[10][10];//몇 번째 숫자인지 적는 배열

int dx[9] = {1,1,1,4,4,4,7,7,7};
int dy[9] = {1,4,7,1,4,7,1,4,7};

void printAll(){
    cout<<'\n';
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<cnt[i][j]<<' ';
        }cout<<'\n';
    }
}

int testNum(int x, int y, int num){
    //x,y에 num을 넣을 때
    //만족하면 0 return
    //만족하지 않으면 잘못된 cnt return

    //- 검사
    bool chk[10];
    for(int i=1; i<=n; i++){
        if(chk[arr[x][i]] == false) chk[arr[x][i]] = true;
        else return cnt[x][i];
    }

    //| 검사
    memset(chk,false,sizeof(chk));
    for(int i=1; i<=n; i++){
        if(chk[arr[i][y]] == false) chk[arr[i][y]] = true;
        else return cnt[i][y];
    }

    //네모검사
    memset(chk,false,sizeof(chk));
    for(int d=8; d>=0; d--){
        if(dx[d]<=x && dy[d]<=y){
            int cx = dx[d];
            int cy = dy[d];
            for(int i=cx; i<cx+3; i++){
                for(int j=cy; j<cy+3; j++){
                    if(chk[arr[i][j]] == false) chk[arr[i][j]] = true;
                    else return cnt[i][j];
                }
            }
        }
    }
    
    return 0;
}

int main(){
    int idx = 1;
    while(true){
        int x, y, num;
        cin>>x>>y>>num;

        arr[x][y] = num;
        cnt[x][y] = idx++;

        int temp = testNum(x,y,num);
        if(temp != 0){
            cout<<temp;
            //printAll();
            return 0;
        }
    }
    cout<<-1;
    return 0;
}