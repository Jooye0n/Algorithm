/*
https://www.acmicpc.net/problem/4920
*/

#include <cstdio>
#include <iostream>

#define MIN -987987987
using namespace std;

int map[13][2][4] = {
    {{0,0,1,1},{0,1,0,1}},//0
    {{0,0,0,0},{0,1,2,3}},//1
    {{0,1,2,3},{0,0,0,0}},//2
    {{0,0,1,1},{0,1,1,2}},//3
    {{0,1,1,2},{1,0,1,0}},//4
    {{0,0,0,1},{0,1,2,2}},//5
    {{0,1,2,2},{1,1,0,1}},//6
    {{0,1,1,1},{0,0,1,2}},//7
    {{0,0,1,2},{0,1,0,0}},//8
    {{0,0,0,1},{0,1,2,1}},//9
    {{0,1,2,1},{0,0,0,1}},//10
    {{0,1,1,1},{1,0,1,2}},//11
    {{1,0,1,2},{0,1,1,1}}//12
};
int arr[101][101];
int n;
int result;

int calcul(int x, int i, int j){
    int temp = 0;
    for(int b=0; b<4; b++){
        int nx = i+map[x][0][b];
        int ny = j+map[x][1][b];

        if(nx<0 || ny<0 || nx>=n || ny>=n) return MIN;

        temp += arr[nx][ny];
    }
    return temp;
}

void putBlock(){
    for(int x=0; x<13; x++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int temp = calcul(x,i,j);
                if(temp>result) result = temp;
            }
        }
    }
}

int main(){
    int idx = 1;
    while(true){
        cin>>n;
        if(n == 0) break;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>arr[i][j];
            }
        }

        result = MIN;
        putBlock();
        cout<<idx<<". "<<result<<'\n';//1. 120
        idx++;
    }
    return 0;
}