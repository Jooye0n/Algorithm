/*
[ 암호 만들기 ]
https://www.acmicpc.net/problem/1759

4 6
a t c i s w
a c i s t w
acis
acit
aciw
acst
acsw
actw
aist
aisw
aitw
astw
cist
cisw
citw
istw
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
char arr[20];
char result[20];
int alp[5] = {'a','e','i','o','u'};

void make(int x, int k){
    if(x == n){
        int chk = 0;
        int chk2 = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<5; j++){
                if(alp[j] == result[i])
                    chk++;
            }
        }
        chk2 = n-chk;

        if(chk>=1 && chk2>=2){
            for(int i=0; i<n; i++){
                cout<<result[i];
            }
            printf("\n");
        }

    }else{
        for(int i=k; i<m; i++){
                result[x] = arr[i];
                make(x+1, i+1);
            
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0 ;i<m; i++){
        cin>>arr[i];
    }

    sort(arr,arr+m);
    make(0,0);

    return 0;
}