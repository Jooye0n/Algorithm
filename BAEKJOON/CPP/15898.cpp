/*
https://www.acmicpc.net/problem/15898
*/

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0,0,1,1};
int dy[4] = {0,1,0,1};
int maxResult = -987987987;
int power[4][4][10];
char color[4][4][10];
int gamaInt[5][5];
char gamaChar[5][5] = {
    'W','W','W','W','W',
    'W','W','W','W','W',
    'W','W','W','W','W',
    'W','W','W','W','W',
    'W','W','W','W','W'
};
bool choiceChk[10];
int n;
vector<int> choiceNum;

void turnPowerAndColor(int x){
    //시계 반대방향으로 power[x]와 color[x]돌린다.
    int tempInt[4][4];
    char tempChar[4][4];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            tempInt[j][i] = power[i][j][x];
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            power[i][j][x] = tempInt[3-i][j];
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            tempChar[j][i] = color[i][j][x];
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            color[i][j][x] = tempChar[3-i][j];
        }
    }
}

void fillGama(int cx, int cy, int x){
    //가마의 p위치에 x번째 재료 씌우기
    for(int i=cx; i<cx+4; i++){
        for(int j=cy; j<cy+4; j++){
            gamaInt[i][j] +=power[i-cx][j-cy][x];
            if(gamaInt[i][j]>9) gamaInt[i][j] = 9;
            if(gamaInt[i][j]<0) gamaInt[i][j] = 0;
        }
    }

    for(int i=cx; i<cx+4; i++){
        for(int j=cy; j<cy+4; j++){
            if(color[i-cx][j-cy][x] != 'W'){
                gamaChar[i][j] = color[i-cx][j-cy][x];
            }
        }
    }
}

void getMoney(){
    //가마의 최종 상태에서 빨강, 파랑, 초록, 노랑으로 칠해진 부분의 품질 합을 각각 R, B, G, Y라고 했을 때,
    int result = 0;

    int red = 0;
    int blue = 0;
    int green = 0;
    int yellow = 0;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            switch(gamaChar[i][j]){
                case 'R':
                red += gamaInt[i][j];
                break;

                case 'B':
                blue += gamaInt[i][j];
                break;

                case 'G':
                green +=gamaInt[i][j];
                break;

                case 'Y':
                yellow +=gamaInt[i][j];
                break;
            }
        }
    }

    //(폭탄의 품질) = 7R + 5B + 3G + 2Y
    result = 7*red + 5*blue + 3*green + 2*yellow;
    if(maxResult<result) maxResult = result;

}

void testGama(int x){
    //choiceNum에 세 가지 재료 들어있음 -> 가마로
    //4가지 방향 + 4가지 위치 전부 test해야한다.

    if(x==3){
        getMoney();
        return;
    }

    //choiceNum[x]번째 재료 test
    int tempInt[5][5];
    char tempChar[5][5];//가마 보관용

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            tempInt[i][j] = gamaInt[i][j];
            tempChar[i][j] = gamaChar[i][j];
        }
    }

    for(int d=0; d<4; d++){
        for(int j=0; j<4; j++){
            turnPowerAndColor(choiceNum[x]);
            fillGama(dx[d],dy[d],choiceNum[x]);
            testGama(x+1);

            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    gamaInt[i][j] = tempInt[i][j];
                    gamaChar[i][j] = tempChar[i][j];
                }
            }
        }
    }
}

void choice(int x){
    //재료 3개 고르기
    if(x==3){
        //가마에 넣기
        testGama(0);
    }else{
        for(int i=0; i<n; i++){
            if(choiceChk[i] == false){
                choiceChk[i] = true;
                choiceNum.push_back(i);
                choice(x+1);
                choiceChk[i] = false;
                choiceNum.pop_back();
            }
        }
    }
}

int main(){
    cin>>n;
    for(int num=0; num<n; num++){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                cin>>power[i][j][num];
            }
        }
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                cin>>color[i][j][num];
            }
        }
    }
    choice(0);
    cout<<maxResult;

    return 0;
}