/*
https://www.acmicpc.net/problem/15684
*/

#include <cstdio>
#include <iostream>
#include <memory.h>

using namespace std;

bool arr[13][33];
int n,m,h;
int result = -1;
int finishLine;

bool testAll(){
    //전체 사다리 타면서 i번째 i로 가는지 보기
    for(int i=1; i<=m; i++){//m개의 세로줄

        int cul = i;//세로줄
        int row = 1;//가로줄

        while(true){
            if(arr[cul][row] == true) cul++;
            else if(arr[cul-1][row] == true) cul--;

            row++;

            if(row == n+1){
                if(cul == i) break;
                else return false;
            }
        }
    }
    return true;
}


void DFS(int x, int k){
    //x번째 사다리 추가

    if(x == finishLine){
        if(testAll()==true){
            result = finishLine;
        }
        return;
    }else{
        //현재 arr에서 1개 긋는다.
        for(int j=k; j<=n; j++){//가로선
            for(int i=1; i<=m-1; i++){//세로선

                if(arr[i+1][j] == true) { i+=2; continue; }
                if(arr[i][j] == true) { i++; continue; }
                if(arr[i-1][j] == true) { continue; }
                
                arr[i][j] = true;
                DFS(x+1,j);
                arr[i][j] = false;
                
            }
        }
    }
}

int main(){
    cin>>m>>h>>n;
    for(int i=0; i<h; i++){
        int a, b;
        cin>>a>>b;
        arr[b][a] = true;
    }

    for(int i=0; i<=3; i++){
        finishLine = i;
        DFS(0,0);
        if(result != -1) break;
    }

    cout<<result;

    return 0;
}