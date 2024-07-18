// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/



class Solution {
    int solve(int curr,int ops,vector<int> & prices,int k){
        if(curr>=prices.size()){
            return 0;
        }
        if(ops==2*k){
            return 0;
        }

        int profit;

        //buy
        if(ops%2==0){
            profit = max( -prices[curr] + solve(curr+1,ops+1,prices,k),solve(curr+1,ops,prices,k));
        }

        //sell
        else{
            profit = max(prices[curr] + solve(curr+1,ops+1,prices,k),solve(curr+1,ops,prices,k));
        }
        return profit;
    }

    int solve_mem(int curr,int ops,vector<int> & prices,int k,vector<vector<int>> & dp){
        if(curr>=prices.size()){
            return 0;
        }
        if(ops==2*k){
            return 0;
        }
        if(dp[curr][ops]!=-1){
            return dp[curr][ops];
        }

        int profit;

        //buy
        if(ops%2==0){
            profit = max( -prices[curr] + solve_mem(curr+1,ops+1,prices,k,dp),solve_mem(curr+1,ops,prices,k,dp));
        }

        //sell
        else{
            profit = max(prices[curr] + solve_mem(curr+1,ops+1,prices,k,dp),solve_mem(curr+1,ops,prices,k,dp));
        }
        return dp[curr][ops] = profit;
    }

    int solve_tab(vector<int> & prices,int k){
        vector<vector<int>> dp(prices.size()+1, vector<int>(2*k+1,0));

        for(int i = prices.size()-1;i>=0;i--){

            for(int j = 2*k-1;j>=0;j--){
                int profit;
                if(j%2){
                    profit = max(prices[i]+dp[i+1][j+1],dp[i+1][j]);
                }
                else{
                    profit = max( - prices[i] + dp[i+1][j+1] , dp[i+1][j]);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][0];
    }

    int sp_op(int k, vector<int>& prices){
        vector<int> prev(2*k+1,0),curr(2*k+1,0);
        for(int i = prices.size()-1;i>=0;i--){

            for(int j = 2*k-1;j>=0;j--){
                int profit;
                if(j%2){
                    profit = max(prices[i]+prev[j+1],prev[j]);
                }
                else{
                    profit = max( - prices[i] + prev[j+1] , prev[j]);
                }
                curr[j] = profit;
            }
            prev = curr;

        }
        return prev[0];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2*k,-1));
        // return solve(0,0,prices,k);
        // return solve_mem(0,0,prices,k,dp);
        // return solve_tab(prices,k);
        return sp_op(k,prices);
    }
};
