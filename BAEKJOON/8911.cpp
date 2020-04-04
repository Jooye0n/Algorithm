/*
https://www.acmicpc.net/problem/8911
*/

#include <cstdio>
#include <iostream>
#include <memory.h>
#include <string>
#define MAX 1001

using namespace std;
int arr[1001][1001];
int T;
int cx, cy, cd;
int minX, minY, maxX, maxY;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

void move(char c){
    if(c == 'F'){
        cx = cx+dx[cd];
        cy = cy+dy[cd];
        if(cx>maxX) maxX = cx;
        if(cy>maxY) maxY = cy;
        if(cx<minX) minX = cx;
        if(cy<minY) minY = cy;
    }else if(c == 'B'){
        cx = cx-dx[cd];
        cy = cy-dy[cd];
        if(cx>maxX) maxX = cx;
        if(cy>maxY) maxY = cy;
        if(cx<minX) minX = cx;
        if(cy<minY) minY = cy;
    }else if(c == 'R'){
        cd = (cd + 3)%4;
    }else if(c == 'L'){
        cd = (cd + 1)%4;
    }
}

int main(){
    cin>>T;
    while(T--){
        minX = 500;
        minY = 500;
        maxX = 500;
        maxY = 500;
        cx = 500;
        cy = 500;

        string s; cin>>s;
        for(int i=0; i<s.size(); i++){
            move(s[i]);
        }

        cout<<(maxX-minX) * (maxY-minY)<<'\n';
    }

    return 0;
}