/*
https://www.acmicpc.net/problem/1443
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
int D,P;
int maxNum = -1;
set<int> s[31];

int getSize(int result){
    string s = to_string(result);
    return s.size();
}

void calcul(int result, int cnt){
    if(getSize(result) > D) return;
    if(s[cnt].count(result) > 0) return;
    
    if(cnt == P){
        if(result > maxNum) maxNum = result;
        return ;
    }

    s[cnt].insert(result);

    for(int i=2; i<=9; i++){
        calcul(result*i,cnt+1);
    }
}

int main(){
    cin>>D>>P;
    calcul(1,0);
    cout<<maxNum;
    return 0;
}