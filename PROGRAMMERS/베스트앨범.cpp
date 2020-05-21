#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
struct person{
    int genNum;
    int play;
    int idx;
};

map<string,int> m;
vector<person> v;

bool cmp(const person &p1, const person &p2){
    if(p1.genNum > p2.genNum) return true;
    else if(p1.genNum == p2.genNum){
        if(p1.play > p2.play) return true;
        else if(p1.play == p2.play){
            if(p1.idx<p2.idx)return true;
        }
    }
    
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i=0; i<genres.size(); i++){
        m[genres[i]]+=plays[i];
    }
    for(int i=0; i<genres.size(); i++){
        v.push_back({m[genres[i]],plays[i],i});
    }
    sort(v.begin(), v.end(), cmp);
    map<int,int> chk;
    for(int i=0; i<v.size(); i++){
        if(chk[v[i].genNum] >= 2) continue;
        chk[v[i].genNum]++;
        answer.push_back(v[i].idx);
    }
    return answer;
}