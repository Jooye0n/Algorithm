/*
https://www.acmicpc.net/problem/13458
*/

#include <cstdio>
#include <iostream>
#define MAX 1000000
using namespace std;
int n;
int arr[MAX];
int b,c;
long long result;

int main(){
    cin>>n;
    result = n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>b>>c;

    for(int i=0; i<n; i++){
        int temp = arr[i]-b;
        if(temp>0){
            int num = temp/c;
            int div = temp%c;
            if(div!=0){
                result ++;;
            }
            result +=num;
        }
    }

    cout<<result;
    return 0;
}