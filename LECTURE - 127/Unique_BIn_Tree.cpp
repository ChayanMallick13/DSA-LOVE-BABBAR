 //  https://leetcode.com/problems/unique-binary-search-trees/


class Solution {
    int solve(int n){
        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            ans += solve(i-1) * solve(n-i);
        }
        return ans;
    }

    int solve_mem(int n,vector<int> & dp){
        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            ans += solve_mem(i-1,dp) * solve_mem(n-i,dp);
        }
        return dp[n] =  ans;
    }

    int tabu(int n){

        vector<int> tab(n+1,0);
        tab[0]=1;

        for(int i = 1;i<=n;i++){
            int ans = 0;
            for(int j = 1;j<=i;j++){
                ans += tab[j-1]*tab[i-j];
            }
            tab[i] = ans;
        }
        return tab[n];
    }
public:
    int numTrees(int n) {
        // vector<int> dp(n+1,-1);
        // return solve(n);
        return tabu(n);
    }
};
