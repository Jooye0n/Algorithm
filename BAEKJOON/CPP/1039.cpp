/*
https://www.acmicpc.net/problem/1039
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int k;
int size;
string maxString;
vector<pair<int, int> > v;
int temp[2];
bool chk[1000001][11];

void getChoice(int x, int k){
    if(x == 2){
        v.push_back(make_pair(temp[0],temp[1]));
    }else{
        for(int i=k; i<size; i++){
            temp[x] = i;
            getChoice(x+1,i+1);
        }
    }
}

void changString(int x, string s){
    if(s[0] == 0) return;

    if(chk[stoi(s)][x] == true) return;

    if(x == k){
        if(maxString.compare(s)<0) maxString = s;
        return ;
    }

    chk[stoi(s)][x] = true;

    for(int i=0; i<v.size(); i++){

        string newString = s;
        int idx1 = v[i].first;
        int idx2 = v[i].second;

        swap(newString[idx1],newString[idx2]);
        changString(x+1,newString);
    }
}

int main(){
    string s;
    cin>>s;
    cin>>k;

    if(s.size() == 1 || ( s.size() == 2 && s[1] == '0')){
        cout<<-1;
        return 0;
    }

    size = s.size();
    getChoice(0,0);
    changString(0,s);

    cout<<maxString;
    return 0;
}