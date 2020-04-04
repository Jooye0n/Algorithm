/*
6
1 0 2 3 3 4
1 1 1 1 1 1
0 0 1 1 1 1
3 9 9 0 1 99
9 11 3 1 0 3
12 3 0 0 0 1
*/

#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int arr[12][12];
bool chk[12][12];
int n;
int result;
int pay=987987987;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool chkFlower(int x, int y){
    //심을 수 있는지 chk
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<=0 || ny<=0 || nx>n || ny>n || chk[nx][ny] == true) return false;
    }
    return true;
}

int selectFlower(int x, int y, bool val){
    //꽃 심기
    int temp = arr[x][y];
    chk[x][y] = val;
    
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        chk[nx][ny] = val;
        temp+=arr[nx][ny];
    }

    return temp;
}

void choice(int x){
    //3개 꽃밭의 중심 고르기
    if(x == 3){
        if(pay>result){
            pay = result;
        }

    }else{
        for(int i=1; i<=n*n; i++){
            int cx = i%n;
            int cy = i/n;

            if(chkFlower(cx,cy) == true){
                result+=selectFlower(cx,cy,true);
                choice(x+1);
                result-=selectFlower(cx,cy,false);
            }
        }
    }
}

int main(){
    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    choice(0);
    cout<<pay;
    return 0;
}