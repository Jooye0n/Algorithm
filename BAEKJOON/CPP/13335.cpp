/*
[ 트럭 ]
https://www.acmicpc.net/problem/13335
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,w,L;
vector<pair<int, int> > v;
int total;//다리 위의 트럭 무게 합
int result;//초
int current;//현재 넣을 트럭 idx(아직 안들어감)
int fin;//나온트럭개수

int main(){

    cin>>n>>w>>L;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(make_pair(temp,0));
    }

    while(fin < n){
        result++;
        //cout<<result<<' '<<current<<'\n';

        if(v[fin].second >= w){//뺄거빼고
            total-=v[fin].first;
            fin++;
        }

        if(current<n && total+v[current].first <= L){//넣을꺼 넣고
            total+=v[current].first;
            current++;
        }

        for(int i=fin; i<current; i++){
            v[i].second++;
        }
    }

    cout<<result;


    return 0;
}