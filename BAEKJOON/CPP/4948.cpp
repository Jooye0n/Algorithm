/*
베르트랑 공준
https://www.acmicpc.net/problem/4948
n을 포함하며, 한 줄로 이루어져 있다. (n ≤ 123456)
*/

#include <cstdio>
#include <iostream>
#include <memory.h>

using namespace std;
int n,cnt;
bool chk[246920];

int main(){
    while(true){
        cin>>n;
        if(n == 0) break;
        
        memset(chk,false,sizeof(chk));
        cnt = 0;
        
        chk[1] = true;

        for(int i=2; i<=n; i++){
            for(int j=2; j*i<=2*n; j++){
                if(chk[i*j] == false){
                    chk[i*j] = true;
                }
            }
        }

        for(int i=n+1; i<=2*n; i++){
            if(chk[i] == false){
                cnt++;
            }
        }

        cout<<cnt<<'\n';

    }
    return 0;
}