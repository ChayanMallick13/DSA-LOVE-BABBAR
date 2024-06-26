//   https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h> 

void solve(vector<int> & nums,int sum,int & ans,int i){
    if(i>=nums.size()){
        if(sum>ans){
            ans = sum;
        }
        return;
    }

    //exclude
    solve(nums,sum,ans,i+1);
    //include
    sum+=nums[i];
    solve(nums,sum,ans,i+2);
}
int maximumNonAdjacentSum(vector<int> &nums){
    
    //recursive solution
    int ans = 0;
    solve(nums,0,ans,0);
    return ans;
}
