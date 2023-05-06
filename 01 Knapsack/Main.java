import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements ");
        int n = sc.nextInt();
        System.out.print("Enter the maximum weight ");
        int w = sc.nextInt();
        System.out.print("Enter " + n + " weights ");
        int[] weights = new int[n],profits = new int[n];
        for(int i=0;i<n;i++) weights[i] = sc.nextInt();
        System.out.print("Enter " + n + " profits ");
        for(int i=0;i<n;i++) profits[i] = sc.nextInt();
        long[][] dp = new long[n][100001];
        for(long[] d: dp) Arrays.fill(d,-1);
        long ans = solve(0,w,weights,profits,dp);
        System.out.println("Maximum profit is " + ans);
    }
    private static long solve(int index, int wr,int[] weights,int[] profits,long[][] dp){
        if(index == weights.length) return 0;
        if(dp[index][wr] != -1) return dp[index][wr];
        long p = solve(index+1,wr,weights,profits,dp);
        if(weights[index]<=wr) p = Math.max(p,solve(index+1,wr-weights[index],weights,profits,dp)+profits[index]);
        return dp[index][wr] = p;
    }

}
