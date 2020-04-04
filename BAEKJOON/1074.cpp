/*
https://www.acmicpc.net/problem/1074
*/

#include <cstdio>
#include <iostream>

using namespace std;

int r,c;


void recur(int x, int y, int th,int n){
    //각 구역의 처음 x,y와 몇번째인지= th 한 변 길이=n
    if(x == r && y == c) cout<<th;//아님
    else{
        int temp = n/2;//한 구역의 한변 길이 1
        int temp2 = temp*temp;// 1
        
        if(x<=r && y<=c && r<x+temp && c<y+temp) recur(x,y,th,temp);
        else if(x<=r && r<x+temp && y+temp<=c && c<y+n) recur(x,y+temp,temp2+th,temp);
        else if(x+temp<=r && r<x+n && y<=c && c<y+temp) recur(x+temp,y,temp2*2+th,temp);
        else if(x+temp<=r && y+temp<=c && r<x+n &&c<y+n) recur(x+temp,y+temp,temp2*3+th,temp);
    }
}
int main(){
    int N;
    int n = 1;

    cin>>N>>r>>c;

    for(int i=0; i<N; i++){
        n*=2;
    }

    recur(0,0,0,n);
    return 0;
}