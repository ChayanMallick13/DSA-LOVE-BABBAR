//   https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1





class Solution {

private:
    // Simple recursive function without memoization
    int solve(vector<int>& s, int i, int time) {
        // Agar index i list se bahar ho jaye, return 0
        if (i >= s.size()) {
            return 0;
        }

        // Do possibilities: ya to current element na lo, ya current element lo aur time increment karo
        return max(solve(s, i + 1, time), s[i] * time + solve(s, i + 1, time + 1));
    }

    // Recursive function with memoization
    int solve_mem(vector<int>& s, int i, int time, vector<vector<int>>& dp) {
        // Agar index i list se bahar ho jaye, return 0
        if (i >= s.size()) {
            return 0;
        }
        // Agar result memoized hai to direct return kar do
        if (dp[i][time] != -1) {
            return dp[i][time];
        }

        // Memoization ke saath do possibilities check karo
        dp[i][time] = max(solve_mem(s, i + 1, time, dp), s[i] * time + solve_mem(s, i + 1, time + 1, dp));

        return dp[i][time];
    }

    // Tabulation method (bottom-up approach)
    int tabu(vector<int>& s) {
        int n = s.size();
        // Table banate hain jahan pe sab values initially 0 hongi
        vector<vector<int>> tab(n + 1, vector<int>(n + 2, 0));

        // Peeche se shuru karte hain loop
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j >= 1; j--) {
                // Do possibilities: ya to current element lo ya na lo
                tab[i][j] = max(s[i] * j + tab[i + 1][j + 1], tab[i + 1][j]);
            }
        }

        return tab[0][1];
    }

    // Optimized tabulation method
    int more_op(vector<int>& s) {
        int n = s.size();
        // Previous row ko store karte hain
        vector<int> prev(n + 2, 0);

        for (int i = n - 1; i >= 0; i--) {
            vector<int> curr(n + 1);
            for (int j = i + 1; j >= 1; j--) {
                // Do possibilities: ya to current element lo ya na lo
                curr[j] = max(s[i] * j + prev[j + 1], prev[j]);
            }
            prev = curr; // Update prev to current row
        }

        return prev[1];
    }

public:
    int maxSatisfaction(vector<int>& s) {
        // Pehle satisfaction list ko sort karte hain
        sort(s.begin(), s.end());
        vector<vector<int>> dp(s.size(), vector<int>(s.size() + 1, -1));
        // return solve(s, 0, 1); // Simple recursive approach
        // return solve_mem(s, 0, 1, dp); // Memoized recursive approach
        // return tabu(s); // Tabulation approach
        return more_op(s); // Optimized tabulation approach
    }
};
