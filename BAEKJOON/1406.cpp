
/*
[ 에디터 ]
https://www.acmicpc.net/problem/1406
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
0.3 초 (하단 참고)	512 MB	22474	5494	3633	25.543%
문제
한 줄로 된 간단한 에디터를 구현하려고 한다. 이 편집기는 영어 소문자만을 기록할 수 있는 편집기로, 최대 600,000글자까지 입력할 수 있다.

이 편집기에는 '커서'라는 것이 있는데, 커서는 문장의 맨 앞(첫 번째 문자의 왼쪽), 문장의 맨 뒤(마지막 문자의 오른쪽), 또는 문장 중간 임의의 곳(모든 연속된 두 문자 사이)에 위치할 수 있다. 즉 길이가 L인 문자열이 현재 편집기에 입력되어 있으면, 커서가 위치할 수 있는 곳은 L+1가지 경우가 있다.

이 편집기가 지원하는 명령어는 다음과 같다.

L	커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
D	커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
B	커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
P $	$라는 문자를 커서 왼쪽에 추가함

예제 입력 1 
abcd
3
P x
L
P y
예제 출력 1 
abcdyx



예제 입력 2 
abc
9
L
L
L
L
L
P x
L
B
P y
예제 출력 2 
yxabc

첫째 줄에는 초기에 편집기에 입력되어 있는 문자열이 주어진다. 
이 문자열은 영어 소문자로만 이루어져 있으며, 길이는 100,000을 넘지 않는다. 

둘째 줄에는 입력할 명령어의 개수를 나타내는 정수 N(1≤N≤500,000)이 주어진다. 
셋째 줄부터 N개의 줄에 걸쳐 입력할 명령어가 순서대로 주어진다. 명령어는 위의 네 가지 중 하나의 형태로만 주어진다.

*/

// #include <cstdio>
// #include <iostream>
// #include <list>

// using namespace std;

// list<char> v;
// int n;

// int main(){
//     string s;
//     getline(cin,s);

//     for(int i=0; i<s.size(); i++){
//         v.push_back(s.at(i));
//     }

//     cin>>n;

//     char flag;
//     int current = v.size();

//     while(n--){
        
//         cin>>flag;
//         switch (flag)
//         {
//         case 'L':
//             if(current != 0){
//                 current--;
//             }
//             break;
//         case 'D':
//             if(current != v.size()){
//                 current++;
//             }
//             break;
//         case 'B':
            
//             if(current != 0){ 
//                 v.erase(v.begin()+current-1);
//                 current--;
//                 }
//             break;
//         case 'P':
//             char add;
//             cin>>add;
//             v.insert(v.begin()+current,add);
//             if(current != v.size()){ current++;}
//             break;
//         }

//     }

//     for(char c:v) cout<<c;

//     return 0;
// }

#include <cstdio>
#include <string>
#include <iostream> 
#include <list>

using namespace std; 

int n, k; 
string s; 
char temp, _plus; 
list<char> L; 

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> n; 

    for(char c : s) L.push_back(c);

    auto pos = L.end();  

    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp == 'P'){
            cin >> _plus; 
            L.insert(pos, _plus); 
        }else if(temp == 'L'){
            if(pos != L.begin()) pos--; 
        }else if(temp == 'D'){
            if(pos != L.end()) pos++; 
        }else if(temp == 'B'){ 
            if(pos != L.begin()){
                pos--; 
                pos = L.erase(pos);
            } 
        } 
    }
    for(char c : L) cout << c; 
    return 0;
} 