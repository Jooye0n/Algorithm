/*
8 8
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBBBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW
*/

#include <cstdio>
#include <iostream>

using namespace std;

int arr[51][51];
int n,m;
int minNum = 987987987;

int startx, starty;

int paintBoard(){
    //2가지 경우 각각의 최소값 구해서 더 작은 값 return
    int result = 987987987;
    //검정색과 하얀색에 대해,
    for(int startColor = -1; startColor<=1; startColor+=2){
        int resultTemp = 0;

        int rowStartColor = startColor;

        for(int i=startx; i<startx+8; i++){

            rowStartColor *= -1;//이어야 함.
            int culStartColor = rowStartColor;

            for(int j=starty; j<starty+8; j++){
                culStartColor *= -1;
                if(arr[i][j] != culStartColor) resultTemp++;
            }
        }

        if(result>resultTemp) result = resultTemp;
    }

    return result;
}

void choiceBoard(){
    for(int i=0; i<=n-8; i++){
        for(int j=0; j<=m-8; j++){
            startx = i;
            starty = j;

            int temp = paintBoard();
            if(minNum>temp) minNum = temp;
        }
    }
}

int main(){
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char str;
            cin>>str;
            if(str == 'B') arr[i][j] = 1;
            else if(str == 'W') arr[i][j] = -1;
        }
    }

    choiceBoard();
    cout<<minNum;
    return 0;
}