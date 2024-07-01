#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct point{
    int x;
    int y;
};

int arr[5][9];
bool chk[12];//0-11
vector<point> v;//x의 위치들 모음.(순서대로임)

void printAll(){
    for(int i=0; i<5; i++){
        for(int j=0; j<9; j++){
            if(arr[i][j] == -1) printf(".");
            else{
                int temp = arr[i][j]+'A';
                printf("%c",temp);
            }
        }printf("\n");
    }
}

bool chkMagic(){
    //매직스타인지 검사
    if(arr[1][1] + arr[1][3] + arr[1][5] + arr[1][7] != 22) return false;
    if(arr[1][7] + arr[2][6] + arr[3][5] + arr[4][4] != 22) return false;
    if(arr[4][4] + arr[3][3] + arr[2][2] + arr[1][1] != 22) return false;
    if(arr[0][4] + arr[1][5] + arr[2][6] + arr[3][7] != 22) return false;
    if(arr[3][7] + arr[3][5] + arr[3][3] + arr[3][1] != 22) return false;
    if(arr[3][1] + arr[2][2] + arr[1][3] + arr[0][4] != 22) return false;

    return true;
}

void found(int k){
    if(k == v.size()){
        if(chkMagic() == true){
            printAll();
            exit(0);
        }

    }else{
        for(int i=0; i<12; i++){
            if(chk[i] == false){
                chk[i] = true;
                arr[v[k].x][v[k].y] = i;
                found(k+1);
                chk[i] = false;
                arr[v[k].x][v[k].y] = 23;
            }
        }
    }
}

int main(){
    for(int i=0; i<5; i++){
        string s;
        cin>>s;
        for(int j=0; j<s.size(); j++){
            if(s[j] == '.') {
                arr[i][j] = -1;
            }else{
                if(s[j] == 'x'){
                    point xp = {i,j};
                    v.push_back(xp);
                    arr[i][j] = 23;
                }else{
                    arr[i][j] = s[j]-'A';
                    chk[arr[i][j]] = true;
                }
            }
        }
    }

    found(0);
    return 0;
}