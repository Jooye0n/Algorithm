/*
https://www.acmicpc.net/problem/2580
*/

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int arr[9][9];

struct point{
    int x;
    int y;
};

int dx[9] = {0,0,0,3,3,3,6,6,6};
int dy[9] = {0,3,6,0,3,6,0,3,6};

vector<point> blank;

void printAll(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<arr[i][j]<<' ';
        }cout<<'\n';
    }
}

bool isItAnswer(int cx, int cy){
    //가로 
    bool temp[10] = {0, }; 
    for(int i=0; i<9; i++){
        if(arr[i][cy] == 0) continue;
        if(temp[arr[i][cy]] == false) temp[arr[i][cy]] = true;
        else return false;
    }
    //세로
    bool temp1[10] = {0, }; 
    for(int i=0; i<9; i++){
        if(arr[cx][i] == 0) continue;
        if(temp1[arr[cx][i]] == false) temp1[arr[cx][i]] = true;
        else return false;
    }

    //사각형
    for(int i=0; i<9; i++){
        if(cx>=dx[i] && cx<dx[i]+3 && cy>=dy[i] && cy<dy[i]+3){
            bool temp2[10] = {0, };
            for(int x=dx[i]; x<dx[i]+3; x++){
                for(int y=dy[i]; y<dy[i]+3; y++){
                    if(arr[x][y] == 0) continue;
                    if(temp2[arr[x][y]] == false) temp2[arr[x][y]] = true;
                    else return false;
                }
            }
        }
    }
    return true;
}


void foundAnswer(int x){
    if(x == blank.size()){
        printAll();
        exit(0);
    }else{
        for(int i=1; i<=9; i++){
            int cx = blank[x].x;
            int cy = blank[x].y;
            arr[cx][cy] = i;
            if(isItAnswer(cx,cy) == true){
                foundAnswer(x+1);
            }
            arr[cx][cy] = 0;
        }
    }
}

int main(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 0){
                point p = {i,j};
                blank.push_back(p);
            }
        }
    }

    foundAnswer(0);
    return 0;
}