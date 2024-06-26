

//   https://www.naukri.com/code360/problems/minimum-elements_3843091?leftPanelTab=0&leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h> 
int solve(vector<int> &num, int x){
    if(x==0){
        return 0;
    }
    if(x<0){
        return -1;
    }

    int ans = INT_MAX;
    for(auto i : num){
        int temp = solve(num, x-i);
        if(temp!=-1){
            ans = min(ans,temp+1);
        }
    }
    if(ans==INT_MAX){
        return -1;
    }
    return ans;
}
int minimumElements(vector<int> &num, int x)
{
    return solve(num, x);
}
