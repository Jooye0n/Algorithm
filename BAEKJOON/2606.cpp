/*
7
6
1 2
2 3
1 5
5 2
5 6
4 7
*/

#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
int n,m;
bool arr[101][101];
bool chk[101];
int cnt;

void found(int x){
    chk[x] = true;
    queue<int> q;
    q.push(x);

    while(q.empty() == false){
        int cx = q.front(); q.pop();
        for(int i=2; i<=n; i++){
            if(chk[i] == false && arr[cx][i]==true){
                cnt++;
                chk[i] = true;
                q.push(i);
            }
        }
    }
}

int main(){
    cin>>n;
    cin>>m;
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        arr[x][y] = true;
        arr[y][x] = true;
    }

    found(1);
    cout<<cnt;
    return 0;
}