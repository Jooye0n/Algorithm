/*
6 6
0 0 0 1 0 0
0 0 0 2 1 0
0 0 2 0 0 0
0 1 0 0 0 0
2 0 0 0 0 0
0 0 0 0 0 0
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001][1001];
int n,m;
int result;

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];

            if(arr[i][j] == 0){
                arr[i][j] = min(min(arr[i][j-1],arr[i-1][j]),arr[i-1][j-1]) + 1;
            }else{
                arr[i][j] = 0;
            }

            if(result<arr[i][j]) result = arr[i][j];
        }
    }

    cout<<result;
    return 0;
}