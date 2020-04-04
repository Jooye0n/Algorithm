/*
16939
*/
#include <cstdio>
#include <iostream>
#include <memory.h>

using namespace std;

int inform[6][4][3] = {
	{{1,0,5},{1,0,3},{1,0,1},{1,0,4}},//0
	{{2,3,0},{3,1,3},{1,0,2},{6,2,4}},//1
	{{2,3,1},{2,3,3},{2,3,5},{2,3,4}},//2
	{{0,2,0},{3,1,5},{0,2,2},{0,2,1}},//3
	{{3,1,0},{3,1,1},{3,1,2},{0,2,5}},//4
	{{1,0,0},{3,1,4},{2,3,2},{0,2,3}},//5
};

int arr[6][4];//cube
int temp[6][4];//cube temp

bool testAll(){
	//가능하면 cout<<1 출력하고 return true 한다.
	for(int i=0; i<6; i++){
		if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][2] == arr[i][3] && arr[i][0] == arr[i][3]) continue;
        else return false;
	}
	cout<<1;
	return true;
}

void turnArr(int x, int dir){
	if(dir == 0){//왼쪽으로 돌린다.
		int temp0 = arr[x][0];
		arr[x][0] = arr[x][1];
		arr[x][1] = arr[x][3];
		arr[x][3] = arr[x][2];
		arr[x][2] = temp0;

		//4면 다루기
		int arrTemp[2] = { arr[inform[x][3][2]][inform[x][3][0]] , arr[inform[x][3][2]][inform[x][3][1]]};
		for(int i=3; i>=1; i--){
			arr[inform[x][i][2]][inform[x][i][0]] = arr[inform[x][i-1][2]][inform[x][i-1][0]];
			arr[inform[x][i][2]][inform[x][i][1]] = arr[inform[x][i-1][2]][inform[x][i-1][1]];
		}
		arr[inform[x][0][2]][inform[x][0][0]] = arrTemp[0];
		arr[inform[x][0][2]][inform[x][0][1]] = arrTemp[1];

	}else if(dir == 1){

		int temp0 = arr[x][0];
		arr[x][0] = arr[x][2];
		arr[x][2] = arr[x][3];
		arr[x][3] = arr[x][1];
		arr[x][1] = temp0;

		//4면 다루기
		int arrTemp[2] = { arr[inform[x][0][2]][inform[x][0][0]] , arr[inform[x][0][2]][inform[x][0][1]]};
		for(int i=1; i<=3; i++){
			arr[inform[x][i-1][2]][inform[x][i-1][0]] = arr[inform[x][i][2]][inform[x][i][0]];
			arr[inform[x][i-1][2]][inform[x][i-1][1]] = arr[inform[x][i][2]][inform[x][i][1]];
		}
		arr[inform[x][3][2]][inform[x][3][0]] = arrTemp[0];
		arr[inform[x][3][2]][inform[x][3][1]] = arrTemp[1];
	}
}


int main(){

	for(int i=0 ;i<6; i++){
		for(int j=0; j<4; j++){
			cin>>arr[i][j];
            temp[i][j] = arr[i][j];
		}
	}

	for(int i=0; i<6; i++){
		for(int j=0; j<2; j++){
			memcpy(arr,temp,sizeof(arr));
			turnArr(i,j);//i면을 j==0이면 왼쪽으로 1이면 오른쪽으로 돌린다. 
			if(testAll() == true) return 0;
		}
	}

	cout<<0;
	return 0;

}