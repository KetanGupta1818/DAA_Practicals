/*
Quick sort uses divide and conqure technique to sort the array.

In this code pivot is always the first element, so worst case time complexity in n*n when the array is already sorted
*/
#include<bits/stdc++.h>
using namespace std;
int nums[100000],n; 

//Code to swap to elements in nums array
void swap(int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}


void quickSort(int l, int r){
    //if there are less than 2 elements in the array, return
    if(l>=r) return;

    /*
        Select the first element as the pivot.
        All numbers less than pivot are placed on the left side and greater than pivot on the right side
        Use the 2 pointers to divide the array based on pivot
    */
    int pivot = nums[l],i=l,j=r;
    while(i<=j){
        while(i<=j && nums[i]<=pivot) i++;
        while(i<=j && nums[j]>pivot) j--;
        if(i<=j) swap(i,j);
    }
    //Place the pivot in middle
    swap(l,i-1);
    //Solve the left part of pivot
    quickSort(l,i-2);
    //Solve the right part of pivot
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
