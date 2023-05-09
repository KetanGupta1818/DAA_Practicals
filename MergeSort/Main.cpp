#include<bits/stdc++.h>
using namespace std;
int n;
int nums[10000],temp[10000];
void merge(int l1, int r1, int l2, int r2){
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
void mergeSort(int l, int r){
    if(l>=r) return;
    int mid = l+(r-l)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
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
