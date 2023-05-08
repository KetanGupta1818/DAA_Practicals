#include<bits/stdc++.h>
using namespace std;
long long solve(int index, int wr, int weights[], int profits[], vector<vector<long long>>& dp,int n){
    if(index == n) return 0;
    if(dp[index][wr] != -1) return dp[index][wr];
    long long p = solve(index+1,wr,weights,profits,dp,n);
    if(weights[index]<=wr) p = max(p,solve(index+1,wr-weights[index],weights,profits,dp,n)+profits[index]);
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
    vector<vector<long long>> dp(n,vector<long long>(100001,-1));
    long long ans = solve(0,w,weights,profits,dp,n);
    cout << "maximum profit is " << ans << endl;
} 
