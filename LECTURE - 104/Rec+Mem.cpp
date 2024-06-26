


#include <bits/stdc++.h> 
int solve(vector<int> &num, int x,vector<int> &dp){
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }
    if(dp[x]!=-1){
        return dp[x];
    }

    int ans = INT_MAX;
    for(auto i : num){
        int temp = solve(num, x-i,dp);
        if(temp!=INT_MAX){
            ans = min(ans,temp+1);
        }
    }
    dp[x]=ans;
    return ans;
}
int minimumElements(vector<int> &num, int x)
{
    vector<int> dp(x+1,-1);
    int ans = solve(num, x,dp);
    if(ans==INT_MAX){
        return -1;
    }
    return ans;
}
