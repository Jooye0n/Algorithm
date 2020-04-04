#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
string s;
string result;

void DFS(int x, string ans){
    if(x==-1){
        return;
    }

    ans[x] = '7';
    if(ans.compare(s)<=0){
        if(stoi(s)-stoi(result) > stoi(s)-stoi(ans)) result = ans;
    }
    DFS(x-1,ans);

    ans[x] = '4';
    if(ans.compare(s)<=0){
        if(stoi(s)-stoi(result) > stoi(s)-stoi(ans)) result = ans;
    }
    DFS(x-1,ans);
    
}
int main(){
    string ans; ans+='7';
    cin>>s;
    if(s.size()==1) result+='0';
    for(int i=1; i<s.size(); i++){
        ans+='7';
        result+='7';
    }
    DFS(s.size()-1,ans);
    cout<<result;
    
    return 0;
}