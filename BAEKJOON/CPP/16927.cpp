/*
배돌2
https://www.acmicpc.net/problem/16927

4 4 2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
*/

#include <cstdio>
#include <algorithm>

using namespace std;
int n,m,r;
int arr[302][302];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void rotate(int x){
    int temp = arr[x][x];
    int cx = x; int cy = x;
    int cnt=0;
    int dir = 0;

    while(cnt<4){
        int nx = cx+dx[dir];
        int ny = cy+dy[dir];

        if(nx<n-x && ny<m-x && nx>=x && ny>=x){
            arr[cx][cy] = arr[nx][ny];
            cx = nx; cy = ny;
        }else{
            dir = (dir+1)%4;
            cnt++;
        }
    }

    arr[x+1][x] = temp;
}


int main(){
    scanf("%d%d%d",&n,&m,&r);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d",&arr[i][j]);
        }
    }

    int size = min(m,n);
    size/=2;

    //전체 그룹 r번 돌려야 하는데, 죄다 r번 돌리지 말고,
    for(int i=0; i<size; i++){
        int rot = 2*(n-(2*i+1)) + 2*(m-(2*i+1));
        int tempR = r%rot;
        while(tempR--){
        rotate(i);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ",arr[i][j]);
        }printf("\n");
    }

    return 0;
}
