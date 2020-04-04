/*
https://www.acmicpc.net/problem/11048

3 4
1 2 3 4
0 0 0 5
9 8 7 6
미로크기 1000이하
DFS의 냄새가 난다. -> 실패 DP였다.
왜냐? 미로 크기가 1000이므로...!
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int n,m;
int arr[1001][1001];

int main(){
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1; i<m; i++){
        arr[0][i] += arr[0][i-1];
    }

    for(int i=1; i<n; i++){
        arr[i][0] += arr[i-1][0];
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            arr[i][j] = max(arr[i-1][j],arr[i][j-1])+arr[i][j];
        }
    }

    cout<<arr[n-1][m-1];
    return 0;
}



