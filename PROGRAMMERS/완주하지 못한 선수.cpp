#include <string>
#include <vector>
#include <map>

using namespace std;
map<string,int> m;
string solution(vector<string> participant, vector<string> completion) {
    for(int i=0; i<completion.size(); i++){
        m[completion[i]]++;
    }
    for(int i=0; i<participant.size(); i++){
        if(m[participant[i]] == 0) return participant[i];
        m[participant[i]]--;
    }
}