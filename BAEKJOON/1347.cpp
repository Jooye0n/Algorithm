/*
https://www.acmicpc.net/problem/1347
*/

#include <cstdio>
#include <iostream>
#include <memory.h>
#include <string>

using namespace std;
int arr[102][102];
int n;

int dx[4] = {1,0,-1,0};//남 동 북 서
int dy[4] = {0,1,0,-1};

int dir = 0;

int cx = 51;
int cy = 51; //현위치

int startx, starty;
int endx, endy;

void makeMaze(char x){
    if(x == 'R'){
        dir = (dir+3)%4;
    }else if(x == 'L'){
        dir = (dir+1)%4;
    }else if(x == 'F'){
        cx = cx+dx[dir];
        cy = cy+dy[dir];
        arr[cx][cy] = 0;
    }
}

void makeMin(){

    for(int i=0; i<=101; i++){
        bool flag = false;
        for(int j=0; j<=101; j++){
            if(arr[i][j] == 0){
                flag = true;
                startx = i;
                starty = j;
                break;
            } 
        }
        if(flag == true) break;
    }

    for(int i=0; i<=101; i++){
        bool flag = false;
        for(int j=0; j<=101; j++){
            if(arr[j][i] == 0){
                flag = true;
                if(startx > j) startx = j;
                if(starty > i) starty = i;
                break;
            } 
        }
        if(flag == true) break;
    }

    for(int i=101; i>=0; i--){
        bool flag = false;
        for(int j=101; j>=0; j--){
            if(arr[i][j] == 0){
                endx = i;
                endy = j;
                flag = true;
                break;
            }
        }
        if(flag == true) break;
    }

    for(int i=101; i>=0; i--){
        bool flag = false;
        for(int j=101; j>=0; j--){
            if(arr[j][i] == 0){
                if(endx < j)endx = j;
                if(endy < i)endy = i;
                flag = true;
                break;
            }
        }
        if(flag == true) break;
    }

}

void printMaze(){
    for(int i=startx; i<=endx; i++){
        for(int j=starty; j<=endy; j++){
            if(arr[i][j] == 0){
                cout<<'.';
            }else{
                cout<<'#';
            }
        }cout<<'\n';
    }
}

int main(){

    for(int i=0; i<102; i++){
        for(int j=0; j<102; j++){
            arr[i][j] = 1;
        }
    }

    arr[cx][cy] = 0;
    cin>>n;
    string s;
    cin>>s;

    for(int i=0; i<n; i++){
        makeMaze(s[i]);
    }

    makeMin();
    printMaze();
    return 0;
}