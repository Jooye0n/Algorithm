/*
5 3 1
1 6
3 5
2 8
*/

#include <stdio.h>
#include <stdlib.h>

using namespace std;
int a,b,c;//100
int chk[101];
int n=3;
int result;

int main(){
    scanf("%d %d %d",&a, &b, &c);

    while(n--){
        int start, end;
        scanf("%d %d",&start, &end);
        for(int i=start; i<end; i++){
            chk[i]++;
        }
    }

    for(int i=1; i<101; i++){
        if(chk[i]==1){
            result += a;
        }else if(chk[i]==2){
            result += b*2;
        }else if(chk[i]==3){
            result += c*3;
        }
    }

    printf("%d",result);
    return 0;
}