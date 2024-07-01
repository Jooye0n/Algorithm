#include <stdio.h>
int visit[1000001];
int Ans= 1000001;
int boool;
int isAllFloor, isGangHo, isObj;
int Up, Down;

// 층수 1~최대층인지 체크
int safe(int Value)
{
return (Value >= 1 && Value <= isAllFloor);
}

void DFS(int local, int count)
{
if (local == isObj)
{
// 최소값을 찾는 것이기 때문에 계속 최솟값 찾기.
if (Ans > count)
Ans = count;
boool = 1;
return;
}

// 시간을 줄이기 위한 visit체크
visit[local] = 1;

// 1~최대층 사이에 해당되고, 방문하지 않았다면 방문.
if (safe(local + Up) && visit[local + Up] == 0)
DFS(local + Up, count + 1);

if (safe(local - Down) && visit[local - Down] == 0)
DFS(local - Down, count + 1);

return;
}

int main()
{
scanf("%d%d%d%d%d", &isAllFloor, &isGangHo, &isObj, &Up, &Down);

// 만약 목적층이랑 같은 층이라면 0출력하고 끝
if (isGangHo == isObj)
{
printf("0\n");
return 0;
}

// 아니라면 DFS
DFS(isGangHo, 0);

if (boool)
printf("%d\n", Ans);
else
printf("use the stairs\n");

return 0;
}