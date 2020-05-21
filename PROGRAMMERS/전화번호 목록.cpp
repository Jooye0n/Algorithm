#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string,bool> m;
bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(),phone_book.end());
    for(int i=0; i<phone_book.size(); i++){
        m[phone_book[i]] = true;
        string temp = "";
        for(int j=0; j<phone_book[i].size()-1;j++){
            temp += phone_book[i][j];
            if(m[temp] == true) return false;
        }
    }
    return answer;
}