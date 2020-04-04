/*
https://www.acmicpc.net/problem/11724
*/

#include <cstdio>
#include <iostream>

using namespace std;

bool arr[1001][1001];
bool chk[1001];
int n,m;//정점수, 간선수
int result;

void foundComponent(int x){
    chk[x] = true;

    for(int i=1; i<=n; i++){
        if(arr[x][i] == true && chk[i] == false)
            foundComponent(i);
    }

}

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        arr[x][y] = true;
        arr[y][x] = true;
    }

    for(int i=1; i<=n; i++){
        if(chk[i] == false){
            result++;
            foundComponent(i);
        }
    }

    cout<<result;
    return 0;
}