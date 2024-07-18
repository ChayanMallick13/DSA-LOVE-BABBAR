//  https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/




class Solution {

    int solve(vector<int> & nums1,vector<int> & nums2,int curr,bool prev){
        if(curr>=nums1.size()){
            return 0;
        }

        int prev1 = nums1[curr-1];
        int prev2 = nums2[curr-1];

        if(prev){
            swap(prev1,prev2);
        }
        int ans = INT_MAX;
        //no swap
        if(prev1 < nums1[curr] && prev2 < nums2[curr]){
            ans = solve(nums1,nums2,curr+1,0);
        }

        //swap
        if(prev1<nums2[curr] && prev2 < nums1[curr]){
            ans = min(ans,1 + solve(nums1,nums2,curr+1,1));
        }


        return ans;
    }



    int solve_mem(vector<int> & nums1,vector<int> & nums2,int curr,bool prev,vector<vector<int>> & dp){
        if(curr>=nums1.size()){
            return 0;
        }
        if(dp[curr][prev]!=-1){
            return dp[curr][prev];
        }

        int prev1 = nums1[curr-1];
        int prev2 = nums2[curr-1];

        if(prev){
            swap(prev1,prev2);
        }
        int ans = INT_MAX;
        //no swap
        if(prev1 < nums1[curr] && prev2 < nums2[curr]){
            ans = solve_mem(nums1,nums2,curr+1,0,dp);
        }

        //swap
        if(prev1<nums2[curr] && prev2 < nums1[curr]){
            ans = min(ans,1 + solve_mem(nums1,nums2,curr+1,1,dp));
        }


        dp[curr][prev] = ans;
        return ans;
    }


    int tabu(vector<int> & nums1,vector<int> & nums2){
        int n = nums1.size();

        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int i = n-1;i>=1;i--){
            for(int j = 0;j<2;j++){
                int prev1 = nums1[i-1];
                int prev2 = nums2[i-1];
                if(j){
                    swap(prev1,prev2);
                }

                int ans = INT_MAX;
                if(prev1 < nums1[i] and prev2 < nums2[i]){
                    ans = min(ans,dp[i+1][0]);
                }
                if(prev1< nums2[i] && prev2 < nums1[i]){
                    ans = min(ans,1+dp[i+1][1]);
                }

                dp[i][j] = ans;
            }
        }

        return dp[1][0];
    }

    int sp_op(vector<int> & nums1,vector<int> & nums2){
        int n = nums1.size();

        vector<int> prev(2,0);
        vector<int> curr(2,0);

        for(int i = n-1;i>=1;i--){
            for(int j = 0;j<2;j++){
                int prev1 = nums1[i-1];
                int prev2 = nums2[i-1];
                if(j){
                    swap(prev1,prev2);
                }

                int ans = INT_MAX;
                if(prev1 < nums1[i] and prev2 < nums2[i]){
                    ans = min(ans,prev[0]);
                }
                if(prev1< nums2[i] && prev2 < nums1[i]){
                    ans = min(ans,1+prev[1]);
                }

                curr[j] = ans;
            }
            prev = curr;
        }

        return prev[0];
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        //step 1
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        // vector<vector<int>> dp(nums1.size(),vector<int>(2,-1));
        // return solve(nums1,nums2,1,0);
        // return solve_mem(nums1,nums2,1,0,dp);
        // return tabu(nums1,nums2);
        return sp_op(nums1,nums2);
    }
};
