/*
https://www.acmicpc.net/problem/16986
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10][10];//상성 정보
bool chk[10];//지우의 손동작 방문chk
int kh[21];//경희
int mh[21];//민호
int jw[21];//지우
bool flag;//이길 수있는가
int n,k;

int canWin(int cnt2, int cnt3, int m, int notPart){//x번째 결과m
    //1 지우승 2 경희승 3 민호승
    int tempWin;
    if(notPart == 1){
        if(arr[kh[cnt2]][mh[cnt3]] == 2 ) tempWin =  2;
        else tempWin = 3;
    }else if(notPart == 2){
        if(arr[m][mh[cnt3]] == 2 ) tempWin = 1;
        else tempWin = 3;
    }else if(notPart == 3){
        if(arr[m][kh[cnt2]] == 2 ) tempWin = 1;
        else tempWin = 2;
    }
    return tempWin;
}

// void printAll(){
//     for(int i=1; i<=n; i++){
//         cout<<jw[i]<<' ';
//     }cout<<'\n';
// }

void fight(int cnt1, int cnt2, int cnt3, int jwCnt, int khCnt, int mhCnt, int notPart){
     
    if(khCnt>=k || mhCnt>=k) return;
    if(jwCnt>=k){//이긴 경우
        flag = true;
        // printAll();
        // printf("cnt: %d %d %d / win: %d %d %d\n", cnt1,cnt2,cnt3,jwCnt,khCnt,mhCnt);
        return;
    }

    if(max(cnt2,cnt3) > 20 || cnt1>n ) return;//20회 넘은 경우

    if(notPart == 1){
        int tempNotPart;
        int temp = canWin(cnt2,cnt3,0,notPart);
        for(int i=1; i<=3; i++){
            if(i != temp && i != notPart){ tempNotPart = i; break; }
        }
        if(temp == 2) fight(cnt1,cnt2+1,cnt3+1,jwCnt,khCnt+1,mhCnt,tempNotPart);
        else if(temp == 3) fight(cnt1,cnt2+1,cnt3+1,jwCnt,khCnt,mhCnt+1,tempNotPart);
    }else{
        int tempNotPart;

        for(int i=1; i<=n; i++){
            if(chk[i] == false){
                chk[i] = true;
                jw[cnt1] = i;
                int temp2 = canWin(cnt2,cnt3,i,notPart);//x번째에 지우가 i냄
                for(int j=1; j<=3; j++){
                    if(j != temp2 && j != notPart){ tempNotPart = j; break; }
                }
                if(notPart == 2){
                    if(temp2 == 1) fight(cnt1+1,cnt2,cnt3+1,jwCnt+1,khCnt,mhCnt,tempNotPart);
                    else if(temp2 == 3) fight(cnt1+1,cnt2,cnt3+1,jwCnt,khCnt,mhCnt+1,tempNotPart);
                }else if(notPart == 3){
                    if(temp2 == 1) fight(cnt1+1,cnt2+1,cnt3,jwCnt+1,khCnt,mhCnt,tempNotPart);
                    else if(temp2 == 2) fight(cnt1+1,cnt2+1,cnt3,jwCnt,khCnt+1,mhCnt,tempNotPart);
                }
                chk[i] =false;
            }
        }
    }
}

int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1; i<=20; i++){
        cin>>kh[i];
    }

    for(int i=1; i<=20; i++){
        cin>>mh[i];
    }

    fight(1,1,1,0,0,0,3);

    flag == true ? cout<<1 : cout<<0;

    return 0;
}