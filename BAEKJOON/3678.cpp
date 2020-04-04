/*
https://www.acmicpc.net/problem/5014
*/

#include <cstdio>
#include <iostream>

using namespace std;

int f,s,g,u,d;

void DFS(int x, int cnt){
    if(x == g){
        cout<<cnt;
    }else{
        if(x+u<=f) DFS(x+u,cnt+1);
        if(x-d>=0) DFS(x-d,cnt+1);
    }
}

int main(){
    cin>>f>>s>>g>>u>>d;
    DFS(s,0);

    return 0;
}