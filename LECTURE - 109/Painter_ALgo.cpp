//    https://www.naukri.com/code360/problems/ninja-and-the-fence_3210208?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM



#include <bits/stdc++.h>
#define lim 1000000007

// Ei function du'to numbers add kore ja modulo 'lim' er modhye thake
int add(int a, int b) {
    return ((a % lim) + (b % lim)) % lim;
}

// Ei function du'to numbers multiply kore ja modulo 'lim' er modhye thake
int mul(int a, int b) {
    return ((a % lim) * 1LL * (b % lim)) % lim;
}

// Ei function 'solve' diye rekursive bhabe n ar k er modhye calculation kore
int solve(int n, int k) {
    if (n == 1) {
        return k;
    }
    if (n == 2) {
        return mul(k, k);
    }

    return add(mul(k-1, solve(n-2, k)), mul(k-1, solve(n-1, k)));
}

// Memoization er jonno ei function 'solve_mem' diye calculation kore
int solve_mem(int n, int k, vector<int> &dp) {
    if (n == 1) {
        return k;
    }
    if (n == 2) {
        return k * k;
    }
    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = add(mul(k-1, solve_mem(n-2, k, dp)), mul(k-1, solve_mem(n-1, k, dp)));
    return dp[n];
}

// Tabulation er jonno ei function 'solve_tab' diye calculation kore
int solve_tab(int n, int k) {
    vector<int> tabu(n+1, 0);
    tabu[1] = k;
    tabu[2] = mul(k, k);
    for (int i = 3; i <= n; i++) {
        tabu[i] = add(mul(k-1, tabu[i-2]), mul(k-1, tabu[i-1]));
    }
    return tabu[n];
}

// Space optimization er jonno ei function 'sp_op' diye calculation kore
int sp_op(int n, int k) {
    int prev1 = mul(k, k);
    int prev2 = k;
    if (n == 1) {
        return k;
    }
    for (int i = 3; i <= n; i++) {
        int curr = add(mul(k-1, prev2), mul(k-1, prev1));
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

// Main function ja different approaches diye n ar k er modhye calculation kore
int numberOfWays(int n, int k) {
    vector<int> dp(n+1, -1);
    // return solve(n, k);      // Rekursive approach
    // return solve_mem(n, k, dp);  // Memoization approach
    // return solve_tab(n, k);      // Tabulation approach
    return sp_op(n, k);             // Space optimized approach
}
