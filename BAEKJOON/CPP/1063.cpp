/*
https://www.acmicpc.net/problem/1063

A1 A2 5
B
L
LB
RB
LT
*/

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

struct point{
    int x;
    int y;
};

int arr[8][8];
int n;

point king; string ks;
point stone; string ss;

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

point chessToCoord(string s){
    int y = s[0]-'A';
    int x = 7-(s[1]-'1');

    point p = {x,y};
    return p;
}


string CoordToChess(point p){
    string s;
    s+=(p.y+'A');
    s+=(7+'1'-p.x);

    return s;
}

int moveFlag(string s){
    if(s.compare("LT")==0) return 0;
    else if(s.compare("T")==0) return 1;
    else if(s.compare("RT")==0) return 2;
    else if(s.compare("L")==0) return 3;
    else if(s.compare("R")==0) return 4;
    else if(s.compare("LB")==0) return 5;
    else if(s.compare("B")==0) return 6;
    else if(s.compare("RB")==0) return 7;
}

void moveKing(string dir){
    //dir으로 king 이동
    int d = moveFlag(dir);

    int kx = king.x+dx[d];
    int ky = king.y+dy[d];

    if(kx>=0 && ky>=0 && kx<8 && ky<8){
        if(kx==stone.x && ky==stone.y){
            int sx = stone.x+dx[d];
            int sy = stone.y+dy[d];
            if(sx>=0 && sy>=0 && sx<8 && sy<8){
                stone.x = sx;
                stone.y = sy;
                king.x = kx;
                king.y = ky;
            }
        }else{
            king.x = kx;
            king.y = ky;
        }
    }
}

int main(){
    cin>>ks>>ss;
    point temp = chessToCoord(ks);
    king.x = temp.x; king.y = temp.y;

    point temp2 = chessToCoord(ss);
    stone.x = temp2.x; stone.y = temp2.y;

    cin>>n;

    while(n--){
        string s;
        cin>>s;
        moveKing(s);
    }

    cout<<CoordToChess(king)<<'\n'<<CoordToChess(stone);

    return 0;
}