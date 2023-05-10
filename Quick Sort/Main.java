import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();
        int[] nums = new int[n];
        System.out.print("Enter " + n + " numbers: ");
        for(int i=0;i<n;i++) nums[i] = sc.nextInt();
        quickSort(0,n-1, nums);
        System.out.println("The sorted array is: " + Arrays.toString(nums));
    }
    private static void quickSort(int l, int r,int[] nums){
        if(l>=r) return;
        int pivot = nums[l],i=l,j=r;
        while(i<=j){
            while(i<=j && nums[i]<=pivot) i++;
            while(i<=j && nums[j]>pivot) j--;
            if(i<=j) swap(i,j,nums);
        }
        swap(l,i-1,nums);
        quickSort(l,i-2,nums);
        quickSort(i,r,nums);
    }
    private static void swap(int i, int j, int[] nums){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
