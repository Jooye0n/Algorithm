/*
https://www.acmicpc.net/problem/1697
*/

#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
bool chk[100001];
int n, k;

int BFS(){
    int result = 0;
    queue<int> q;
    chk[n] = true;
    q.push(n);

    while(q.empty()==false){
        int size = q.size();
        while(size--){
            int cx = q.front(); q.pop();
            if(cx==k) return result;
            if(cx+1<=100000 && chk[cx+1]==false){
                chk[cx+1] = true;
                q.push(cx+1);
            }

            if(cx-1>=0 && chk[cx-1]==false){
                chk[cx-1] = true;
                q.push(cx-1);
            }

            if(cx*2<=100000 && chk[cx*2]==false){
                chk[cx*2] = true;
                q.push(cx*2);
            }
        }
        result++;
    }
}
int main(){
    cin>>n>>k;
    cout<<BFS();
    return 0;
}