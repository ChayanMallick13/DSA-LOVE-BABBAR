// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/





class Solution {
private:
    int solve(int curr,vector<int> & cost,int buy){
        if(curr>=cost.size()){
            return 0;
        }
        int profit = INT_MIN;
        if(buy){
            profit = max( -cost[curr] + solve(curr+1,cost,0),solve(curr+1,cost,1));
        }
        else{
            profit = max( cost[curr] + solve(curr+1,cost,1) , solve(curr+1,cost,0));
        }
        return profit;
    }

    int solve_mem(int curr,vector<int> & cost,int buy,vector<vector<int>> & dp){
        if(curr>=cost.size()){
            return 0;
        }
        if(dp[curr][buy]!=-1){
            return dp[curr][buy];
        }
        int profit = INT_MIN;
        if(buy){
            profit = max( -cost[curr] + solve_mem(curr+1,cost,0,dp),solve_mem(curr+1,cost,1,dp));
        }
        else{
            profit = max( cost[curr] + solve_mem(curr+1,cost,1,dp) , solve_mem(curr+1,cost,0,dp));
        }
        return dp[curr][buy] = profit;
    }

    int solve_tabu(vector<int> & cost){
        vector<vector<int>> tab(cost.size()+1,vector<int>(2,0));
        for(int i = cost.size()-1;i>=0;i--){
            for(int j = 0;j<=1;j++){
                int profit;
                if(j==0){
                    profit = max(cost[i] + tab[i+1][1],tab[i+1][0]);
                }
                else{
                    profit = max(-cost[i] + tab[i+1][0] , tab[i+1][1]);
                }
                tab[i][j] = profit;
            }
        }
        return tab[0][1];
    }

    int sp_op(vector<int> & cost){
        int pbuy,psell;
        pbuy = psell = 0;
        for(int i = cost.size()-1;i>=0;i--){
            for(int j = 0;j<2;j++){
                int cbuy,csell;
                if(j==0){
                    csell = max(cost[i] + pbuy,psell);
                    psell = csell;
                }
                else{
                    cbuy = max(-cost[i]+psell,pbuy);
                    pbuy = cbuy;
                }
            }
        }
        return pbuy;
    }
public:
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        // return solve(0,prices,1);
        // return solve_mem(0,prices,1,dp);
        // return solve_tabu(prices);
        return sp_op(prices);
    }
};
