



#include <bits/stdc++.h>

// Pehle solve function ko define karte hain
long long int solve(vector<int>& arr, int pos, vector<long long int>& dp){
    if(pos < 0){
        return 0; // Agar position 0 se chhoti hai toh return 0
    }
    if(dp[pos] != -1){
        return dp[pos]; // Agar dp[pos] already calculated hai toh usko return karo
    }

    long long int exclu = solve(arr, pos-1, dp); // Element ko exclude karne ki case
    long long int inclu = solve(arr, pos-2, dp) + arr[pos]; // Element ko include karne ki case
    dp[pos] = max(exclu, inclu); // Maximum of exclude aur include ko dp[pos] mein store karo
    return dp[pos]; // dp[pos] return karo
}

// Ab solve1 function ko define karte hain
long long int solve1(vector<int>& arr, int pos, vector<long long int>& dp){
    if(pos < 1){
        return 0; // Agar position 1 se chhoti hai toh return 0
    }
    if(dp[pos] != -1){
        return dp[pos]; // Agar dp[pos] already calculated hai toh usko return karo
    }

    long long int exclu = solve1(arr, pos-1, dp); // Element ko exclude karne ki case
    long long int inclu = solve1(arr, pos-2, dp) + arr[pos]; // Element ko include karne ki case
    dp[pos] = max(exclu, inclu); // Maximum of exclude aur include ko dp[pos] mein store karo
    return dp[pos]; // dp[pos] return karo
}

// Main function jo house robber problem solve karega
long long int houseRobber(vector<int>& arr)
{
    int n = arr.size(); // Array ka size lo
    if(arr.size() == 1){
        return arr[0]; // Agar array ka size 1 hai toh pehla element return karo
    }
    vector<long long int> dp(n, -1); // dp array ko initialize karo -1 se
    vector<long long int> dp1(n, -1); // dp1 array ko initialize karo -1 se
    return max(solve(arr, n-2, dp), solve1(arr, n-1, dp1)); // solve aur solve1 ka maximum return karo
}
