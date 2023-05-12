import java.util.*;
public class Main {
    static int[][] a = {{1,3,2,4},{2,3,4,5},{9,3,2,30},{9,9,3,2}};
    static int[][] b = {{9,4,3,2},{2,3,4,2},{4,3,5,66},{9,4,3,2}};
    static int[][] ans = new int[4][4];
    public static void main(String[] args) {
        for(int i=0;i<4;i++) new Thread(new Multiplier(i)).start();
        System.out.println("answer matrix");
        for(int[] arr: ans) System.out.println(Arrays.toString(arr));
    }
    static class Multiplier implements Runnable {
        int i;
        public Multiplier(int i){
            this.i = i;
        }
        @Override
        public void run() {
            for (int j = 0; j < 4; j++) for (int k = 0; k < 4; k++) ans[i][j] += a[i][k] * b[k][j];
        }
    }
}
