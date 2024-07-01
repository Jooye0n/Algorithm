#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int n,m;
int arr[10001];
long long total;
int result;
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>arr[i];
    int start=0, end=0;
    total = arr[start];

    while(start != n && end != n){
        if(total<m){
            total+=arr[++end];
        }else{
            if(total == m) result++;
            total-=arr[start++];
        }
    }
    cout<<result;
    return 0;
}