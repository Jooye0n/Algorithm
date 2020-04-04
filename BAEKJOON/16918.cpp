/*
https://www.acmicpc.net/problem/16918
첫째 줄에 R, C, N (1 ≤ R, C, N ≤ 200)이 주어진다. 둘째 줄부터 R개의 줄에 격자판의 초기 상태가 주어진다. 빈 칸은 '.'로, 폭탄은 'O'로 주어진다.
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>

using namespace std;

struct point{
    int x;
    int y;
};

const int dx[] = {0,0,0,1,-1};
const int dy[] = {0,1,-1,0,0};

int chk[200][200];//1과 -1
char arr[200][200];
int n,m,k;//k초 후 상태 출력
int cnt = 1;
vector<point> bomb;//폭탄 모으기

void makeBomb(int x){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == '.'){
                arr[i][j] = 'O';
                chk[i][j] = x;
            }
        }
    }
}

void removeBomb(int x){
    vector<point> v;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(chk[i][j] == x && arr[i][j] == 'O'){
                point p = {i,j};
                v.push_back(p);
            }
        }
    }

    for(int i=0; i<v.size(); i++){
        int cx = v[i].x;
        int cy = v[i].y;
        for(int d=0; d<5; d++){
            int nx = cx+dx[d];
            int ny = cy+dy[d];
            if(nx>=0 && ny>=0 && nx<n && ny<m){
                arr[nx][ny] = '.';
                chk[nx][ny] = 0;
            }
        }
    }
}

void printAll(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j];
        }cout<<'\n';
    }
}

int main(){
    int idx = -1;
    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<s.size(); j++){
            arr[i][j] = s[j];//빈 칸은 '.'로, 폭탄은 'O'로 주어진다.
            chk[i][j] = 1;
        }
    }
    if(k == 1){
        printAll();
        return 0;
    }

    while(true){
        makeBomb(idx);
        cnt++;
        if(cnt == k) break;

        idx *=-1;
        removeBomb(idx);
        cnt++;
        if(cnt == k) break;
    }

    printAll();

    return 0;
}