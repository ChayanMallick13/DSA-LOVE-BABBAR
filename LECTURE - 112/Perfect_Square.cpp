//   https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1


//User function Template for C++

class Solution{
    private:
    int solve(int n){
        if(n==0){
            return 0;
        }
        int ans = INT_MAX;
        for(int i = 1;i*i<=n;i++){
            ans = min(ans,solve(n-i*i)+1);
        }
        return ans;
    }
    
    int solve_mem(int n,vector<int> & dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans = INT_MAX;
        for(int i = 1;i*i<=n;i++){
            ans = min(ans,solve_mem(n-i*i,dp)+1);
        }
        dp[n] = ans;
        return dp[n];
    }
    
    int solve_tabu(int n){
        
        vector<int> tabu(n+1,INT_MAX);
        
        tabu[0] = 0;
        tabu[1] = 1;
        for(int i = 2;i<=n;i++){
            for(int j = 1;j*j<=i;j++){
                tabu[i] = min(tabu[i],tabu[i-j*j]+1);
            }
        }
        
        return tabu[n];
    }
    
    
	public:
	int MinSquares(int n)
	{
	    // Code here
	    vector<int> dp(n+1,-1);
	   // return solve_mem(n,dp);
	   return solve_tabu(n);
	}
};
