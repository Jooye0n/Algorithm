/*
https://www.acmicpc.net/problem/1987
*/

#include <cstdio>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>

using namespace std;

struct point{
    int x;
    int y;
    bool flag[26];
};

int n,m;
int maxNum;
char arr[21][21];

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

void findMax(int x, point p){
    
    if(x>maxNum){
        maxNum = x;
    }

    for(int i=0; i<4; i++){
        int nx = p.x + dx[i];
        int ny = p.y + dy[i];

        if(nx>=0 && ny>=0 && nx<n && ny<m && p.flag[arr[nx][ny]-'A'] == false){
            point np; np.x = nx; np.y = ny;
            memcpy(np.flag,p.flag,sizeof(p.flag));
            np.flag[arr[nx][ny]-'A'] = true;
            findMax(x+1,np);
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<m; j++){
            arr[i][j] = s[j];
        }
    }

    point p; p.x = 0; p.y = 0;
    p.flag[arr[0][0]-'A'] = true;
    findMax(1,p);

    cout<<maxNum;
    return 0;
}