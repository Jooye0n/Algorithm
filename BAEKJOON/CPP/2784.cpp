/*
https://www.acmicpc.net/problem/2784
*/


#include <cstdio>
#include <iostream>
#include <string>
#include <memory.h>

using namespace std;
char arr[3][3];//map
string str[6];//단어 6개 사전순
int tempStr[3];//고른 문자의 idx

bool chk[6];

void printAll(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<arr[i][j];
        }cout<<'\n';
    }
}

bool putString(){
    //- 퍼즐 만들기
    for(int i=0; i<3; i++){//temp idx
        for(int j=0; j<3; j++){
            arr[i][j] = str[tempStr[i]][j];
        }
    }
    
    //남은 문자 세로줄에 맞는지
    string rowString[3];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            rowString[i] += arr[j][i];
        }
    }

    int cnt = 0;
    bool tempChk[3] = {false,false,false};

    for(int i=0; i<6; i++){
        if(i != tempStr[0] && i !=tempStr[1] && i !=tempStr[2]){

            for(int j=0; j<3; j++){
                //cout<<rowString[j]<<' '<<str[i]<<'\n';
                if(rowString[j].compare(str[i]) == 0 && chk[i] == false && tempChk[j] == false){
                    tempChk[j] = true;
                    chk[i] = true;
                    cnt++;
                }
            }
            
        }
    }

    memset(chk,false,sizeof(chk));
    
    chk[tempStr[0]] = true;
    chk[tempStr[1]] = true;
    chk[tempStr[2]] = true;

    if(cnt == 3) return true;
    else return false;
}

void foundAnswer(){
    string str1;
    string str2;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            str1 +=arr[i][j];
            str2 +=arr[j][i];
        }
    }

    if(str1.compare(str2) < 0){
        for(int i=0; i<9; i++){
            cout<<str1[i];
            if(i % 3 == 2) cout<<'\n';
        }
    }else{
        for(int i=0; i<9; i++){
            cout<<str2[i];
            if(i % 3 == 2) cout<<'\n';
        }
    }

    exit(0);
}

void choiceStr(int x){
    if(x == 3){
        //고른 문자 arr에 배치
        if(putString() == true){
            foundAnswer();
        }

    }else{
        for(int i=0; i<6; i++){
            if(chk[i] == false){
                tempStr[x] = i;
                chk[i] = true;
                choiceStr(x+1);
                chk[i] = false;
            }
        }
    }
}

int main(){
    for(int i=0 ;i<6; i++){
        cin>>str[i];
    }

    choiceStr(0);
    cout<<'0';
    return 0;
}