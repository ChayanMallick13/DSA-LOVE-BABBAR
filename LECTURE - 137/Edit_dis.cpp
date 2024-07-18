
//https://leetcode.com/problems/edit-distance/




class Solution {
    int solve(string & a,string & b,int i,int j){
        if(i>=a.length()){
            return b.length()-j;
        }
        if(j>=b.length()){
            return a.length()-i;
        }

        //match ho gaya
        if(a[i]==b[j]){
            return solve(a,b,i+1,j+1);
        }
        else{

            //insert karo
            int insert = 1 + solve(a,b,i,j+1);

            //delete karo
            int del = 1 + solve(a,b,i+1,j);

            //replace karo
            int replace = 1 + solve(a,b,i+1,j+1);

            return min(del,min(replace,insert));
        }
    }

    int solve_mem(string & a,string & b,int i,int j,vector<vector<int>> & dp){
        if(i>=a.length()){
            return b.length()-j;
        }
        if(j>=b.length()){
            return a.length()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans ;

        //match ho gaya
        if(a[i]==b[j]){
            ans =  solve_mem(a,b,i+1,j+1,dp);
        }
        else{

            //insert karo
            int insert = 1 + solve_mem(a,b,i,j+1,dp);

            //delete karo
            int del = 1 + solve_mem(a,b,i+1,j,dp);

            //replace karo
            int replace = 1 + solve_mem(a,b,i+1,j+1,dp);

            ans =  min(del,min(replace,insert));
        }

        return dp[i][j] = ans;
    }

    int solve_tab(string & a, string & b){

        vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,0));

        for(int i = 0;i<=a.length();i++){
            dp[i][b.length()] = a.length()-i;
        }
        for(int i = 0;i<=b.length();i++){
            dp[a.length()][i] = b.length()-i;
        }

        for(int i = a.length()-1;i>=0;i--){
            for(int j = b.length()-1;j>=0;j--){
                int ans;
                if(a[i]==b[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    ans = 1+  min(dp[i][j+1],min(dp[i+1][j] , dp[i+1][j+1]));
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][0];

    }

    int sp_op(string & a,string & b){
        int n = a.length();
        int m = b.length();

        if(n<m){
            swap(n,m);
            swap(a,b);
        }

        vector<int> now(m+1,0);
        vector<int> prev(m+1,0);
        for(int i = 0;i<m;i++){
            prev[i] = b.length()-i;
        }

        for(int i = n-1;i>=0;i--){

            for(int j = m-1;j>=0;j--){
                int ans;
                if(a[i]==b[j]){
                    ans = prev[j+1];
                }
                else{
                    ans = 1+  min(now[j+1],min(prev[j] , prev[j+1]));
                }
                now[j] = ans;
            }

            now[m] = a.length()-i;
            prev = now;
        }

        return prev[0];
    }

public:
    int minDistance(string word1, string word2) {
        
        // vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));   
        // return solve(word1,word2,0,0);   
        // return solve_mem(word1,word2,0,0,dp);   
        // return solve_tab(word1,word2);
        return sp_op(word1,word2);
    }   
};
