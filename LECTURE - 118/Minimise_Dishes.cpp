//  https://leetcode.com/problems/reducing-dishes/



class Solution {

private:
    int solve(vector<int>& s,int i,int time){
        if(i>=s.size()){
            return 0;
        }

        return max(solve(s,i+1,time),s[i]*time + solve(s,i+1,time+1));
    }

    int solve_mem(vector<int>& s,int i,int time,vector<vector<int>> &dp){
        if(i>=s.size()){
            return 0;
        }
        if(dp[i][time]!=-1){
            return dp[i][time];
        }

        dp[i][time] =  max(solve_mem(s,i+1,time,dp),s[i]*time + solve_mem(s,i+1,time+1,dp));

        return dp[i][time];
    }

    int tabu(vector<int>& s){
        int n = s.size();

        vector<vector<int>> tab(n+1,vector<int>(n+2,0));

        for(int i = n-1;i>=0;i--){
            for(int j = i+1;j>=1;j--){
                tab[i][j] = max(s[i]*j+tab[i+1][j+1],tab[i+1][j]);
            }
        }

        return tab[0][1];
    }


    int more_op(vector<int>& s){
        int n = s.size();
        vector<int> prev(n+2,0);

        for(int i = n-1;i>=0;i--){
            vector<int> curr(n+1);
            for(int j = i+1;j>=1;j--){
                curr[j] = max(s[i]*j+prev[j+1],prev[j]);
            }
            prev = curr;
        }

        return prev[1];
    }


public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        vector<vector<int>> dp(s.size(),vector<int>(s.size()+1,-1));
        // return solve(s,0,1);
        // return solve_mem(s,0,1,dp);
        // return tabu(s);
        return more_op(s);
    }
};




//  Greedy


class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        //greedy Approach
        sort(sat.begin(),sat.end());

        int ans = 0;
        int sum = 0;

        for(int i = sat.size()-1;i>=0;i--){
            if(ans < ans + sum + sat[i]){
                ans = ans+sum+sat[i];
                sum+=sat[i];
            }
            else{
                break;
            }
        }

        return ans;
    }
};
