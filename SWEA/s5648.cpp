#include <bits/stdc++.h>
#define IDX 2000
using namespace std;
 
struct point {
    int x, y;
    int dir; 
    int e; //1 이상
    bool flag;//죽으면 true
    int idx; //v 에서의 idx
};
 
struct spuare {
    int idx; //v idx를 담는다.
    int cnt; //해당 칸에서 충돌된 원자 수
};
 
const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { -1,1,0,0 };
 
int n;
spuare arr[2 * IDX + 1][2 * IDX + 1];
 
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int result = 0; // 최종 결과값
        vector<point> v; //전체 원자 담는다.
        cin >> n;
        for(int i=0; i<n; i++){
            point temp;
            cin >> temp.x >> temp.y >> temp.dir >> temp.e;
            temp.x = 2 * temp.x + IDX;
            temp.y = 2 * (IDX - temp.y) - IDX;
            temp.flag = false;
            temp.idx = i;
            v.push_back(temp);
        }
 
        while (true) {
            int cnt = 0;
            for(int curIdx =0; curIdx <v.size(); curIdx++){
 
                if (v[curIdx].flag == true) {
                    cnt++;
                    continue;
                }
 
                int cx = v[curIdx].x;
                int cy = v[curIdx].y;
                int ce = v[curIdx].e;
                int cdir = v[curIdx].dir;
 
                int nx = cx + dx[cdir];
                int ny = cy + dy[cdir];
 
                if (nx < 0 || ny < 0 || nx >= 2 * IDX || ny >= 2 * IDX) {
                    v[curIdx].flag = true;
                    continue;
                }
 
                v[curIdx].x = nx;
                v[curIdx].y = ny;
 
                if (arr[ny][nx].cnt == 0) {
                    arr[ny][nx].cnt = 1;
                    arr[ny][nx].idx = curIdx;
                }
                else if (arr[ny][nx].cnt == 1) {
                    arr[ny][nx].cnt++;
                    v[arr[ny][nx].idx].flag = true;
                    v[curIdx].flag = true;
                    result += v[arr[ny][nx].idx].e;
                    result += ce;
                }
                else if (arr[ny][nx].cnt == 2) {
                    v[curIdx].flag = true;
                    result += ce;
                }
            }
 
            if (cnt == v.size()) break;
            else {
                for (int i = 0; i < v.size(); i++) {
                    arr[v[i].y][v[i].x].cnt = 0;
                }
            }
        }
        printf("#%d %d\n", t, result);
    }
    return 0;
}