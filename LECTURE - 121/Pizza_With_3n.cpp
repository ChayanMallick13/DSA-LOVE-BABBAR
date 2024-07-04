//   https://leetcode.com/problems/pizza-with-3n-slices/description/



class Solution {

public:
    int solve(int curr,int last,vector<int> & sli,int toeaten,int n){
        if(curr>=last || toeaten == 0){
            return 0;
        }

        //include

        int include = sli[curr] + solve(curr+2,last,sli,toeaten-1,n);


        //exclude
        int exclude = solve(curr+1,last,sli,toeaten,n);


        return max(include,exclude);
    }

    int solve_mem(int curr,int last,vector<int> & sli,int toeaten,int n,vector<vector<int>> & dp){
        if(curr>=last || toeaten == 0){
            return 0;
        }
        if(dp[curr][toeaten]!=-1){
            return dp[curr][toeaten];
        }

        //include

        int include = sli[curr] + solve_mem(curr+2,last,sli,toeaten-1,n,dp);


        //exclude
        int exclude = solve_mem(curr+1,last,sli,toeaten,n,dp);


        dp[curr][toeaten] = max(include,exclude);
        return dp[curr][toeaten];
    }


    int tabu(vector<int> & slices){

        int k = slices.size();
        int n = k/3;

        vector<vector<int>> tab1(k+2,vector<int>(n+1,0));
        vector<vector<int>> tab2(k+2,vector<int>(n+1,0));

        for(int i = k-1;i>=1;i--){
            for(int j = n-1;j>=0;j--){
                int include = slices[i] + tab1[i+2][j+1];

                int exclude = tab1[i+1][j];

                tab1[i][j] = max(include,exclude);
            }
        }

        for(int i = k-2;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                int include = slices[i] + tab2[i+2][j+1];

                int exclude = tab2[i+1][j];

                tab2[i][j] = max(include,exclude);
            }
        }

        return max(tab1[1][0],tab2[0][0]);

    }


    int sp_opti(vector<int> & slices){
        int k = slices.size();
        int n = k/3;

        vector<vector<int>> tab1(3,vector<int>(n+1,0));
        vector<vector<int>> tab2(3,vector<int>(n+1,0));

        for(int i = k-1;i>=1;i--){
            for(int j = n-1;j>=0;j--){
                int include = slices[i] + tab1[2][j+1];

                int exclude = tab1[1][j];

                tab1[0][j] = max(include,exclude);
            }
            tab1[2] = tab1[1];
            tab1[1] = tab1[0];
        }

        for(int i = k-2;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                int include = slices[i] + tab2[2][j+1];

                int exclude = tab2[1][j];

                tab2[0][j] = max(include,exclude);
            }
            tab2[2] = tab2[1];
            tab2[1] = tab2[0];
        }

        return max(tab1[1][0],tab2[1][0]);
    }


public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        int n = k/3;

        // vector<vector<int>> dp1(k,vector<int>(n+1,-1));
        // vector<vector<int>> dp2(k,vector<int>(n+1,-1));

        // int first_exclude = solve_mem(1,k,slices,n,n,dp1);
        // int first_include = solve_mem(0,k-1,slices,n,n,dp2);



        // return max(first_include,first_exclude);
        // return tabu(slices);
        return sp_opti(slices);

    }
};
