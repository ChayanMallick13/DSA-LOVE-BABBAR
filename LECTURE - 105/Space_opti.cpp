#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    int prev1 = 0;
    int prev2 = 0;
    for(int i = 0;i<n;i++){
        int curr;
        curr=max(prev1,prev2+nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
