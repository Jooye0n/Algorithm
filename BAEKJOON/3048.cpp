/*
https://www.acmicpc.net/problem/3048
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct ant{
    char alp;
    bool group;
};

int n1, n2;
string s1;//T
string s2;//F
int T;
int N;

ant line[100];

int main(){
    cin>>n1>>n2;
    cin>>s1; 
    for(int i=n1-1; i>=0; i--){
        line[(n1-1)-i].alp = s1[i];
        line[(n1-1)-i].group = true;
    }

    cin>>s2; 
    for(int i=0; i<n2; i++){
        
        line[i+n1].alp = s2[i];
        line[i+n1].group = false;
    }

    N = n1+n2;
    cin>>T;

    while(T--){
        for(int i=0; i<N-1; i++){
            if(line[i].group == true && line[i+1].group == false){

                ant temp;

                temp.alp = line[i].alp;
                temp.group = line[i].group;

                line[i].alp = line[i+1].alp;
                line[i].group = line[i+1].group;

                line[i+1].alp = temp.alp;
                line[i+1].group = temp.group;
                i++;
            }
        }
    }

    for(int i=0; i<N; i++){
        cout<<line[i].alp;
    }
    return 0;
}