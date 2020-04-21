#include <bits/stdc++.h>
#define MAX 987987987
using namespace std;
struct point {
    int x, y;
};
int n;
int minTime = MAX;
int arr[10][10];
int numOfStair[10];
int arriveTime[10];
vector<point> person;
vector<point> stair;
 
void getArriveToStairTime(int x) {
    //사람 x의 계단 도착 시간을 구하여 arriveTime배열에 넣는다.
    int cx = person[x].x;
    int cy = person[x].y;
    int sx = stair[numOfStair[x]].x;
    int sy = stair[numOfStair[x]].y;
 
    arriveTime[x] = abs(cx - sx) + abs(cy - sy) + 1;
}
 
int getTime(int num, vector<int> v) {
    //계단 v로 탈출하는 사람들의 최종 탈출 시간 return
    if (v.size() == 0) return 0;
 
    queue<int> q;
    sort(v.begin(), v.end());
    num = arr[stair[num].x][stair[num].y];//최대 인원수
    int idx = 0;
    int cnt = 0;//빠져나온 사람 수
    int curTime = v[0];//현재 시간
      
    while (true) {
        while (q.empty() == false) {//나갈 수 있으면 나간다.
            if (curTime - q.front() == num) {
                cnt++;
                q.pop();
            }
            else break;
        }
 
        while (idx < v.size()) {//이미 도착했고, 들어갈 수 있으면 들어간다.
            if (q.size() < 3) {
                if (v[idx] > curTime) break;
                q.push(curTime);
                idx++;
            }
            else break;
        }
 
        if (cnt == v.size()) return curTime;
        else curTime++;
    }
}
 
int getFinalTime() {
    //최종 탈출 시간 구한다.
    vector<int> s0;//계단 0
    vector<int> s1;//계단 1
 
    for (int i = 0; i < person.size(); i++) {
        if (numOfStair[i] == 0) {
            s0.push_back(arriveTime[i]);
        }
        else {
            s1.push_back(arriveTime[i]);
        }
    }
 
    return max(getTime(0,s0), getTime(1,s1));
}
 
void setNumberOfStairs(int x) {
    //사람마다 내려갈 계단(0 or 1) 정한다.
    if (x == person.size()) {
        for (int i = 0; i < person.size(); i++) {
            getArriveToStairTime(i);
        }
        minTime = min(minTime, getFinalTime());
    }
    else {
        for (int i = 0; i < 2; i++) {
            numOfStair[x] = i;
            setNumberOfStairs(x + 1);
        }
    }
}
 
void init() {
    person.clear();
    stair.clear();
    minTime = MAX;
}
 
int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == 1) {
                    person.push_back({ i,j });
                }
                else if (arr[i][j] > 1) {
                    stair.push_back({ i,j });
                }
            }
        }
        setNumberOfStairs(0);
        printf("#%d %d\n",t,minTime);
    }
    return 0;
}