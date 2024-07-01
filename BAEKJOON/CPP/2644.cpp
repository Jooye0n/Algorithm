/*
https://www.acmicpc.net/problem/2644
*/

#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

bool arr[101][101];
bool chk[101];

int n,m;
int start, endY;

int found(int x){
    //촌수 찾기
    int result = 1;

    chk[x] = true;
    queue<int> q;
    q.push(x);

    while(q.empty() == false){
        int size = q.size();
        while(size--){
            int cx = q.front(); q.pop();
            
            for(int i=1; i<=n; i++){
                if(arr[cx][i] == true && chk[i] == false){
                    if(i == endY) return result;
                    chk[i] = true;
                    q.push(i);
                }
            }
        }
        result++;
    }
    
    return -1;
}

int main(){
    cin>>n;
    cin>>start>>endY;
    cin>>m;
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        arr[x][y] = true;
        arr[y][x] = true;
    }

    cout<<found(start);

    return 0;
}