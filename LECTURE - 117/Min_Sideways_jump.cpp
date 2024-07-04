//  https://leetcode.com/problems/minimum-sideway-jumps/description/



class Solution {
    
private:
    
    int solve(vector<int>& obs,int pos,int lane,vector<bool> visited){
        
        if(pos == obs.size()-1){
            return 0;
        }

        
        visited[lane] = true;
        
        if(obs[pos+1]!=lane){

            vector<bool> nw(4,false);
            return solve(obs,pos+1,lane,nw);
        }
        
        int ans = INT_MAX-1;
        for(int i = 1;i<=3;i++){
            if(visited[i] || (obs[pos] == i) ){
                continue;
            }
            ans = min(ans,solve(obs,pos,i,visited)+1);
        }

        return ans;
    }



    int solve_mem(vector<int>& obs,int pos,int lane,vector<vector<int>> &dp){
        
        if(pos == obs.size()-1){
            return 0;
        }
        if(dp[pos][lane]!=-1){
            return dp[pos][lane];
        }

        

        if(obs[pos+1]!=lane){

            return solve_mem(obs,pos+1,lane,dp);
        }
        
        int ans = INT_MAX-1;
        for(int i = 1;i<=3;i++){
            if( (i==lane) || (obs[pos] == i) ){
                continue;
            }
            ans = min(ans,solve_mem(obs,pos,i,dp)+1);
        }

        dp[pos][lane] =  ans;
        return ans;
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        
        // vector<bool> visited(4,0);

        vector<vector<int>> dp(obstacles.size(),vector<int>(4,-1));
        
        return solve_mem(obstacles,0,2,dp);
        
    }
};








class Solution {
public:

    int tabu(vector<int>& obs){

        int n = obs.size();

        vector<vector<int>> tab(n,vector<int>(4,1e9));

        for(int i = 0;i<4;i++){
            tab[n-1][i] = 0;
        }

        for(int i = n-2;i>=0;i--){
            for(int j = 1;j<=3;j++){
                if(obs[i+1] != j){
                    tab[i][j] = tab[i+1][j];
                }

                else{
                    for(int lane = 1;lane<4;lane++){
                        if( (lane != j) && (obs[i]!=lane)){
                            tab[i][j] = min(tab[i][j],tab[i+1][lane]+1);
                        }
                    }
                }
            }
        }

        return min(tab[0][3]+1,min(tab[0][1]+1,tab[0][2]));


    }

    int more_op(vector<int>& obs){

        vector<int> prev(4,0);
        int n = obs.size();

        for(int  i = n-2;i>=0;i--){
            vector<int> curr(4,1e9);
            for(int j = 1;j<=3;j++){
                if(obs[i+1] != j){
                    curr[j] = prev[j];
                }
                else{
                    for(int lane = 1;lane<4;lane++){
                        if(lane != j && obs[i]!=lane){
                            curr[j] = min(curr[j],1+prev[lane]);
                        }
                    }
                }
            }
            prev = curr;
        }

        return min(prev[1]+1,min(prev[2],prev[3]+1));

    }
    int minSideJumps(vector<int>& obstacles) {
        // return tabu(obstacles);
        return more_op(obstacles);
    }
};


