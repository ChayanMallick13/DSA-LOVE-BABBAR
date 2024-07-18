//  https://leetcode.com/problems/longest-common-subsequence/description/



class Solution {
    int solve(string &a,string & b,int i,int j){
        if(i>=a.length()){
            return 0;
        }
        if(j>=b.length()){
            return 0;
        }

        if(a[i]==b[j]){
            return 1 + solve(a,b,i+1,j+1);
        }
        else{
            return max(solve(a,b,i+1,j),solve(a,b,i,j+1));
        }
    }

    int solve_mem(string &a,string & b,int i,int j,vector<vector<int>> & dp){
        if(i>=a.length()){
            return 0;
        }
        if(j>=b.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans ;
        if(a[i]==b[j]){
            ans =  1 + solve_mem(a,b,i+1,j+1,dp);
        }
        else{
            ans =  max(solve_mem(a,b,i+1,j,dp),solve_mem(a,b,i,j+1,dp));
        }
        return dp[i][j] = ans ;
    }

    int solve_tabu(string &a, string &b){
        int n = a.length();
        int m = b.length();
        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j++){
                if(a[i]==b[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }

        return dp[0][0];

    }

    int sp_op(string &a, string &b){

        int n = a.length();
        int m = b.length();

        if(n<m){
            swap(a,b);
            swap(n,m);
        }

        vector<int> now(m+1,0);
        vector<int> prev(m+1,0);

        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(a[i]==b[j]){
                    now[j] = 1 + prev[j+1];
                }
                else{
                    now[j] = max(prev[j],now[j+1]);
                }
            }
            prev = now;
        }

        return prev[0];
    }

public:
    int longestCommonSubsequence(string &text1, string &text2) {
        // vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        // return solve(text1,text2,0,0);
        // return solve_mem(text1,text2,0,0,dp);
        return sp_op(text1,text2);
    }
};
