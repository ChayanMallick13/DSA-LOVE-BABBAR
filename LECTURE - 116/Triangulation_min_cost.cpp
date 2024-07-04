//   https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/




class Solution {
private:
    int solve(int i,int j,vector<int>& arr){
        if(j-i<2){
            return 0;
        }

        int ans = INT_MAX;

        for(int k = i+1;k<j;k++){
            ans = min(ans,arr[i]*arr[k]*arr[j] + solve(i,k,arr) + solve(k,j,arr) );
        }

        return ans;
    }

    int solve_mem(int i,int j,vector<int>& arr,vector<vector<int>> & dp){
        if(j-i<2){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans = INT_MAX;

        for(int k = i+1;k<j;k++){
            ans = min(ans,arr[i]*arr[k]*arr[j] + solve_mem(i,k,arr,dp) + solve_mem(k,j,arr,dp) );
        }

        dp[i][j] = ans;
        return ans;
    }

    int tabu(vector<int>& values){
        int n = values.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        
        
        for(int i = n-1;i>=0;i--){
            for(int j = i+2;j<n;j++){
                int ans = INT_MAX;
                for(int k = i+1 ; k<j;k++){
                    ans = min(ans,values[i] * values[k] * values[j] + dp[i][k]+ dp[k][j] );
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        // ret<urn solve(0,values.size()-1,values);
        vector<vector<int>> dp(values.size(),vector<int>(values.size(),-1));
        // return solve_mem(0,values.size()-1,values,dp);
        return tabu(values);
    }
};
