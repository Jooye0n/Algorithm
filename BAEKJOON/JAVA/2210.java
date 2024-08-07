import java.util.*;
import java.io.*;
/*
https://www.acmicpc.net/problem/2210
5×5 크기의 숫자판이 있다. 각각의 칸에는 숫자(digit, 0부터 9까지)가 적혀 있다. 
이 숫자판의 임의의 위치에서 시작해서, 인접해 있는 네 방향으로 다섯 번 이동하면서, 각 칸에 적혀있는 숫자를 차례로 붙이면 6자리의 수가 된다. 
이동을 할 때에는 한 번 거쳤던 칸을 다시 거쳐도 되며, 0으로 시작하는 000123과 같은 수로 만들 수 있다.
숫자판이 주어졌을 때, 만들 수 있는 서로 다른 여섯 자리의 수들의 개수를 구하는 프로그램을 작성하시오.

*/

public class Main {
    static int n = 5;
    static int[] dx = {0,0,1,-1};
    static int[] dy = {1,-1,0,0};
    static String[][] arr = new String[n][n];
    static int result = 0;
    static Map<String, Boolean> map = new HashMap<String, Boolean>();
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int i=0; i<n; i++){
            String[] str = br.readLine().split(" ");
            for(int j=0; j<n; j++){
                arr[i][j] = str[j];
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                DFS(i, j, 0, arr[i][j]);
            }
        }

        System.out.println(result);
    }

    public static void DFS(int cx, int cy, int x, String str){
        if(x == 5){
            if(map.containsKey(str) == false){
                //System.out.println(str);
                map.put(str, true);
                result++;
            }
        }else{
            for(int i=0 ;i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                else{
                    DFS(nx, ny, x+1, str+arr[nx][ny]);
                }
            }
        }
    }

}