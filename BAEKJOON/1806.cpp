#include <cstdio>
#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;
int n,m;
int arr[MAX];
long long total;
int result = MAX;
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>arr[i];
    int start=0,end=0;
    total += arr[start];

    while(start !=n && end != n){
        if(total<m){
            total += arr[++end];
        }else{
            int len = end-start+1;
            if(result>len) result = len;
            total -= arr[start++];
        }
    }
    result == MAX ? cout<<0 : cout<<result;
    return 0;
}