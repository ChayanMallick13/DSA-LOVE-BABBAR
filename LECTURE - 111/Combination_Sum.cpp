//  https://www.naukri.com/code360/problems/number-of-ways_3755252?leftPanelTab=0&leftPanelTabValue=PROBLEM





#include <bits/stdc++.h> // Sob standard libraries include korar jonno

// Recursive solution without memoization
int solve(vector<int> &num, int tar) {
    // Jodi tar 0 hoy, tahole 1 return koro (base case)
    if (tar == 0) {
        return 1;
    }

    int ans = 0; // Answer ke initialize koro
    // Proti item er jonno check koro
    for (auto i : num) {
        // Jodi tar - i >= 0 hoy, tahole recursive call koro
        if (tar - i >= 0) {
            ans += solve(num, tar - i);
        }
    }
    return ans;
}

// Recursive solution with memoization
int solve_rem(vector<int> &num, int tar, vector<int> &dp) {
    // Jodi tar 0 hoy, tahole 1 return koro (base case)
    if (tar == 0) {
        return 1;
    }

    // Jodi current state already calculate kora hoye thake, tahole directly use koro
    if (dp[tar] != -1) {
        return dp[tar];
    }

    int ans = 0; // Answer ke initialize koro
    // Proti item er jonno check koro
    for (auto i : num) {
        // Jodi tar - i >= 0 hoy, tahole recursive call koro
        if (tar - i >= 0) {
            ans += solve_rem(num, tar - i, dp);
        }
    }

    // Current state ke store koro
    dp[tar] = ans;
    return dp[tar];
}

// Tabulation method
int solve_tab(vector<int> &num, int tar) {
    vector<int> tabu(tar + 1, 0); // DP table ke initialize koro
    tabu[0] = 1; // Base case

    // DP table ke fill koro
    for (int i = 1; i <= tar; i++) {
        int ans = 0; // Answer ke initialize koro
        // Proti item er jonno check koro
        for (auto j : num) {
            // Jodi i - j >= 0 hoy, tahole ans ke update koro
            if (i - j >= 0) {
                ans += tabu[i - j];
            }
        }
        tabu[i] = ans; // Current state ke store koro
    }

    return tabu[tar];
}

// Main function to find ways to achieve target
int findWays(vector<int> &num, int tar) {
    // Vector to store results for memoization
    vector<int> dp(tar + 1, -1);
    // return solve(num, tar); // Uncomment for recursive solution
    // return solve_rem(num, tar, dp); // Uncomment for memoized solution
    return solve_tab(num, tar); // Tabulation solution
}
