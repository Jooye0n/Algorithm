/*
https://www.acmicpc.net/problem/3085

5
YCPZY
CYZZP
CCPPP
YCYZC
CPPZZ
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct point{
    int x;
    int y;
};

int n;
int arr[51][51];
int result = 1;

void countNumber(){
    //x, y에서부터 연속 부분 개수 찾기
    int cnt;

    for(int i=0; i<n; i++){
        int cnt = 1;
        for(int j=0; j<n-1; j++){
            if(arr[i][j]==arr[i][j+1]){
                cnt++;
            }else{
                result = max(result,cnt);
                cnt=1;
            }
            result = max(result,cnt);
        }
    }

    for(int i=0; i<n; i++){
        int cnt = 1;
        for(int j=0; j<n-1; j++){
            if(arr[j][i]==arr[j+1][i]){
                cnt++;
            }else{
                result = max(result,cnt);
                cnt=1;
            }
            result = max(result,cnt);
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<s.size(); j++){
            arr[i][j] = s[j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(arr[i][j] != arr[i][j+1]){
                swap(arr[i][j],arr[i][j+1]);
                countNumber();
                swap(arr[i][j],arr[i][j+1]);
            }

            if(arr[j][i] != arr[j+1][i]){
                swap(arr[j][i],arr[j+1][i]);
                countNumber();
                swap(arr[j][i],arr[j+1][i]);
            }
        }
    }

    cout<<result;

    return 0;
}
