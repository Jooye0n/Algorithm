/*
https://www.acmicpc.net/problem/16955
*/

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
char arr[10][10];
bool chk[10][10];

bool testFive(int x, int y){
    if(x+4<10){
        for(int i=1; i<=4; i++){
            if(arr[x+i][y]!='X') break;
            if(i == 4) return true;
        }
    }

    if(y+4<10){
        for(int i=1; i<=4; i++){
            if(arr[x][y+i]!='X') break;
            if(i == 4) return true;
        }
    }

    if(x+4<10 && y+4<10){
        for(int i=1; i<=4; i++){
            if(arr[x+i][y+i]!='X') break;
            if(i == 4) return true;
        }
    }

    if(x+4<10 && y-4>=0){
        for(int i=1; i<=4; i++){
            if(arr[x+i][y-i]!='X') break;
            if(i == 4) return true;
        }
    }
    return false;
}

bool testAll(){
    //x,y부터 5개면 true
    for(int i=0; i<10 ; i++){
        for(int j=0; j<10; j++){
            if(arr[i][j] == 'X'){
                if(testFive(i,j) == true) return true;
            }
        }
    }
    return false;
}
void choice(int x, int k){
    if(x == 1){
        if(testAll() == true){
            cout<<1;
            exit(0);
        }

    }else{
        for(int i=k; i<100; i++){
            int cx = i/10;
            int cy = i%10;

            if(arr[cx][cy] == '.'){
                arr[cx][cy] = 'X';
                choice(x+1,i+1);
                arr[cx][cy] = '.';
            }
        }
    }
}

int main(){
    for(int i=0; i<10; i++){
        string s; cin>>s;
        for(int j=0; j<10; j++){
            arr[i][j] = s[j];
        }
    }

    choice(0,0);
    cout<<'0';
    return 0;
}