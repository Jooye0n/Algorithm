/*
[ 숨바꼭질3 ]
https://www.acmicpc.net/problem/13549
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100001

using namespace  std;
int n,k;//100,000
int arr[MAX] = {987987987, };
queue<int> q;

int main(){
    cin>>n>>k;
    fill(arr,arr+MAX,987987987);
    arr[n] = 0;
    q.push(n);

    while(q.empty() == false){
        int temp = q.front(); q.pop();
        if(temp == k){
            cout<<arr[temp];
            return 0;
        }

        if(temp+1<MAX && arr[temp+1]>arr[temp]+1){
            arr[temp+1] = arr[temp]+1;
            q.push(temp+1);
        }

        if(temp-1>=0 && arr[temp-1]>arr[temp]+1){
            arr[temp-1] = arr[temp]+1;
            q.push(temp-1);
        }

        if(temp*2<MAX && arr[temp*2]>arr[temp]){
            arr[temp*2] = arr[temp];
            q.push(temp*2);
        }
    }
    return 0;
}
