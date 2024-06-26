

#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> tabu(n);
    // tabu.push_front(0);
    tabu[0]=nums[0];
    for(int i = 1;i<=n;i++){
        tabu[i]=max(tabu[i-1],tabu[i-2]+nums[i]);
    }
    return tabu[n-1];
}
