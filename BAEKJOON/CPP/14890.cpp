/*
[ 경사로 ]
https://www.acmicpc.net/problem/14890


//똑같은 수의 개수(x)를 센다 -> 1크거나 1작은 수(m)가 나오면 x보다 l이 작으면 탈락 크면 성공->x리셋 후 m의 개수를 센다.

6 2
3 3 3 3 3 3
2 3 3 3 3 3
2 2 2 3 2 3
1 1 1 2 2 2
1 1 1 3 3 1
1 1 2 3 3 2

3
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int n,l;
int result;
int arr[101][101];

int main(){
    cin>>n>>l;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    /*
    못가는조건
    1. 1 이상 차이날 때
    2. 1 커지는데, l보다 num이 작을 때
    3. 1 작아지는데, (1작은수의 개수 num)l보다 num이 작을 때
    */

    for(int i=0; i<n; i++){
        int num = 1;
        bool flag = true;
        int temp = arr[i][0];
        for(int j=1; j<n; j++){
            if(arr[i][j] == temp) num++;
            else{
                if(arr[i][j]>temp+1 || arr[i][j]<temp-1){
                    flag = false;
                    break;
                }else if(arr[i][j] == temp+1){
                    if(l>num){
                        flag = false;
                        break;
                    }else{
                        temp = arr[i][j];
                        num=1;
                    }
                }else if(arr[i][j] == temp-1){
                    if(n-j<l){
                        flag = false;
                        break;
                    }else{
                        num = 0;
                        for(int k=j; k<j+l; k++){
                            if(arr[i][k] == temp-1) num++;
                            else{
                                flag = false;
                                break;
                            }
                        }
                        if(num == l){
                            
                            j = j+l-1;
                            temp = arr[i][j];
                            num=0;
                        }

                    }
                }
            }
        }

        if(flag == true) {
            result++;
        }
    }

    for(int j=0; j<n; j++){
        int num = 1;
        bool flag = true;
        int temp = arr[0][j];
        for(int i=1; i<n; i++){
            if(arr[i][j] == temp) num++;
            else{
                if(arr[i][j]>temp+1 || arr[i][j]<temp-1){
                    flag = false;
                    break;
                }else if(arr[i][j] == temp+1){
                    if(l>num){
                        flag = false;
                        break;
                    }else{
                        temp = arr[i][j];
                        num = 1;
                    }
                }else if(arr[i][j] == temp-1){
                    if(n-i<l){
                        flag = false;
                        break;
                    }else{
                        num = 0;
                        for(int k=i; k<i+l; k++){
                            if(arr[k][j] == temp-1) num++;
                            else{
                                flag = false;
                                break;
                            }
                        }
                        if(num == l){
                            
                            i = i+l-1;
                            temp = arr[i][j];
                            num =0;
                        }
                    }
                }
            }
        }

        if(flag == true) result++;
    }

    cout<<result;
    return 0;
}