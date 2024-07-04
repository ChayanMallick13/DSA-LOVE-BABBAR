//    https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/






#define lim 1000000007

class Solution {
public:
    int solve(int target,int k,int n){
        if(target==0 )
            return 1;
        if(n == 0)
            return 0;
        
        int ans  = 0;

        for(int i = 1;i<=k;i++){
            if(target-i>=0)
                ans += solve(target-i,k,n-1);
        }

        return ans;
        

    }


    int solve_mem(int target,int k,int n,vector<vector<int>> & dp){
        if(target == 0 && n == 0)
            return 1;
        if(target==0 && n!=0)
            return 0;
        if(n == 0)
            return 0;
        if(dp[n][target]!=-1){
            return dp[n][target];
        }

        int ans  = 0;

        for(int i = 1;i<=k;i++){
            if(target-i>=0)
                ans = (ans + solve_mem(target-i,k,n-1,dp)  )%lim;
            else
                break;
        }

        dp[n][target]  = ans;

        return ans;
        

    }


    int tabu(int n, int k, int target){
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[0][0] = 1;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=target;j++){
                int ans = 0;
                for(int val = 1;val<=k;val++){
                    if(j-val>=0){
                        ans = (ans + dp[i-1][j-val])%lim;
                    }
                }
                dp[i][j] = ans;
            }
        }

        return dp[n][target];
    }

    int sp_op(int n, int k, int target){
        vector<int> dp(target+1,0);
        dp[0] = 1;
        for(int i = 1;i<=n;i++){
            for(int j = target;j>=1;j--){
                int ans = 0;
                for(int val = 1;val<=k;val++){
                    if(j-val>=0){
                        ans = (ans + dp[j-val])%lim;
                    }
                }
                dp[j] = ans;
            }
            dp[0]=0;
        }

        return dp[target];
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        // return solve(target,k,n);
        // return solve_mem(target,k,n,dp);
        // return tabu(n,k,target);
        return sp_op(n,k,target);
    }
};
