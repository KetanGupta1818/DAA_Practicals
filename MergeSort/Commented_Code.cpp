#include<bits/stdc++.h>
using namespace std;
int n; //Number of elements in the array
int nums[10000],temp[10000]; // int temp[] will be needed to store the intermediate array while merging


//merges 2 sorted segements of an array
// l1 start of 1st segment
// r1 end of 1st segment
// l2 start of 2nd segment
// r2 end of 2nd segment
void merge(int l1, int r1, int l2, int r2){
    //len -> represents the combined length of 2 segments
    //start -> represents the start of the first segment
    int len = r2-l1+1,start=l1;
    /*
        Use 2 pointers techinque to merge 2 sorted array
        This is a well known problem. Refer this https://leetcode.com/problems/merge-sorted-array/
    */
    for(int i=0;i<len;i++){
        if(l1<=r1 && l2<=r2){
            if(nums[l1]>=nums[l2]) temp[i] = nums[l2++];
            else temp[i] = nums[l1++];
        }
        else if(l1<=r1) temp[i] = nums[l1++];
        else temp[i] = nums[l2++];
    }
    //The result gets sorted in temp array, so coppy it in nums array
    for(int i=start;i<start+len;i++) nums[i] = temp[i-start];
}
void mergeSort(int l, int r){
    //if their are less than 2 elements in the current segment, then return
    if(l>=r) return;

    //break the segment into two parts (Divide)
    int mid = l+(r-l)/2;

    //solve the first part
    mergeSort(l,mid);

    //solve the second part
    mergeSort(mid+1,r);

    //merge both parts (Conqure)
    merge(l,mid,mid+1,r);
}
int main(){
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for(int i=0;i<n;i++) cin >> nums[i];
    mergeSort(0,n-1);
    cout << "The sorted array is: ";
    for(int i=0;i<n-1;i++) cout << nums[i] << ", ";
    cout << nums[n-1] << "\n";
} 
