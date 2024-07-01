/*
https://www.acmicpc.net/problem/5373
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char arr[6][3][3];
int T;
char initArr[6] = {'r','o','g','b','w','y'};

void init(){
    for(int i=0; i<6; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                arr[i][j][k] = initArr[i];
            }
        }
    }
}

void turn(int space, char dir){
    char temp[3];

    temp[0] = arr[space][0][0];
    temp[1] = arr[space][0][1];
    temp[2] = arr[space][0][2];

    if(dir == '+'){
        arr[space][0][0] = arr[space][2][0];
        arr[space][0][1] = arr[space][1][0];
        arr[space][0][2] = temp[0];

        arr[space][2][0] = arr[space][2][2];
        arr[space][1][0] = arr[space][2][1];

        arr[space][2][2] = temp[2];
        arr[space][2][1] = arr[space][1][2];

        arr[space][1][2] = temp[1];

    }else{
        arr[space][0][0] = arr[space][0][2];
        arr[space][0][1] = arr[space][1][2];
        arr[space][0][2] = arr[space][2][2];

        arr[space][1][2] = arr[space][2][1];
        arr[space][2][2] = arr[space][2][0];

        arr[space][2][1] = arr[space][1][0];

        arr[space][2][0] = temp[0];
        arr[space][1][0] = temp[1];
    }
}

void change(char space, char dir){
    char temp[3];

    switch(space){
        case 'F'://0

        turn(0,dir);

        for(int i=0; i<3; i++){
            temp[i] = arr[4][2][i];
        }

        if(dir == '+'){
            for(int i=0; i<3; i++){
                arr[4][2][i] = arr[2][2-i][2];
                arr[2][2-i][2] = arr[5][0][2-i];
                arr[5][0][2-i] = arr[3][i][0];
                arr[3][i][0] = temp[i];
            }
        }else{
            for(int i=0; i<3; i++){
                arr[4][2][i] = arr[3][i][0];
                arr[3][i][0] = arr[5][0][2-i];
                arr[5][0][2-i] = arr[2][2-i][2];
                arr[2][2-i][2] = temp[i];
            }
        }
        break;


        case 'B'://1

        turn(1,dir);

        for(int i=0; i<3; i++){
            temp[i] = arr[5][2][i];
        }

        if(dir == '+'){
            for(int i=0; i<3; i++){
                arr[5][2][i] = arr[2][i][0];
                arr[2][i][0] = arr[4][0][2-i];
                arr[4][0][2-i] = arr[3][2-i][2];
                arr[3][2-i][2] = temp[i];
            }
        }else{
            for(int i=0; i<3; i++){
                arr[5][2][i] = arr[3][2-i][2];
                arr[3][2-i][2] = arr[4][0][2-i];
                arr[4][0][2-i] = arr[2][i][0];
                arr[2][i][0] = temp[i];
            }
        }
        break;

        
        case 'L'://2

        turn(2,dir);

        for(int i=0; i<3; i++){
            temp[i] = arr[4][i][0];
        }

        if(dir == '+'){
            for(int i=0; i<3; i++){
                arr[4][i][0] = arr[1][i][0];
                arr[1][i][0] = arr[5][i][0];
                arr[5][i][0] = arr[0][i][0];
                arr[0][i][0] = temp[i];
            }
        }else{
            for(int i=0; i<3; i++){
                arr[4][i][0] = arr[0][i][0];
                arr[0][i][0] = arr[5][i][0];
                arr[5][i][0] = arr[1][i][0];
                arr[1][i][0] = temp[i];
            }
        }
        break;



        case 'R'://3

        turn(3,dir);

        for(int i=0; i<3; i++){
            temp[i] = arr[4][2-i][2];
        }

        if(dir == '+'){
            for(int i=0; i<3; i++){
                arr[4][2-i][2] = arr[0][2-i][2];
                arr[0][2-i][2] = arr[5][2-i][2];
                arr[5][2-i][2] = arr[1][2-i][2];
                arr[1][2-i][2] = temp[i];
            }
        }else{
            for(int i=0; i<3; i++){
                arr[4][2-i][2] = arr[1][2-i][2];
                arr[1][2-i][2] = arr[5][2-i][2];
                arr[5][2-i][2] = arr[0][2-i][2];
                arr[0][2-i][2] = temp[i];
            }
        }
        break;


        case 'U'://4

        turn(4,dir);

        for(int i=0; i<3; i++){
            temp[i] = arr[1][2][i];
        }

        if(dir == '+'){
            for(int i=0; i<3; i++){
                arr[1][2][i] = arr[2][0][2-i];
                arr[2][0][2-i] = arr[0][0][2-i];
                arr[0][0][2-i] = arr[3][0][2-i];
                arr[3][0][2-i] = temp[i];
            }
        }else{
            for(int i=0; i<3; i++){
                arr[1][2][i] = arr[3][0][2-i];
                arr[3][0][2-i] = arr[0][0][2-i];
                arr[0][0][2-i] = arr[2][0][2-i];
                arr[2][0][2-i] = temp[i];
            }
        }
        break;


        case 'D'://5

        turn(5,dir);

        for(int i=0; i<3; i++){
            temp[i] = arr[0][2][i];
        }

        if(dir == '+'){
            for(int i=0; i<3; i++){
                arr[0][2][i] = arr[2][2][i];
                arr[2][2][i] = arr[1][0][2-i];
                arr[1][0][2-i] = arr[3][2][i];
                arr[3][2][i] = temp[i];
            }
        }else{
            for(int i=0; i<3; i++){
                arr[0][2][i] = arr[3][2][i];
                arr[3][2][i] = arr[1][0][2-i];
                arr[1][0][2-i] = arr[2][2][i];
                arr[2][2][i] = temp[i];
            }
        }
        break;

    }
    
}

void printUp(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<arr[4][i][j];
        }cout<<'\n';
    }
}

int main(){
    cin>>T;
    while(T--){
        init();
        int cnt;
        cin>>cnt;
        while(cnt--){
            string s;
            cin>>s;
            change(s[0],s[1]);
        }
        printUp();
    }

    return 0;
}