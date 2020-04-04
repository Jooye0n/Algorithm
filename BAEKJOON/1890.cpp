/*
https://www.acmicpc.net/problem/1890
*/

#include <cstdio>
#include <iostream>

using namespace std;
int n;
int arr[100][100];
long long result[100][100];

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    result[0][0] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            if(arr[i][j]==0) continue;

            int d = arr[i][j];
            int cx = i+d;
            int cy = j+d;

            if(cy<n){
                result[i][cy] += result[i][j];
            }
            if(cx<n){
                result[cx][j] += result[i][j];
            }
            
        }   
    }

    cout<<result[n-1][n-1];
    return 0;
}