/*
[ 숫자 ]
*/

#include <cstdio>
#include <iostream>

using namespace std;

long long n,m;
long long c;

int main(){
    cin>>n>>m;
    if(m<n){
        long long temp = m;
        m = n;
        n = temp;
    }else if(m==n){
        cout<<0<<'\n';
        return 0;
    }

    c = m-n-1;
    cout<<c<<'\n';
    for(long long i=n+1; i<m; i++){
        cout<<i<<' ';
    }
    return 0;
}
