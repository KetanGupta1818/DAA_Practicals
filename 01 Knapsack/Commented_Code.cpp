/*
In 0/1 knapsnack we have to options at any state
    1) dont select current state (0)
    2) select current state (1)
*/


#include<bits/stdc++.h>
using namespace std;
/*
DP state dp[index][wr]
index -> represents element of the arr
wr -> weight remaining with us (the total weight which we can add to our kanpsack) 
*/
long long solve(int index, int wr, int weights[], int profits[], vector<vector<long long>>& dp,int n){
    //All elements have been processed, return 0 
    if(index == n) return 0;
  
    //If this state is seen before then return the value which was previously calculated
    if(dp[index][wr] != -1) return dp[index][wr];
  
    //Do not select the current element
    long long p = solve(index+1,wr,weights,profits,dp,n);
  
    //Select the current element if remaining weight is greater than or equal to current weight
    if(weights[index]<=wr) p = max(p,solve(index+1,wr-weights[index],weights,profits,dp,n)+profits[index]);
  
    //store the value in dp matrix
    return dp[index][wr] = p;
} 
int main(){
    int n,w;
    cout << "Enter the number of elements: " ;
    cin >> n;
    cout << "Enter the maximum weight: ";
    cin >> w;
    cout << "Enter " << n << " weights: ";
    int weights[n];
    for(int i=0;i<n;i++) cin >> weights[i];
    cout << "Enter " << n << " profits: ";
    int profits[n];
    for(int i=0;i<n;i++) cin >> profits[i];
    //Initialise the dp matrix with -1, -1 represents that this state in dp is not visited
    vector<vector<long long>> dp(n,vector<long long>(100001,-1));
    long long ans = solve(0,w,weights,profits,dp,n);
    cout << "maximum profit is " << ans << endl;
} 
/*
Time complexity -> O(N*W)
Space Complexity -> O(N*W)
*/
