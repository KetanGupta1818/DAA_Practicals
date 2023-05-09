import java.util.*;
public class Main {
    private static int[] temp;
    private static int[] nums;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();
        nums = new int[n];
        System.out.print("Enter " + n + " numbers: ");
        for(int i=0;i<n;i++) nums[i] = sc.nextInt();
        temp = new int[n];
        mergeSort(0,n-1);
        System.out.println("The sorted array is: " + Arrays.toString(nums));
    }
    private static void merge(int l1, int r1, int l2, int r2){
        int len = r2-l1+1,start=l1;
        for(int i=0;i<len;i++){
            if(l1<=r1 && l2<=r2){
                if(nums[l1]>=nums[l2]) temp[i] = nums[l2++];
                else temp[i] = nums[l1++];
            }
            else if(l1<=r1) temp[i] = nums[l1++];
            else temp[i] = nums[l2++];
        }
        for(int i=start;i<start+len;i++) nums[i] = temp[i-start];
    }
    private static void mergeSort(int l, int r){
        if(l>=r) return;
        int mid = l+(r-l)/2;
        mergeSort(l,mid);
        mergeSort(mid+1,r);
        merge(l,mid,mid+1,r);
    }
}
