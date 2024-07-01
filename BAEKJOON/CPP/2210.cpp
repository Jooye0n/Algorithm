/*
acmicpc.net/problem/2210

1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 2 1
1 1 1 1 1

*/

#include <cstdio>
#include <iostream>
#define MAX 5

using namespace std;

int arr[6][6];//숫자판
bool temp[1000000];
int number;
int countNum;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void found(int x, int y, int c){

    number = number*10 + arr[x][y];

    if(c == 5){
        if(temp[number] == false){
            temp[number] = true;
            countNum++;
        }
    }else{
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0 && ny>=0 && nx<5 && ny<5){
                found(nx,ny,c+1);
                number/=10;
            }
        } 
    }
}

int main(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            number = 0;
            found(i,j,0);//시작점
        }
    }


    cout<<countNum;

    return 0;
}