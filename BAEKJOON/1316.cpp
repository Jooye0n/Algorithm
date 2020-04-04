#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

set <pair<int,int>> point;
set <pair<pair<int,int>,pair<int,int>>> line;

int main() {
    int n;
    cin>>n;
    string s; cin>>s;

    vector<int> arrows;
    
    for(int i=0; i<n; i++){
        arrows.push_back(s[i]-'0');
    }
    
    int answer = 0;

    pair<int,int> now = make_pair(0,0);
    point.insert(now);

    for(int i=0;i<arrows.size();i++)
    {
        pair<int,int> next = now;
        for(int j=0;j<2;j++)
        {
            next.first += dy[arrows[i]];
            next.second += dx[arrows[i]];
            pair<int,int> Max = max(next,now);
            pair<int,int> Min = min(now,next);
            if(point.find(next)!=point.end() && line.find(make_pair(Min,Max))==line.end())
            {
                answer++;
            }
            point.insert(next);
            line.insert(make_pair(Min,Max));
            now = next;
        }
    }

    cout<<answer;
    return 0;
}