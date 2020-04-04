/*
https://www.acmicpc.net/problem/2161
*/

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int n;//1000
vector<int> v;
vector<int> temp;
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        v.push_back(i);
    }

    while(v.size()>1){
        temp.push_back(v.front());
        v.erase(v.begin());
        v.push_back(v.front());
        v.erase(v.begin());
    }

    for(int i=0; i<temp.size(); i++){
        cout<<temp[i]<<' ';
    }
    cout<<v.front();
    return 0;
}