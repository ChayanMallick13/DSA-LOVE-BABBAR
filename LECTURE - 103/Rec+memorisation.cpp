

class Solution {
public:
    int solve(vector<int>& cost,int pos,vector<int> & dp) {

        //BASE
        if(pos==0){
            return cost[0];
        }
        if(pos==1){
            return cost[1];
        }

      // step 3
        if(dp[pos]!=-1){
            return dp[pos];
        }

        // step 2
        dp[pos] = min(solve(cost,pos-1,dp),solve(cost,pos-2,dp))+cost[pos];
        return dp[pos];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
      //step 1
        vector<int> dp(n,-1);
        return min(solve(cost,n-1,dp),solve(cost,n-2,dp));
    }
};
