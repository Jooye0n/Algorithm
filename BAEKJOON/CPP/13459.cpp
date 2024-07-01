#include <bits/stdc++.h>
using namespace std;

struct point {
   int x;
   int y;
};

struct marvel {
   point red;
   point blue;
};

int n, m;
char arr[10][10];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

marvel moveArr(int dir, point red, point blue) {
   point newRed, nexBlue;
   int cx = red.x;
   int cy = red.y;
   bool flag = false;
   while (true) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (arr[nx][ny] == '#') {
         if (flag == true) {
            newRed.x = cx-dx[dir];
            newRed.y = cy-dy[dir];
         }
         else {
            newRed.x = cx;
            newRed.y = cy;
         }
         break;
      }else if (arr[nx][ny] == 'O') {
         newRed.x = nx;
         newRed.y = ny;
         break;
      }
      if (nx == blue.x && ny == blue.y) {
         flag = true;
      }
      cx = nx; cy = ny;
   }

   cx = blue.x;
   cy = blue.y;
   flag = false;

   while (true) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (arr[nx][ny] == '#') {
         if (flag == true) {
            nexBlue.x = cx - dx[dir];
            nexBlue.y = cy - dy[dir];
         }
         else {
            nexBlue.x = cx;
            nexBlue.y = cy;
         }
         break;
      }else if (arr[nx][ny] == 'O') {
         nexBlue.x = nx;
         nexBlue.y = ny;
         break;
      }
      if (nx == red.x && ny == red.y) {
         flag = true;
      }
      cx = nx; cy = ny;
   }
   if (arr[newRed.x][newRed.y] == 'O' && arr[nexBlue.x][nexBlue.y] != 'O') {
      cout << 1;
      exit(0);
   }
   return { newRed,nexBlue };
}

void DFS(int x, int dir, point red, point blue) {
   if (x == 10) return;
   for (int i = 0; i < 4; i++) {
      if (i == dir) continue;
      //arr에 구슬 굴리기
      marvel mar = moveArr(i, red, blue);
      if (arr[mar.blue.x][mar.blue.y] == 'O') {//실패
         continue;
      }
      else DFS(x + 1, i, mar.red, mar.blue);
   }
}
int main() {
   point redP, blueP;
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      string s; cin >> s;
      for (int j = 0; j < m; j++) {
         arr[i][j] = s[j];
         if (arr[i][j] == 'R') {
            redP.x = i;
            redP.y = j;
            arr[i][j] = '.';
         }
         else if (arr[i][j] == 'B') {
            blueP.x = i;
            blueP.y = j;
            arr[i][j] = '.';
         }
      }
   }

   DFS(0, -1, redP, blueP);
   cout << 0;
   return 0;
}