/*
https://www.acmicpc.net/problem/9372

2
3 3
1 2
2 3
1 3
5 4
2 1
2 3
4 3
4 5
*/

#include <cstdio>
#include <iostream>

using namespace std;

int T;
int n,m;

int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=0; i<m; i++){
            int a,b;
            cin>>a>>b;
        }
        cout<<n-1<<'\n';
    }
    return 0;
}
