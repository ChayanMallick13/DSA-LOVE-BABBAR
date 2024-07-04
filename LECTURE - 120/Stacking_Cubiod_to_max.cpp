//  https://leetcode.com/problems/maximum-height-by-stacking-cuboids/



class Solution {
    bool check(vector<int> & a,vector<int> & b){
        return (a[0]<=b[0]) && (a[1]<=b[1]) && (a[2]<=b[2]);
    }
    int solve(vector<vector<int>> & arr,int curr,int last,vector<vector<int>> & dp){
        if(curr>=arr.size()){
            return 0;
        }if(dp[curr][last+1]!=-1){
            return dp[curr][last+1];
        }

        int include = INT_MIN;
        if( last== -1 || check(arr[last],arr[curr])){
            include = arr[curr][2] + solve(arr,curr+1,curr,dp);
        }
        int exclude = solve(arr,curr+1,last,dp);

        dp[curr][last+1] = max(include,exclude);
        return dp[curr][last+1];
    }

public:
    int maxHeight(vector<vector<int>>& cub) {
        int n = cub.size();
        for(int i = 0;i<cub.size();i++){
            sort(cub[i].begin(),cub[i].end());
        }

        sort(cub.begin(),cub.end());

        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(cub,0,-1,dp);

    }
};
