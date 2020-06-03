#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 100000000
using namespace std;
struct point{
    string start;
    string end;
    bool flag;
};

vector<point> v;
vector<string> answer;
vector<string> res;
int n;
bool result = false;

void DFS(int x, string cur){
    if(x == n){
        if(res.size() == 0) res = answer;
        return;
    }else{
        for(int i=0; i<v.size(); i++){
            if(cur.compare(v[i].start) == 0 && v[i].flag == false){
                v[i].flag = true;
                answer.push_back(v[i].end);
                DFS(x+1,v[i].end);
                answer.pop_back();
                v[i].flag = false;
            }
        }
    }
}

bool cmp(const point &p1, const point &p2){
    if(p1.start.compare(p2.start)<0) return true;
    else if(p1.start.compare(p2.start)==0){
        if(p1.end.compare(p2.end)<0) return true;
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    for(int i=0;i<tickets.size(); i++){
        v.push_back({tickets[i][0],tickets[i][1],false});
    }
    sort(v.begin(),v.end(),cmp);
    n = v.size();
    answer.push_back("ICN");
    DFS(0,"ICN");
    return res;
}