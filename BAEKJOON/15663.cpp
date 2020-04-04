/*
[ N과 M (9)]
https://www.acmicpc.net/problem/15663

4 2
9 7 9 1

1 7
1 9
7 1
7 9
9 1
9 7
9 9

9791
1799

6 3
1 1 1 2 2 3 중에서 2개
1 1
1 2
1 3
2 1
2 2 
2 3
3 1
3 2

3개
1 1 1
1 1 2
1 1 3
1 2 1
1 2 2
1 2 3
1 3 1
1 3 2
2 1 1
2 1 2
2 1 3
2 2 1
2 2 3
3 1 1
3 1 2
3 2 1
3 2 2
//이전 수와 같지 않으면 출력
//1로 시작해서 한번 했으면 앞으로 1로 시작 안한다. 

전체 수 n개중에 m개를 고르는데 중복은 없도록!
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
            if(chk[i] == false){
                chk[i] = true;
                v.push_back(arr[i]);

                found(x+1);

                chk[i] = false;
                v.erase(v.end()-1);
            }
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