/*
https://www.acmicpc.net/problem/15683
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

struct Camera{
    int x;
    int y;
    int num;
};

int arr[8][8];
int minNum = 987987987;
int n,m;
vector<Camera> v;

void DFS(int x, int k);
void printAll();

int fillArea(int x, int y, int dir){
    int eraseSafe = 0;
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    for(int i=1; i<max(m,n); i++){
        int nx = x+dx[dir]*i;
        int ny = y+dy[dir]*i;

        if(nx<0 || ny<0 || nx>=n || ny>=m) break;

        if(arr[nx][ny] == 6) break;

        else if(arr[nx][ny] == 0){
            arr[nx][ny] = 7;
            eraseSafe++;
        }
    }

    return eraseSafe;
}

void camera1(int x, int y, int th, int k){
    int temp[8][8];

    for(int i=0; i<4; i++){
        //arr 배열을  temp 배열로 옮기는 함수
        for(int arri=0; arri<n; arri++){
            for(int arrj=0; arrj<m; arrj++){
                temp[arri][arrj] = arr[arri][arrj];
            }
        }

        int eraseSafe = fillArea(x,y,i);
        DFS(th+1,k-eraseSafe);
        //arr 배열을  temp 배열로 옮기는 함수
        for(int arri=0; arri<n; arri++){
            for(int arrj=0; arrj<m; arrj++){
                arr[arri][arrj] = temp[arri][arrj];
            }
        }
    }
}

void camera2(int x, int y, int th, int k){
    int temp[8][8];
    for(int d=0; d<=2; d+=2){//d=0 d=2
        int eraseSafe = 0;
        //arr 배열을  temp 배열로 옮기는 함수
        for(int arri=0; arri<n; arri++){
            for(int arrj=0; arrj<m; arrj++){
                temp[arri][arrj] = arr[arri][arrj];
            }
        }

        for(int i=0; i<=1; i++){
            eraseSafe+= fillArea(x,y,i+d);//i+d=0,1   2,3
        }
        DFS(th+1,k-eraseSafe);
        //arr 배열을  temp 배열로 옮기는 함수
        for(int arri=0; arri<n; arri++){
            for(int arrj=0; arrj<m; arrj++){
                arr[arri][arrj] = temp[arri][arrj];
            }
        }
    }
}

void camera3(int x, int y, int th, int k){
    int temp[8][8];
    //arr 배열을  temp 배열로 옮기는 함수
    for(int arri=0; arri<n; arri++){
        for(int arrj=0; arrj<m; arrj++){
            temp[arri][arrj] = arr[arri][arrj];
        }
    }

    int eraseSafe = 0;
    eraseSafe+=fillArea(x,y,1);
    eraseSafe+=fillArea(x,y,3);
    DFS(th+1,k-eraseSafe);
    //arr 배열을  temp 배열로 옮기는 함수
    for(int arri=0; arri<n; arri++){
        for(int arrj=0; arrj<m; arrj++){
            arr[arri][arrj] = temp[arri][arrj];
        }
    }

    eraseSafe = 0;
    eraseSafe+=fillArea(x,y,0);
    eraseSafe+=fillArea(x,y,3);
    DFS(th+1,k-eraseSafe);
    //arr 배열을  temp 배열로 옮기는 함수
    for(int arri=0; arri<n; arri++){
        for(int arrj=0; arrj<m; arrj++){
            arr[arri][arrj] = temp[arri][arrj];
        }
    }

    eraseSafe = 0;
    eraseSafe+=fillArea(x,y,0);
    eraseSafe+=fillArea(x,y,2);
    DFS(th+1,k-eraseSafe);
    //arr 배열을  temp 배열로 옮기는 함수
    for(int arri=0; arri<n; arri++){
        for(int arrj=0; arrj<m; arrj++){
            arr[arri][arrj] = temp[arri][arrj];
        }
    }

    eraseSafe = 0;
    eraseSafe+=fillArea(x,y,1);
    eraseSafe+=fillArea(x,y,2);
    DFS(th+1,k-eraseSafe);
    //arr 배열을  temp 배열로 옮기는 함수
    for(int arri=0; arri<n; arri++){
        for(int arrj=0; arrj<m; arrj++){
            arr[arri][arrj] = temp[arri][arrj];
        }
    }
}

void camera4(int x, int y, int th, int k){
    int temp[8][8];
    int eraseSafe = 0;
    //arr 배열을  temp 배열로 옮기는 함수
    for(int arri=0; arri<n; arri++){
        for(int arrj=0; arrj<m; arrj++){
            temp[arri][arrj] = arr[arri][arrj];
        }
    }

    eraseSafe+=fillArea(x,y,1);
    eraseSafe+=fillArea(x,y,2);
    eraseSafe+=fillArea(x,y,3);
    DFS(th+1,k-eraseSafe);
    //arr 배열을  temp 배열로 옮기는 함수
    for(int arri=0; arri<n; arri++){
        for(int arrj=0; arrj<m; arrj++){
            arr[arri][arrj] = temp[arri][arrj];
        }
    }

    eraseSafe = 0;
    eraseSafe+=fillArea(x,y,0);
    eraseSafe+=fillArea(x,y,2);
    eraseSafe+=fillArea(x,y,3);
    DFS(th+1,k-eraseSafe);
    //arr 배열을  temp 배열로 옮기는 함수
    for(int arri=0; arri<n; arri++){
        for(int arrj=0; arrj<m; arrj++){
            arr[arri][arrj] = temp[arri][arrj];
        }
    }

    eraseSafe = 0;
    eraseSafe+=fillArea(x,y,1);
    eraseSafe+=fillArea(x,y,0);
    eraseSafe+=fillArea(x,y,3);
    DFS(th+1,k-eraseSafe);
    //arr 배열을  temp 배열로 옮기는 함수
    for(int arri=0; arri<n; arri++){
        for(int arrj=0; arrj<m; arrj++){
            arr[arri][arrj] = temp[arri][arrj];
        }
    }

    eraseSafe = 0;
    eraseSafe+=fillArea(x,y,1);
    eraseSafe+=fillArea(x,y,2);
    eraseSafe+=fillArea(x,y,0);
    DFS(th+1,k-eraseSafe);
    //arr 배열을  temp 배열로 옮기는 함수
    for(int arri=0; arri<n; arri++){
        for(int arrj=0; arrj<m; arrj++){
            arr[arri][arrj] = temp[arri][arrj];
        }
    }
}


void camera5(int x, int y, int th, int k){
    int temp[8][8];
    int eraseSafe = 0;
    //arr 배열을  temp 배열로 옮기는 함수
    for(int arri=0; arri<n; arri++){
        for(int arrj=0; arrj<m; arrj++){
            temp[arri][arrj] = arr[arri][arrj];
        }
    }

    for(int i=0; i<4; i++){
        eraseSafe += fillArea(x,y,i);
    }

    DFS(th+1,k-eraseSafe);
    //arr 배열을  temp 배열로 옮기는 함수
    for(int arri=0; arri<n; arri++){
        for(int arrj=0; arrj<m; arrj++){
            arr[arri][arrj] = temp[arri][arrj];
        }
    }
}

void printAll(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<' ';
        }cout<<"\n";
    }cout<<'\n';
}



void DFS(int x, int k){
    //x번째 vector의 카메라  x 표시 후 개수세기 (k 는 x번째 DFS 하기 전 카메라까지의 사각지대 수)
    if(x == v.size()){
        if(k<minNum){
            minNum = k;
            //printAll();
            //cout<<':'<<minNum<<'\n';
        }
    }else{
        int cn = v[x].num;
        int cx = v[x].x;
        int cy = v[x].y;

        switch(cn){
            case 1:
            camera1(cx,cy,x,k);
            break;

            case 2:
            camera2(cx,cy,x,k);
            break;

            case 3:
            camera3(cx,cy,x,k);
            break;

            case 4:
            camera4(cx,cy,x,k);
            break;

            case 5:
            camera5(cx,cy,x,k);
            break;
        }        
    }
}

int main(){
    int result = 0;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j]>0 && arr[i][j]<6){//카메라면,
                Camera c = {i,j,arr[i][j]};
                v.push_back(c);
            }else if(arr[i][j]==0){
                result++;
            }
        }
    }
    
    DFS(0,result);
    cout<<minNum;

    return 0;
}