/*
https://www.acmicpc.net/problem/4991

시작점 깨끗한곳 0
더러운곳 num
가구 -1

1. 더러운거 중에서 2개의 조합 고르기
2. 그 두개간의 최단거리 구해서 map에 저장
3. 더러운거 num개의 순열 구하기
4. 순열의 최단거리 합 중 최소값으로 cout
->실패 왜냐면 왔던길 다시가기가 불가능하다


1. 청소기부터 각각 더러운 점 까지의 거리 구하기
2. 각각 더러운 점부터 다른점 모두 거치는 최단거리 구하기
3. 1과 2의 합 중 최소 cout

*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>


using namespace std;

struct point{
    int x;
    int y;
};

bool flag;
int arr[21][21];
int map[21][21];
point dirty[12];//0은 청소기 위치

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool chk[21][21];
queue<point> q;
int getMin = 0;

int w;//가로
int h;//세로

bool chknum[11];

vector<int> v;
int num=1;

int getMinRoute(int start){
    //start 최단거리
    fill(&chk[0][0],&chk[20][21],false);
    fill(chknum, chknum+11,false);
    while(q.empty() == false) q.pop();

    int local = 0;
    int countDirty = 0;

    q.push(dirty[start]);
    chk[dirty[start].x][dirty[start].y] = true;
    chknum[start] = true;
    countDirty++;

    while(q.empty() == false){
        int size = q.size();
        local++;
        while(size--){
            int cx = q.front().x;
            int cy = q.front().y; q.pop();

            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];

                if(nx>=0 && ny>=0 && nx<h && ny<w && chk[nx][ny] == false && arr[nx][ny] !=-1){

                    if(arr[nx][ny] > 0 && chknum[arr[nx][ny]] == false){
                        countDirty++;
                        chknum[arr[nx][ny]] = true;
                        fill(&chk[0][0],&chk[20][21],false);
                        while(q.empty() == false) q.pop();

                        if(countDirty == num-1){
                            return local;
                        }

                    }

                    chk[nx][ny] = true;
                    point p = {nx,ny};
                    q.push(p);
                    
                }
            }
        }
        
    }
    return -1;
}

int getLen(int start, int end){
    //start 부터 end까지 최단거리
    fill(&chk[0][0],&chk[20][21],false);
    while(q.empty() == false) q.pop();
    
    int local = 0;

    q.push(dirty[start]);
    chk[dirty[start].x][dirty[start].y] = true;

    while(q.empty() == false){
        int size = q.size();
        local++;
        while(size--){
            int cx = q.front().x;
            int cy = q.front().y; q.pop();

            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];

                if(nx>=0 && ny>=0 && nx<h && ny<w && chk[nx][ny] == false && arr[nx][ny] !=-1){
                    if(arr[nx][ny] == end){
                        return local;
                    }else if(arr[nx][ny] >= 0){
                        chk[nx][ny] = true;
                        point p = {nx,ny};
                        q.push(p);
                    }
                }
            }
        }
    }
    return -1;
}



int main(){
    while(true){
        cin>>w>>h;

        if(w == 0 && h == 0){
            break;
        }

        num = 1;
        flag = false;

        for(int i=0; i<h; i++){
            string s;
            cin>>s;
            for(int j=0; j<s.size(); j++){
                int temp;
                if(s[j] == '.'){
                    temp = 0;
                }else if(s[j] == '*'){
                    temp = num;
                    point p = {i,j};
                    dirty[num] = p;
                    num++;
                }else if(s[j] == 'o'){
                    point p = {i,j};//시작점
                    dirty[0] = p;
                    temp = 0;
                }else if(s[j] == 'x'){
                    temp = -1;
                }
                arr[i][j] = temp;
            }
        }

        int goToDirty[11]={0, };
        int result[11]={0, };

        //1. 청소기부터 각각 더러운 점 까지의 거리 구하기 
        //2. 각각 더러운 점부터 다른점 모두 거치는 최단거리 구하기

        for(int i=1; i<num; i++){
            result[i]= getLen(0,i);
            cout<<result[i]<<' ';
            if(result[i] == -1){
                cout<<-1<<'\n';
                flag = true;
                break;
            }else{
                result[i]+= getMinRoute(i);
                cout<<"c:"<<result[i]<<'\n';
            }
        }

        //3. 1과 2의 합 중 최소 cout
        if(flag == false)
            cout<<*min_element(result+1,result+num)<<'\n';
    }

    return 0;
}