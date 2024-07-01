/*
[ 2007년 ]
https://www.acmicpc.net/problem/1924

문제
오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨 요일일까? 이를 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 빈 칸을 사이에 두고 x(1≤x≤12)와 y(1≤y≤31)이 주어진다. 참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.

출력
첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.

예제 입력 1 
1 1
예제 출력 1 
MON
예제 입력 2 
3 14
예제 출력 2 
WED
예제 입력 3 
9 2
예제 출력 3 
SUN
예제 입력 4 
12 25
예제 출력 4 
TUE

*/

#include <cstdio>
#include <iostream>
#include <string>

//SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.
//0,1,2,3,4,5,6
using namespace std;
int x,y;
string arr[7] = {"SUN","MON","TUE", "WED","THU","FRI","SAT"};

int main(){
    //2007. 1. 1. 월
    //2007. x. y?
    cin>>x>>y;

    //2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.
    // 1월 31 y%7 0-6(일 - 토)
    // 2월 28 y%7 (수 - 화)
    // 3월 31 y%7 (수 - 화)
    // 4/30 (토 - 금) 월
    // 5/31 (월 - 일) 목
    // 6/30 (목 - 수)
    // 7/31 (토 - 금)
    // 8/31 (화 - 월)
    // 9/30 (금 - 목)
    // 10/31 (일 - 토)
    // 11/30 (수 - 화)
    // 12/31 (금 - 목)

    int div = 0;

    switch(x){
        case 1://일
        case 10:
        div = y%7;
        break;

        case 2://수
        case 3:
        case 11:
        div = (y+3)%7;
        break;

        case 4://토
        case 7:
        div = (y+6)%7;
        break;

        case 5://월
        div = (y+1)%7;
        break;

        case 6://목
        div = (y+4)%7;
        break;

        case 8://화
        div = (y+2)%7;
        break;

        case 9://금
        case 12:
        div = (y+5)%7;
        break;
    }

    cout<<arr[div];



    return 0;
}