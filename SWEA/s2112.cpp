/*
보호필름
6 8 3         
0 0 1 0 1 0 0 1
0 1 0 0 0 1 1 1
0 1 1 1 0 0 0 0
1 1 1 1 0 0 0 1
0 1 1 0 1 0 0 1
1 0 1 0 1 1 0 1

2
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int h,w,k;
int T;
int arr[14][21];
bool flag;
vector<int> v;

bool check(){
    //판정하기
    for (int i = 0; i < w; i++) {
		bool chk1 = false;
		for (int j = 0; j <= h - k; j++) {
			bool chk2 = false;
			for (int z = j + 1; z < j + k; z++) {
				if (arr[j][i] != arr[z][i]) {
					chk2 = true;
					break;
				}
			}
			if (chk2 == false) {
				chk1 = true;
				break;
			}
		}
		if (chk1 == false) {
			return false;
		}
	}
	return true;

}

void fillAB(int x){
    //0 또는 1로 가로줄 채우기
    if(x == v.size()){

        if(check() == true){
            flag = true;
        }

    }else{
        int temp[20];

        for(int i=0; i<w; i++){
            temp[i] = arr[v[x]][i];
        }

        for(int i=0; i<w; i++){
            arr[v[x]][i] = 0;
        }
        fillAB(x+1);

        for(int i=0; i<w; i++){
            arr[v[x]][i] = 1;
        }
        fillAB(x+1);

        for(int i=0; i<w; i++){
            arr[v[x]][i] = temp[i];
        }
    }
}

void found(int x,int a,int s){
    //a개 찾아서 v에 넣기 조합
    if(x == a){
        fillAB(0);
    }else{
        for(int i=s; i<h; i++){
            v.push_back(i);
            found(x+1,a,i+1);
            v.pop_back();
        }
    }
}

int main(){
    cin>>T;

    for(int t=1; t<=T; t++){
        cin>>h>>w>>k;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>arr[i][j];
            }
        }
        //init
        v.clear();
        flag = false;
        //init
        for(int i=0; i<=h; i++){
            found(0,i,0);
            if(flag == true){
                cout<<"#"<<t<<' '<<i<<'\n';
                break;
            }
        }
    }

    return 0;
}