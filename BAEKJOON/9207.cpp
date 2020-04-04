/*
3
###...###
..oo.....
.....oo..
.........
###...###

###...###
..oo.o...
...o.oo..
...oo....
###...###

###o..###
.o.oo....
o.o......
.o.o.....
###...###
*/

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

char arr[5][9];
char temp[5][9];

int T;

int minNum, moveTurn;

void DFS(int x, int k){

    if(x<minNum){
        minNum = x;
        moveTurn = k;
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<9; j++){
            if(arr[i][j]=='o'){

                for(int d=0; d<4; d++){
                    int cx = i+dx[d];
                    int cy = j+dy[d];

                    int nx = cx+dx[d];
                    int ny = cy+dy[d];

                    if(nx>=0 && ny>=0 && nx<9 && ny<5 && arr[cx][cy]=='o' && arr[nx][ny] == '.'){
                        arr[i][j] = '.';
                        arr[cx][cy] = '.';
                        arr[nx][ny] = 'o';

                        DFS(x-1, k+1);

                        arr[i][j] = 'o';
                        arr[cx][cy] = 'o';
                        arr[nx][ny] = '.';
                    }

                }
            }
        }
    }
}

int main(){
    cin>>T;
    while(T--){
        int cnt = 0;
        minNum = 98987987;

        for(int i=0; i<5; i++){
            string s;
            cin>>s;

            for(int j=0; j<9; j++){
                arr[i][j] = s[j];
                if(arr[i][j]=='o') cnt++;
            }
        }

        DFS(cnt,0);
        cout<<minNum<<' '<<moveTurn<<'\n';
    }
    return 0;
}