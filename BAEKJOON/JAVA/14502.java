import java.util.*;
import java.io.*;
/*
https://www.acmicpc.net/problem/14502
첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)
둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.
빈 칸의 개수는 3개 이상이다.

1. 입력
2. 임의의 벽 3개 할당
3. 바이러스 확산 및 카운팅
*/
class Point {
    int x;
    int y;

    Point(int x, int y){
        this.x = x;
        this.y = y;
    }
}

public class Main {
    public static int n, m;
    public static String[][]arr = new String[10][10];
    public static Boolean[][]chk = new Boolean[10][10];
    public static int[] dx = {0,0,1,-1};
    public static int[] dy = {1,-1,0,0};
    public static int result = 0;
    public static int totSafe = 0;
    public static ArrayList<Point> v= new ArrayList<>();
    public static ArrayList<Point> virus = new ArrayList<>();
        
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        
        for(int i=0; i<n; i++){
            String[] str = br.readLine().split(" ");
            for(int j=0; j<m; j++){
                arr[i][j] = str[j];
                if("0".equals(arr[i][j])){
                    v.add(new Point(i, j));
                    totSafe++;
                }else if("2".equals(arr[i][j])){
                    virus.add(new Point(i, j));
                }
            }
        }
        
        //1. 임의의 벽 3개 할당
        totSafe = totSafe-3;
        DFS(0);

        System.out.println(result);

    }

    static public void DFS(int x) {
        if(x == 3){
            String[][]tmp = arr.clone();
            for(int i=0; i<n; i++){
                tmp[i] = arr[i].clone();
            }

            int tmpRes = spreadVirus();
            if(result < tmpRes) result = tmpRes;

            for(int i=0; i<n; i++){
                arr[i] = tmp[i].clone();
            }

        }else{
            for(int i=0; i<v.size(); i++){
                if("0".equals(arr[v.get(i).x][v.get(i).y])){
                    arr[v.get(i).x][v.get(i).y] = "1";
                    DFS(x+1);
                    arr[v.get(i).x][v.get(i).y] = "0";
                }
            }
        }
    }

    static public int spreadVirus() {
        int safe = totSafe;
        Queue<Point> q = new LinkedList<>();

        for(int i=0; i<virus.size(); i++){
            q.add(virus.get(i));
        }

        while(q.isEmpty() == false){
            Point p = q.poll();
            int cx = p.x;
            int cy = p.y;
            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                if( nx<0 || ny<0 || nx>=n || ny>=m || "0".equals(arr[nx][ny]) == false) continue;
                else{
                    arr[nx][ny] = "2";
                    q.add(new Point(nx,ny));
                    safe--;
                }
            }
        }
        return safe;
    }
}
