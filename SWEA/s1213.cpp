/*
주어지는 영어 문장에서 특정한 문자열의 개수를 반환하는 프로그램을 작성하여라.

Starteatingwellwiththeseeighttipsforhealthyeating,whichcoverthebasicsofahealthydietandgoodnutrition.

위 문장에서 ti 를 검색하면, 답은 4이다.

[제약 사항]

총 10개의 테스트 케이스가 주어진다.

문장의 길이는 1000자를 넘어가지 않는다.

한 문장에서 검색하는 문자열의 길이는 최대 10을 넘지 않는다.

한 문장에서는 하나의 문자열만 검색한다. 

[입력]

각 테스트 케이스의 첫 줄에는 테스트 케이스의 번호가 주어지고 그 다음 줄에는 찾을 문자열, 그 다음 줄에는 검색할 문장이 주어진다.

[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 테스트 케이스의 답을 출력한다.

입력
1
ti
Starteatingwellwiththeseeighttipsforhealthyeating,whichcoverthebasics ...
2
ing
Thedoublehelixformsthestructuralbasisofsemi-conservativeDNAreplication.1,2Less ...
...
test_input.txt
출력
#1 4
#2 2
...
 

 */

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int n;
string temp;
string total;


int main(){
    for(int k=1; k<=10; k++){
        cin>>n;
        
        cin>>temp;
        cin>>total;

        // if(total.find("temp") == string::npos){
        //     cout<<"0\n";
        // }else{
            int x = 0;

            for(int i=0; i<=total.length()-temp.length(); i++){
                if(total.at(i) == temp.at(0)){
                    bool chk = false;
                    for(int j=i+1; j<i+temp.length(); j++){
                        if(total.at(j) != temp.at(j-i)){
                            chk = true;
                            break;
                        }
                    }
                    if(chk == false) {
                        x++;
                    }
                }
            }
            cout<<'#'<<n<<' ';
            cout<<x<<'\n';
       // }
    }
    return 0;
}
