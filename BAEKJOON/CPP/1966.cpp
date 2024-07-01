/*
[ 프린터 큐]
https://www.acmicpc.net/problem/1966

입력
3
1 0
5
4 2
1 2 3 4
6 0
1 1 9 1 1 1


출력
1
2
5
*/


#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n;


int main(){
    cin>>n;
    while(n--){
        int arr[101];
        int sortarr[101];

        int num, x;
        cin>>num>>x;

        for(int i=0; i<num; i++){
             cin>>arr[i];
             sortarr[i] = arr[i];
        }

        sort(sortarr, sortarr+num);//desc

        int i=0; 
        int j=num-1;

        int result = -1;

        while(result != x){
            if(sortarr[j] == arr[i]){
                result = i;
                j--;

            }
                if(i<num-1){
                    i++;
                }else{
                    i=0;
                }
            
        }

        cout<<num-j-1<<'\n';
    }

    return 0;

}