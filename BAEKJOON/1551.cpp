/*
5 1
5,6,3,9,-1
*/
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
int n,k;
int arr[21];
int main(){
    cin>>n>>k;
    string s;
    cin>>s;
    string temp;
    int idx = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] != ','){
            temp+=s[i];
        }else{
            arr[idx++] = stoi(temp);
            temp = "";
        }
    }
    arr[idx] = stoi(temp);
    
    while(k--){
        for(int i=0; i<n-1; i++){
            arr[i] = arr[i+1]-arr[i];
        }
        n--;
    }

    for(int i=0; i<n-1; i++){
        cout<<arr[i]<<',';
    }
    cout<<arr[n-1];
    return 0;
}