/*
https://www.acmicpc.net/problem/15665
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;
int n,m;
int arr[10];
int chk[10];
set<vector<int> > result;
vector<int> v;

void found(int x){
    if(x == m){
        result.insert(v);
    }else{
        for(int i=0 ;i <n; i++){
                v.push_back(arr[i]);

                found(x+1);

                v.erase(v.end()-1);
            
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0 ; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    found(0);
    for(auto e:result){
        for(int i=0; i<e.size(); i++){
            cout<<e[i]<<' ';
        }cout<<'\n';
    }
    
    return 0;
}