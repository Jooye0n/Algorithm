/*
[ 공 ]
https://www.acmicpc.net/problem/1547
4
3 1
2 3
3 1
3 2
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int n;
bool arr[4];

int main(){
    cin>>n;
    arr[1] = true;
    for(int i=0 ;i<n; i++){
        int a,b;
        cin>>a>>b;
        swap(arr[a],arr[b]);
    }

    for(int i=1 ;i<=3; i++){
        if(arr[i] == true){
            cout<<i;
        }
    }
    return 0;
}