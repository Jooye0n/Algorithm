/*
https://www.acmicpc.net/problem/1021
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
#define MAX 987987987

using namespace std;

int n,k;
int arr[50];
int result = MAX;
vector<int> v;

void getNumber(int x, int cnt){
    //전체 숫자에 대하여 2, 3연산 전부 해보고 최소값 return
    if(x == k){
        if(result>cnt) result = cnt;
    }else{
        int idx;

        for(int i=0; i<v.size(); i++){
            if(v[i] == arr[x]) {
                idx = i;
                break;
            }
        }

        if(idx>v.size()-idx){
            while(v.front() != arr[x]){
                v.insert(v.begin(),v.back());
                v.pop_back();
                cnt++;
            }
            v.erase(v.begin());
            getNumber(x+1,cnt);
        }else{
            while(v.front() != arr[x]){
                v.push_back(v.front());
                v.erase(v.begin());
                cnt++;
            }
            v.erase(v.begin());
            getNumber(x+1,cnt);
            
        }
    }
}

int main(){

    cin>>n>>k;
    for(int i=1; i<=n; i++){
        v.push_back(i);
    }

    for(int i=0; i<k; i++){
        cin>>arr[i];
    }

    getNumber(0,0);

    cout<<result;
    return 0;
}