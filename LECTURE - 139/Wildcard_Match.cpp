// https://leetcode.com/problems/wildcard-matching/description/


class Solution {
    bool solve(string & a,string & b,int i,int j,vector<vector<int>> & dp){
        if(i==a.length() && j==b.length()){
            return true;
        }
        if(j>=b.length()){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i>=a.length()){
            for(int k = j;k<b.length();k++){
                if(b[k]!='*'){
                    return dp[i][j] =  false;
                }
            }
            return dp[i][j] =  true;
        }
        

        if(a[i]==b[j] || b[j]=='?'){
            return dp[i][j]=solve(a,b,i+1,j+1,dp);
        }
        else if(b[j]=='*'){
            return dp[i][j] = solve(a,b,i,j+1,dp) || solve(a,b,i+1,j,dp);
        }
        else{
            return dp[i][j] = false;
        }
    }

    int solve_tabu(string & s, string & p){
        vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,0));
        int n = s.length(),m=p.length();

        dp[n][m] = 1;

        for(int k = m-1;k>=0;k--){
            if(p[k]=='*')
                dp[n][k]=1;
            else
                break;
        }

        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(s[i]==p[j] || p[j] == '?'){
                    dp[i][j] = dp[i+1][j+1];
                }
                else if(p[j]=='*'){
                    dp[i][j] = dp[i][j+1] || dp[i+1][j];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }

    int sp_op(string & s,string & p){

        int n = s.length(),m=p.length();

        vector<int> prev(m+1,0);

        vector<int> now(m+1,0);

        prev[m] = 1;

        for(int k = m-1;k>=0;k--){
            if(p[k]=='*')
                prev[k]=1;
            else
                break;
        }

        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(s[i]==p[j] || p[j] == '?'){
                    now[j] = prev[j+1];
                }
                else if(p[j]=='*'){
                    now[j] = now[j+1] || prev[j];
                }
                else{
                    now[j] = 0;
                }
            }
            prev = now;
        }

        return prev[0];

    }
public:
    bool isMatch(string s, string p) {
        // vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,-1));
        // return solve(s,p,0,0,dp);
        // return solve_tabu(s,p);
        return sp_op(s,p);
    }
};
