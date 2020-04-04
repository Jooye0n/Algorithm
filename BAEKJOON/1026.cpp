/*
https://www.acmicpc.net/problem/1026

5
1 1 1 6 0
2 7 8 3 1

18
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[101];//a 배열
int brr[101];
int result;


int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    
    for(int i=0; i<n; i++){
        cin>>brr[i];
    }

    sort(arr, arr+n);
    sort(brr, brr+n);

    for(int i=0; i<n; i++){
        result +=arr[i]*brr[n-i-1];
    }
    
    cout<<result;
    return 0;
}
