/*
[ 쇠막대기 ]
https://www.acmicpc.net/problem/10799


*/

#include <cstdio>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string s;
stack<char> stk;
int result;

int main(){
    cin>>s;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '('){
            stk.push(s[i]);

        }else if(s[i] == ')'){
            if(stk.empty() == false){
                stk.pop();
                if(s[i-1] == '('){
                    result+=stk.size();
                }else if(s[i-1] == ')'){
                    result+=1;
                }
            }else break;

        }
    }

    cout<<result;

    return 0;
}
