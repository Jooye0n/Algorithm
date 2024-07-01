#include <bits/stdc++.h>
using namespace std;
int n;
int chk[10001];

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int x; scanf("%d",&x); chk[x]++;
    }
   
    for(int i=0; i<10001; i++){
        if(chk[i]==0)continue;
        for(int j=0; j<chk[i]; j++) printf("%d\n",i);
    }
    
    return 0;
}