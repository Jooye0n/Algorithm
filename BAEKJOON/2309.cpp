/*
[ 일곱난쟁이 ]
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[9];
int result[7];
int sum = 0;
bool chk[9];

void choice(int x){
    //합이 100이 되는 7개 수를 찾는다.

    if(x == 7){
        if(sum == 100){
            for(int i=0; i<7; i++){
                cout<<result[i]<<'\n';
            }
            exit(0);
        }
    }else{
        for(int i=0; i<9; i++){
            if(chk[i] == false){
                result[x] = arr[i];
                sum+=arr[i];
                chk[i] = true;
                choice(x+1);
                sum-=arr[i];
                chk[i] = false;
            }
        }
    }

}

int main(){
    for(int i=0; i<9; i++){
        cin>>arr[i];
    }

    sort(arr, arr+9);

    choice(0);

    return 0;
}
