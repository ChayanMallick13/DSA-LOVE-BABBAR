
//    https://www.naukri.com/code360/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM





#include <bits/stdc++.h> // Sob standard libraries include korar jonno

// Recursive solution without memoization
int solve(vector<int> &weight, vector<int> &value, int &n, int capacity, int i) {
    // Jodi index i, n er cheye boro ba soman hoye jay, tahole 0 return koro (base case)
    if (i >= n) {
        return 0;
    }

    int include = 0; // Item include korar porer value
    int exclude = 0; // Item exclude korar porer value

    // Jodi current weight item ta include korte paro
    if (capacity >= weight[i]) {
        // Value add koro ebong remaining capacity diye recursive call koro
        include = value[i] + solve(weight, value, n, capacity - weight[i], i + 1);
    }

    // Item ta exclude kore recursive call
    exclude = solve(weight, value, n, capacity, i + 1);

    // Dui case er moddhe maximum value return koro
    return max(include, exclude);
}

// Recursive solution with memoization
int solve_mem(vector<int> &weight, vector<int> &value, int &n, int capacity, int i, vector<vector<int>> &dp) {
    // Jodi index i, n er cheye boro ba soman hoye jay, tahole 0 return koro (base case)
    if (i >= n) {
        return 0;
    }

    // Jodi current state already calculate kora hoye thake, tahole directly use koro
    if (dp[i][capacity] != -1) {
        return dp[i][capacity];
    }

    int include = 0; // Item include korar porer value
    int exclude = 0; // Item exclude korar porer value

    // Jodi current weight item ta include korte paro
    if (capacity >= weight[i]) {
        // Value add koro ebong remaining capacity diye recursive call koro
        include = value[i] + solve_mem(weight, value, n, capacity - weight[i], i + 1, dp);
    }

    // Item ta exclude kore recursive call
    exclude = solve_mem(weight, value, n, capacity, i + 1, dp);

    // Current state ke store koro
    dp[i][capacity] = max(include, exclude);
    return dp[i][capacity];
}

// Tabulation method
int solve_tabu(vector<int> &weight, vector<int> &value, int &n, int capa) {
    vector<vector<int>> tabu(n, vector<int>(capa + 1, 0));

    // First row ke initialize koro
    for (int i = 0; i <= capa; i++) {
        if (i >= weight[0])
            tabu[0][i] = value[0];
    }

    // DP table ke fill koro
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= capa; j++) {
            int include = 0, exclude = tabu[i - 1][j];
            if (j >= weight[i]) {
                include = value[i] + tabu[i - 1][j - weight[i]];
            }
            tabu[i][j] = max(include, exclude);
        }
    }

    return tabu[n - 1][capa];
}

// Space optimized DP
int sp_op(vector<int> &weight, vector<int> &value, int &n, int capa) {
    vector<int> prev(capa + 1, 0);
    vector<int> curr(capa + 1, 0);

    for (int i = 0; i <= capa; i++) {
        if (i >= weight[0]) {
            prev[i] = value[0];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= capa; j++) {
            int inclu, exclu;
            inclu = exclu = 0;
            exclu = prev[j];
            if (j >= weight[i]) {
                inclu = value[i] + prev[j - weight[i]];
            }
            curr[j] = max(inclu, exclu);
        }
        prev = curr;
    }
    return prev[capa];
}

// More space optimized DP
int more_op(vector<int> &weight, vector<int> &value, int &n, int capa) {
    vector<int> curr(capa + 1, 0);
    for (int i = 0; i <= capa; i++) {
        if (i >= weight[0]) {
            curr[i] = value[0];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = capa; j >= 0; j--) {
            int inc, exc;
            inc = exc = 0;

            exc = curr[j];
            if (j >= weight[i]) {
                inc = value[i] + curr[j - weight[i]];
            }
            curr[j] = max(inc, exc);
        }
    }

    return curr[capa];
}

// Main knapsack function
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // return solve(weight, value, n, maxWeight, 0); // Uncomment for recursive solution
    // return solve_mem(weight, value, n, maxWeight, 0, dp); // Uncomment for memoized solution
    // return solve_tabu(weight, value, n, maxWeight); // Uncomment for tabulation solution
    // return sp_op(weight, value, n, maxWeight); // Uncomment for space-optimized solution
    return more_op(weight, value, n, maxWeight); // More space-optimized solution
}
