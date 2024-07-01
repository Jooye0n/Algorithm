/*
https://www.acmicpc.net/problem/1514
n<=100
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;
int n;
string startNum, endNum;
queue<string> q;
set<string> s;//chk 대신

void turnOneChar(int x, string cs){
    //한칸돌리기
    string temp = cs;

    for(int i=1; i<5; i++){
        cs[x] = (((cs[x]-'0') +i) % 10 ) + '0';
        if(s.count(cs) == 0){
            s.insert(cs);
            q.push(cs);
        }
        cs[x] = temp[x];

        cs[x] = (((cs[x]-'0') -i +10) % 10 ) + '0';
        if(s.count(cs) == 0){
            s.insert(cs);
            q.push(cs);
        }
        cs[x] = temp[x];
    }

    //i=5
    cs[x] = (((cs[x]-'0') +5) % 10 ) + '0';
    if(s.count(cs) == 0){
        s.insert(cs);
        q.push(cs);
    }
}

void turnTwoChar(int x, string cs){
    //두칸돌리기
    string temp = cs;

    for(int i=1; i<5; i++){
        cs[x] = (((cs[x]-'0') +i) % 10 ) + '0';
        cs[x+1] = (((cs[x+1]-'0') +i) % 10 ) + '0';
        if(s.count(cs) == 0){
            s.insert(cs);
            q.push(cs);
        }
        cs[x] = temp[x];
        cs[x+1] = temp[x+1];

        cs[x] = (((cs[x]-'0') -i +10) % 10 ) + '0';
        cs[x+1] = (((cs[x+1]-'0') -i +10) % 10 ) + '0';
        if(s.count(cs) == 0){
            s.insert(cs);
            q.push(cs);
        }
        cs[x] = temp[x];
        cs[x+1] = temp[x+1];
    }

    //i=5
    cs[x] = (((cs[x]-'0') +5) % 10 ) + '0';
    cs[x+1] = (((cs[x+1]-'0') +5) % 10 ) + '0';
    if(s.count(cs) == 0){
        s.insert(cs);
        q.push(cs);
    }
}

void turnThreeChar(int x, string cs){
    //세칸돌리기
    string temp = cs;

    for(int i=1; i<5; i++){
        cs[x] = (((cs[x]-'0') +i) % 10 ) + '0';
        cs[x+1] = (((cs[x+1]-'0') +i) % 10 ) + '0';
        cs[x+2] = (((cs[x+2]-'0') +i) % 10 ) + '0';
        if(s.count(cs) == 0){
            s.insert(cs);
            q.push(cs);
        }
        cs[x] = temp[x];
        cs[x+1] = temp[x+1];
        cs[x+2] = temp[x+2];

        cs[x] = (((cs[x]-'0') -i +10) % 10 ) + '0';
        cs[x+1] = (((cs[x+1]-'0') -i +10) % 10 ) + '0';
        cs[x+2] = (((cs[x+2]-'0') -i +10) % 10 ) + '0';
        if(s.count(cs) == 0){
            s.insert(cs);
            q.push(cs);
        }
        cs[x] = temp[x];
        cs[x+1] = temp[x+1];
        cs[x+2] = temp[x+2];
    }

    //i=5
    cs[x] = (((cs[x]-'0') +5) % 10 ) + '0';
    cs[x+1] = (((cs[x+1]-'0') +5) % 10 ) + '0';
    cs[x+2] = (((cs[x+2]-'0') +5) % 10 ) + '0';
    if(s.count(cs) == 0){
        s.insert(cs);
        q.push(cs);
    }
}

int foundUsingBFS(){
    int result = 0;
    s.insert(startNum);
    q.push(startNum);

    while(q.empty() == false){
        int size = q.size();
        while(size--){
            string cs = q.front(); q.pop();
            if(cs.compare(endNum) == 0) return result;

            //1칸 돌리기
            for(int i=0; i<n; i++){
                turnOneChar(i,cs);
            }

            //2칸 돌리기
            for(int i=0; i<n-1; i++){
                turnTwoChar(i,cs);
            }

            //3칸 돌리기
            for(int i=0; i<n-2; i++){
                turnThreeChar(i,cs);
            }
        }
        result++;
    }
}

int main(){
    cin>>n;
    cin>>startNum>>endNum;
    cout<<foundUsingBFS();
    return 0;
}
