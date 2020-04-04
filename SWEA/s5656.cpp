/*
[ 벽돌 깨기 ]
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRQm6qfL0DFAUo

[입력]

가장 첫 줄에는 총 테스트 케이스의 개수 T 가 주어지고,

그 다음 줄부터 T 개의 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 N, W, H 가 순서대로 공백을 사이에 두고 주어지고,

다음 H 줄에 걸쳐 벽돌들의 정보가 1 줄에 W 개씩 주어진다.

[제약 사항]

1. 1 ≤ N ≤ 4

2. 2 ≤ W ≤ 12

3. 2 ≤ H ≤ 15
 

[출력]

출력은 #t 를 찍고 한 칸 띄운 다음 정답을 출력한다.

(t 는 테스트 케이스의 번호를 의미하며 1 부터 시작한다)

입력
5 // T = 5

3 10 10 // #1, N = 3, W = 10, H = 10
0 0 0 0 0 0 0 0 0 0
1 0 1 0 1 0 0 0 0 0
1 0 3 0 1 1 0 0 0 1
1 1 1 0 1 2 0 0 0 9
1 1 4 0 1 1 0 0 1 1
1 1 4 1 1 1 2 1 1 1
1 1 5 1 1 1 1 2 1 1
1 1 6 1 1 1 1 1 2 1
1 1 1 1 1 1 1 1 1 5
1 1 7 1 1 1 1 1 1 1

2 9 10 // #2, N = 2, W = 9, H = 10
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0
1 1 0 0 1 0 0 0 0
1 1 0 1 1 1 0 1 0
1 1 0 1 1 1 0 1 0
1 1 1 1 1 1 1 1 0
1 1 3 1 6 1 1 1 1
1 1 1 1 1 1 1 1 1



1
3 10 10
0 0 0 0 0 0 0 0 0 0
1 0 1 0 1 0 0 0 0 0
1 0 3 0 1 1 0 0 0 1
1 1 1 0 1 2 0 0 0 9
1 1 4 0 1 1 0 0 1 1
1 1 4 1 1 1 2 1 1 1
1 1 5 1 1 1 1 2 1 1
1 1 6 1 1 1 1 1 2 1
1 1 1 1 1 1 1 1 1 5
1 1 7 1 1 1 1 1 1 1
 
출력
#1 12
#2 27
#3 4
#4 8
#5 0

*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int T;
int n,w,h;//구슬 수,가로,세로
int resultTemp;//남아있는 벽돌 수
int result = 999999999;
int map[16][13];//전체 벽돌
int temp[16][13];
int arr[5];//i번째 구슬의 w
int test;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


void downBlock(){
    for(int i=0; i<w; i++){
        queue<int> q;
        int k=0;

        for(int j=h-1; j>=0; j--){
            if(map[j][i] !=0){
                q.push(map[j][i]);
                map[j][i] = 0;
                map[h-1-k][i] = q.front(); q.pop();
                k++;
            }
        }
    }
}


void bomb(int x, int y){
    int value = map[x][y];//부셔질 벽돌의 값.
    map[x][y] = 0;
    
    if(value == 0) return;
    else if(value == 1){
        map[x][y] = 0;
        
    }else{
        for(int j=0; j<value; j++){//값만큼 주변 폭발
            for(int dir=0; dir<4; dir++){
                int nx = x+dx[dir]*j;
                int ny = y+dy[dir]*j;

                if(nx>=0 && nx<h && ny>=0 && ny<w ){
                    bomb(nx,ny);
                }
                    
            }
        }
    }
}

void DFS(int x, int y){
    //x,y부터 1이상인 점의 개수 세자.
    map[x][y] = 0;
    resultTemp++;

    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(nx>=0 && nx<h && ny>=0 && ny<w ){
            if(map[nx][ny] !=0)
                DFS(nx,ny);
        }
    }
}



void fun(int x){
	if(x == n){
        /*배열 복구*/
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                map[i][j] = temp[i][j];
            }
        }
        
		for(int i=0; i<n; i++){
            int ith = arr[i];//arr[i]는 i번째 구슬의 w값
            

            /*떨어트리고 깨트리기 DFS*/
            for(int j=0; j<h; j++){
                if(map[j][ith]!=0){//맞는 부분 찾으면
                    bomb(j,ith);//부실 수 있는 부분 전부 부시고
                    break;
                }
            }
            /*벽돌내리기*/
            downBlock();
		}

        /*벽돌 세서 = resultTemp로*/
        resultTemp = 0;
        
        for(int j=0; j<w; j++){
            if(map[h-1][j] != 0){//다녀 갔다는 표시로 0으로 바꾼다.
                DFS(h-1,j);
            }
        }
        
        if(result>resultTemp)
            result = resultTemp;

	}else{
		for(int i=0; i<w; i++){
				arr[x] = i;
				fun(x+1);
                
		}
	}
}


int main(){
    cin>>T;
    for(test=1; test<=T; test++){
        /*초기화*/
        result = 999999999;

        /*입력*/
        cin>>n>>w>>h;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>map[i][j];
                temp[i][j] = map[i][j];
            }
        }

        /* 전체 경우 따지기*/
        fun(0);
        printf("#%d %d\n",test,result);
    }

}