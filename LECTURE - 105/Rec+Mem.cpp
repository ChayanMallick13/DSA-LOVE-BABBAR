
#include <bits/stdc++.h> 
int solve(vector<int> &nums,int i,vector<int> &dp){
    if(i<0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }

    int inclu = solve(nums, i-2,dp)+nums[i];
    int exclu = solve(nums, i-1,dp);
    dp[i]= max(inclu,exclu);
    return dp[i];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n,-1);
    return solve(nums, n-1,dp);
}
