/*
n queen
https://www.acmicpc.net/problem/9663
가로세로대각선
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[16];
int result;

bool check(int x,int k){
    //x번째 줄에 k 번째에 여왕님 가능하신가
    for(int i=0; i<x; i++){
        if(arr[i] == k) return false;
        else if(x-i == arr[i]-k) return false;
        else if(x-i == k-arr[i]) return false;
    }
    return true;
}

void found(int x){
    if(x == n){
        result++;
    }else{
        for(int i=0; i<n; i++){
            if(check(x,i) == true){
                arr[x] = i;
                found(x+1);
            }
        }
    }
}

int main(){
    cin>>n;

    found(0);
    cout<<result;

    return 0;
}