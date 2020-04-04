/*
[ 소문난 칠공주 ]
https://www.acmicpc.net/problem/1941

YYYYY
SYSYS
YYYYY
YSYYS
YYYYY

경우의 수 출력
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;
int result[7];
bool chk[26];
bool chk2[6][6];
char arr[6][6];
int num;
int flag;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


bool findWho(int x){
    //0-24 번호 주면 어떤 파인지 ('S'면 true) return
    int a = x/5;
    int b = x%5;

    if(arr[a][b] == 'S') return true;
    else return false;
}

void connectChk(int cx, int cy){
    //연결되어있으면 true 반환
    chk2[cx][cy] = true;
    for(int i=0 ;i<4; i++){
        int nx = cx+dx[i];
        int ny = cy+dy[i];
        

        if(nx>=0 && ny>=0 && nx<5 && ny<5 && chk2[nx][ny] == false){
            int tx = 5*nx+ny;
            if(chk[tx] == true){
                flag++;
                connectChk(nx,ny);
            }
        }
    }
}

void found(int x, int m, int k){
    if(x == 7){
        if(m>=4){
            fill(&chk2[0][0],&chk2[5][6],false);
            flag = 0;
            for(int i=0 ; i<25; i++){
                if(chk[i] == true){
                    connectChk(i/5,i%5);
                }  
            }
            if(flag == 6) num++;
        }
    }else{
        for(int i=k; i<25; i++){
            if(chk[i] == false){
                chk[i] = true;
                result[x] = i;

                if(findWho(i) == true) found(x+1,m+1,i+1);
                else found(x+1,m, i+1);
                
                chk[i] = false;
            }
        }
    }
}


int main(){
    for(int i=0 ;i<5;i++){
        string s;
        cin>>s;
        for(int j=0; j<5; j++){
            arr[i][j] = s[j];
        }
    }

    found(0,0,0);//25중 7개 고른 후 'S'가 4개 이상인 경우만 연결 여부 확인하여 개수세기.

    cout<<num;
    return 0;
}