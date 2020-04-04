/*
기준점 (x, y)와 경계의 길이 d1, d2를 정한다. (d1, d2 ≥ 1, 1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N)
다음 칸은 경계선이다.
(x, y), (x+1, y-1), ..., (x+d1, y-d1)
(x, y), (x+1, y+1), ..., (x+d2, y+d2)
(x+d1, y-d1), (x+d1+1, y-d1+1), ... (x+d1+d2, y-d1+d2)
(x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)
경계선과 경계선의 안에 포함되어있는 5번 선거구이다.
5번 선거구에 포함되지 않은 구역 (r, c)의 선거구 번호는 다음 기준을 따른다.
1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y
2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N
3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
4번 선거구: x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int arr[21][21];//인구 수
int group[21][21];//그룹
int sum[6];
int n;
int result = 987987987;

void makeFive(int x, int y, int d1, int d2){
    for(int i=0; i<=d1; i++){
        int nx = x+i;
        int ny = y-i;
        if(nx>0 && ny>0 && nx<=n && ny<=n){
            while(ny<=n){
                group[nx][ny]=5;
                ny++;
            }
        }
    }

    for(int i=0; i<=d2; i++){
        int nx = x+d1+i;
        int ny = y-d1+i;
        if(nx>0 && ny>0 && nx<=n && ny<=n){
            while(ny<=n){
                group[nx][ny]=5;
                ny++;
            }
        }
    }

    for(int i=0; i<=d2; i++){
        int nx = x+i;
        int ny = y+i;
        if(nx>0 && ny>0 && nx<=n && ny<=n){
            while(ny<=n){
                ny++;
                group[nx][ny]=0;
            }
        }
    }

    for(int i=0; i<=d1; i++){
        int nx = x+d2+i;
        int ny = y+d2-i;
        if(nx>0 && ny>0 && nx<=n && ny<=n){
            while(ny<=n){
                ny++;
                group[nx][ny]=0;
            }
        }
    }
}

void getGroupNum(int x, int y, int d1, int d2){

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){//d1 d2 1 1    x y 0 1
            if(i<x+d1 && j<=y && group[i][j] !=5){//(x, y), (x+1, y-1), ..., (x+d1, y-d1)
                sum[1]+=arr[i][j];
            }else if(i<=x+d2 && j>y && group[i][j] !=5){//(x, y), (x+1, y+1), ..., (x+d2, y+d2)
                sum[2]+=arr[i][j];
            }else if(i>=x+d1 && j<y-d1+d2 && group[i][j] !=5){//(x+d1, y-d1), (x+d1+1, y-d1+1), ... (x+d1+d2, y-d1+d2)
                sum[3]+=arr[i][j];
            }else if(i>x+d2 && j>=y-d1+d2 && group[i][j] !=5){//(x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)
                sum[4]+=arr[i][j];
            }else{
                sum[5]+=arr[i][j];
            }
        }
    }

    int temp = *max_element(sum+1,sum+6)-*min_element(sum+1,sum+6);
    if(temp<result) result = temp;

}

void makeBound(int d1, int d2){
    //x와 y정한다.
    for(int i=1; i<=n-(d1+d2); i++){
        for(int j=d1+1; j<=n-d2; j++){//d1 d2 1 1    x y 0 1
            memset(sum,0,sizeof(sum));
            memset(group,0,sizeof(group));

            makeFive(i,j,d1,d2);
            getGroupNum(i,j,d1,d2);
        }
    }
    
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1; i<=n-2; i++){
        for(int j=1; i+j<=n-1; j++){
            makeBound(i,j);//d1과 d2정하기
        }
    }

    cout<<result;
    return 0;
}