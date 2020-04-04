/*
https://www.acmicpc.net/problem/1062
*/

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
int n,m;
string arr[50];
bool chk[26];
int result;

void choice(int x, int k){
    if(x == m){
        int temp = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<arr[i].size(); j++){
                int Idx = arr[i][j]-'a';
                if(chk[Idx]==false) break;
                if(j==arr[i].size()-1) temp++;
            }
        }
        if(temp>result) result = temp;
    }else{
        for(int i=k; i<26; i++){
            if(chk[i]==false){
                chk[i] = true;
                choice(x+1,i+1);
                chk[i] = false;
            }
        }
    }
}

int main(){
    cin>>n>>m;

    if(m<5){
        cout<<0;
    }else if(m==26){
        cout<<n;
    }else{
        int cntAnta = 0;
        for(int i=0; i<n; i++){
            string s; cin>>s;
            if(s.compare("antatica")==0){
                cntAnta++;
            }else{
                for(int j=4; j<s.size()-4; j++){
                    arr[i]+=s[j];
                }
            }
        }
        m -= 5;
        chk['a'-'a'] = true;
        chk['c'-'a'] = true;
        chk['n'-'a'] = true;
        chk['i'-'a'] = true;
        chk['t'-'a'] = true;

        choice(0,0);
        cout<<result+cntAnta;
    }
    
    return 0;
}