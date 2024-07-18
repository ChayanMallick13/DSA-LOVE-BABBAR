// https://leetcode.com/problems/partition-equal-subset-sum/description/


class Solution {
    bool solve(vector<int> & arr,int curr,int sum,int target){
        if(curr>=arr.size()){
            return false;
        }
        if(sum==target){
            return true;
        }

        //include

        bool include = solve(arr,curr+1,sum+arr[curr],target);

        //exclude
        bool exclude = solve(arr,curr+1,sum,target);

        return include || exclude;
    }

    bool solve_mem(vector<int> & arr,int curr,int sum,int target,vector<vector<int>> & dp){
        if(curr>=arr.size()){
            return false;
        }
        if(sum==target){
            return true;
        }
        if(sum>target){
            return false;
        }
        if(dp[curr][sum]!=-1){
            return dp[curr][sum];
        }

        //include

        bool include = solve_mem(arr,curr+1,sum+arr[curr],target,dp);

        //exclude
        bool exclude = solve_mem(arr,curr+1,sum,target,dp);

        dp[curr][sum] = include || exclude;

        return dp[curr][sum];
    }

    bool solve_mem1(vector<int> & arr,int curr,int target,vector<vector<int>> & dp){
        if(curr>=arr.size()){
            return false;
        }
        if(target==0){
            return 1;
        }
        if(target<0){
            return false;
        }
        if(dp[curr][target]!=-1){
            return dp[curr][target];
        }

        //include

        bool include = solve_mem1(arr,curr+1,target-arr[curr],dp);

        //exclude
        bool exclude = solve_mem1(arr,curr+1,target,dp);

        dp[curr][target] = include || exclude;

        return dp[curr][target];
    }


    bool tabu(vector<int> & nums,int target){

        int n = nums.size();

        vector<vector<bool>> tab(n+1,vector<bool>(target+1,0));

        for(int i = 0;i<=n;i++){
            tab[i][0]=1;
        }

        for(int i = n-1;i>=0;i--){
            for(int j = 1;j<=target;j++){
                bool include = 0;
                if(j-nums[i]>=0){
                    include = tab[i+1][j-nums[i]];
                }

                bool exclude = tab[i+1][j];

                tab[i][j] = include or exclude;
            }
        }

        return tab[0][target];
    }

    int sp_op(vector<int> & nums,int target){

        int n = nums.size();

        vector<bool> tab(target+1,0);
        tab[0]=1;

        for(int i = n-1;i>=0;i--){
            for(int j = target;j>=1;j--){
                bool include = 0;
                if(j-nums[i]>=0){
                    include = tab[j-nums[i]];
                }

                bool exclude = tab[j];

                tab[j] = include or exclude;
            }
        }

        return tab[target];
    }


public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums) {
            sum+=i;
        }
        if(sum%2){
            return false;
        }
        int target = sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        // return solve(nums,0,0,target);
        // return solve_mem(nums,0,0,target,dp);
        // return solve_mem1(nums,0,target,dp);
        // return tabu(nums,target);
        return sp_op(nums,target);
    }
};
