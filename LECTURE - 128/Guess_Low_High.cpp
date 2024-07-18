//  https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/



class Solution {
    int tabu(int n){
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        //start wala
        for(int i = n;i>=1;i--){
            //end wala
            for(int j = i+1;j<=n;j++){
                int ans = INT_MAX;
                for(int k = i;k<=j;k++){
                    ans = min(ans,k+max(dp[i][k-1],dp[k+1][j]));
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n];
    }
public:
    int getMoneyAmount(int n) {
        return tabu(n);
    }
};
