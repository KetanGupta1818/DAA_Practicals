#include<bits/stdc++.h>
using namespace std;
int nums[100000],n; 
void swap(int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
void quickSort(int l, int r){
    if(l>=r) return;
    int pivot = nums[l],i=l,j=r;
    while(i<=j){
        while(i<=j && nums[i]<=pivot) i++;
        while(i<=j && nums[j]>pivot) j--;
        if(i<=j) swap(i,j);
    }
    swap(l,i-1);
    quickSort(l,i-2);
    quickSort(i,r);
}
int main(){
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for(int i=0;i<n;i++) cin >> nums[i];
    quickSort(0,n-1);
    cout << "The sorted array is: ";
    for(int i=0;i<n-1;i++) cout << nums[i] << ", ";
    cout << nums[n-1] << "\n";
}
