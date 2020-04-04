/*
포도주 시식
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];
int result[10001];

int n;

int main(){
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    if(n==1){
        cout<<arr[0];
        return 0;
    }

    result[0] = arr[0];
    result[1] = arr[0] + arr[1];

    for(int i=2; i<n; i++){
        result[i] = max(result[i-1] , max(result[i-2]+arr[i], result[i-3]+arr[i-1]+arr[i]));
    }

    cout<<result[n-1];
    return 0;
}
