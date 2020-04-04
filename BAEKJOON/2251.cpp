/*
8 9 10
*/

#include <cstdio>
#include <iostream>

using namespace std;

struct Basket{
    int size;
    int water;
};

bool chk[201][201][201];
Basket basket[4];
bool result[201];

int fromAToB(int x, int y){
    //x의 물을 y에게
    int howMany = 0;

    if(basket[x].water<basket[y].size-basket[y].water){
        howMany = basket[x].water;
        basket[y].water += basket[x].water;
        basket[x].water = 0;
    }else{
        basket[x].water -= (basket[y].size-basket[y].water);
        howMany = (basket[y].size-basket[y].water);
        basket[y].water = basket[y].size;
    }

    return howMany;
}

void giveWater(){
    if(chk[basket[1].water][basket[2].water][basket[3].water] == false){
        chk[basket[1].water][basket[2].water][basket[3].water] = true;

        if(basket[1].water == 0){
            result[basket[3].water] = true;
        }

        for(int i=1; i<=3; i++){
            if(basket[i].water >0){
                int temp = fromAToB(i,(i+1)%3+1);
                giveWater();
                basket[(i+1)%3+1].water -=temp;
                basket[i].water +=temp;

                temp = fromAToB(i,(i+3)%3+1);
                giveWater();
                basket[(i+3)%3+1].water -=temp;
                basket[i].water +=temp;
            }
        }
    }
}

int main(){
    cin>>basket[1].size>>basket[2].size>>basket[3].size;

    basket[3].water = basket[3].size;
    basket[1].water = 0;
    basket[2].water = 0;

    giveWater();

    for(int i=0; i<201; i++){
        if(result[i] == true){
            cout<<i<<' ';
        }
    }

    return 0;
}