//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/



class Solution {
    int solve(int curr,int buy,vector<int> & prices,int fee){

        if(curr>=prices.size()){
            return 0;
        }

        int profit;
        if(buy){
            profit = max( -prices[curr]-fee+solve(curr,0,prices,fee),solve(curr+1,buy,prices,fee));
        }
        else{
            profit = max(prices[curr] + solve(curr+1,1,prices,fee),solve(curr+1,buy,prices,fee));
        }   

        return profit;

    }


    int solve_mem(int curr,int buy,vector<int> & prices,int fee,vector<vector<int>> & dp){

        if(curr>=prices.size()){
            return 0;
        }
        if(dp[curr][buy]!=-1){
            return dp[curr][buy];
        }

        int profit;
        if(buy){
            profit = max( -prices[curr]-fee+solve_mem(curr,0,prices,fee,dp),solve_mem(curr+1,buy,prices,fee,dp));
        }
        else{
            profit = max(prices[curr] + solve_mem(curr+1,1,prices,fee,dp),solve_mem(curr+1,buy,prices,fee,dp));
        }   

        return dp[curr][buy] = profit;

    }

    int solve_tabu(vector<int>& prices, int fee){
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        for(int i = prices.size()-1;i>=0;i--){
            for(int j = 0;j<2;j++){
                int profit;
                if(j){
                    profit = max( -prices[i]-fee+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    profit = max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                dp[i][j]  = profit;
            }
        }
        return dp[0][1];
    }
    int sp_op(vector<int>& prices, int fee){
        int nsell,nbuy,psell,pbuy;
        psell = pbuy = 0;

        for(int i = prices.size()-1;i>=0;i--){
            for(int j = 0;j<2;j++){
                int profit;
                if(j){
                    profit = max( -prices[i]-fee+psell,pbuy);
                    nbuy = profit;
                }
                else{
                    profit = max(prices[i]+pbuy,psell);
                    nsell = profit;
                }
            }
            psell = nsell;
            pbuy = nbuy;
        }

        return pbuy;

    }
public:
    int maxProfit(vector<int>& prices, int fee) {

        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        // return solve(0,1,prices,fee);
        // return solve_mem(0,1,prices,fee,dp);
        // return solve_tabu(prices,fee);
        return sp_op(prices,fee);

    }
};
