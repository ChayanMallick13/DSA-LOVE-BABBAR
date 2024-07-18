// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/







class Solution {
    int solve(int deals, int buy, int curr, vector<int>& prices) {
        if (curr >= prices.size()) {
            return 0;
        }
        if (deals == 0) {
            return 0;
        }

        int profit;

        if (buy) {
            profit = max(-prices[curr] + solve(deals, 0, curr + 1, prices),
                         solve(deals, buy, curr + 1, prices));
        } else {
            profit = max(prices[curr] + solve(deals - 1, 1, curr + 1, prices),
                         solve(deals, 0, curr + 1, prices));
        }

        return profit;
    }

    int solve_mem(int deals, int buy, int curr, vector<int>& prices,
                  vector<vector<vector<int>>>& dp) {
        if (curr >= prices.size()) {
            return 0;
        }
        if (deals == -1) {
            return 0;
        }
        if (dp[deals][curr][buy] != -1) {
            return dp[deals][curr][buy];
        }

        int profit;

        if (buy) {
            profit =
                max(-prices[curr] + solve_mem(deals, 0, curr + 1, prices, dp),
                    solve_mem(deals, buy, curr + 1, prices, dp));
        } else {
            profit = max(prices[curr] +
                             solve_mem(deals - 1, 1, curr + 1, prices, dp),
                         solve_mem(deals, 0, curr + 1, prices, dp));
        }

        return dp[deals][curr][buy] = profit;
    }
    int solve_tabu(vector<int>& prices) {
        vector<vector<vector<int>>> tab(
            3, vector<vector<int>>(prices.size()+1, vector<int>(2, 0)));

        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 1; k <= 2; k++) {
                    int profit = 0;
                    if (j) {
                        profit =
                            max(-prices[i] +
                                     tab[k][i+1][0],
                                tab[k][i+1][j]);
                    } else {
                        profit =
                            max(prices[i] +  tab[k-1][i+1][1],
                                 tab[k][i+1][0]);
                    }
                    tab[k][i][j] = profit;
                }
            }
        }
        return tab[2][0][1];
    }

    int sp_op(vector<int>& prices){
        vector<vector<vector<int>>> tab(3,vector<vector<int>>(2,vector<int>(2,0)));
        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 1; k <= 2; k++) {
                    int profit = 0;
                    if (j) {
                        profit =
                            max(-prices[i] +
                                     tab[k][1][0],
                                tab[k][1][j]);
                    } else {
                        profit =
                            max(prices[i] +  tab[k-1][1][1],
                                 tab[k][1][0]);
                    }
                    tab[k][0][j] = profit;
                }
            }
            tab[2][1] = tab[2][0];
            tab[1][1] = tab[1][0];
        }
        return tab[2][0][1];
    }

public:
    int maxProfit(vector<int>& prices) {
        // vector<vector<vector<int>>> dp(
        //     2, vector<vector<int>>(prices.size(), vector<int>(2, -1)));
        // return solve(2,1,0,prices);
        // return solve_mem(1, 1, 0, prices, dp);
        // return solve_tabu(prices);
        return sp_op(prices);
    }
};
