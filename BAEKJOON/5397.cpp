/*
https://www.acmicpc.net/problem/5397
2
<<BP<A>>Cd-
ThIsIsS3Cr3t

BAPC
ThIsIsS3Cr3t
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <list>

using namespace std;

int T;

int main(){
    cin>>T;
    while(T--){
        list<char> v;
        list<char>::iterator idx = v.begin();//아무 원소도 없는 컨테이너의 begin==end
        string s, answer; cin>>s;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '<'){
                if(idx == v.begin()) continue;
                else idx--;
            }else if(s[i] == '>'){
                if(idx == v.end()) continue;
                else idx++;
            }else if(s[i] == '-'){
                if(idx == v.begin()) continue;
                v.erase((--idx)++);
            }else{
                v.insert(idx,s[i]);
            }
        }

        for (auto x : v) cout<<x;
        cout<<'\n';
    }
    return 0;
}
