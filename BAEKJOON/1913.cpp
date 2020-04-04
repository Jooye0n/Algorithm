/*
달팽이
https://www.acmicpc.net/problem/1913
*/


#include <cstdio>
#include <iostream>
#include <vector>


using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int arr[1000][1000];
bool chk[1000][1000];
int n;
int dir;

int what;

int main(){

    cin>>n;
    cin>>what;

    int cx = 0;
    int cy = 0;
    int num = n*n;
    

    while(true){
        chk[cx][cy] = true;
        arr[cx][cy] = num;
        //반복을 하되 마지막꺼 적었으면 이제 나가라.
        if(num == 1) break;
        //마지막께 아니면 다음꺼로
        else{
            int nx = cx+dx[dir];
            int ny = cy+dy[dir];

            if(nx>=0 && ny>=0 && nx<n && ny<n && chk[nx][ny] == false){
                cx = nx;
                cy = ny;
                num--;
            }else{
                dir = (dir+1)%4;
            }
        }
    }

    int a,b;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<' ';
            if(arr[i][j] == what){
                a = i; b = j;
            }
        }
        cout<<'\n';
    }
    cout<<a+1<<' '<<b+1;


    return 0;
}