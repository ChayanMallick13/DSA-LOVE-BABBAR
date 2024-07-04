//     https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1




// User function Template for C++

class Solution{
    
private:
    int solve(int i, int j, vector<vector<int>> & mat,int & ans){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        
        int dia = solve(i+1,j+1,mat,ans);
        int right = solve(i,j+1,mat,ans);
        int down = solve(i+1,j,mat,ans);
        
        int size = min(dia,min(right,down)) + 1;
        
        if(mat[i][j]){
            ans = max(ans,size);
            return size;
        }
        
        return 0;
        
    }
    
    
    int solve_mem(int i, int j, vector<vector<int>> & mat,int & ans,vector<vector<int>> & dp){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int dia = solve_mem(i+1,j+1,mat,ans,dp);
        int right = solve_mem(i,j+1,mat,ans,dp);
        int down = solve_mem(i+1,j,mat,ans,dp);
        
        int size = min(dia,min(right,down)) + 1;
        
        
        if(mat[i][j]){
            dp[i][j] = size;
            ans = max(ans,size);
            return size;
        }
        dp[i][j]= 0;
        
        return 0;
        
    }
    
    int solve_tabu(int n, int m, vector<vector<int>> & mat){
        vector<vector<int>> tab(n+1,vector<int>(m+1,0));
        
        int ans = 0;
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                int right = tab[i][j+1];
                int dia = tab[i+1][j+1];
                int down = tab[i+1][j];
                
                int size = min(right,min(down,dia))+1;
                
                if(mat[i][j]){
                    ans = max(size,ans);
                    tab[i][j]= size;
                }
                
            }
        }
        return ans;
    }
    
    int more_op(vector<vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();

        

        int ans = 0;

        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                int right ,down,dia;
                dia = right = down = 0;

                if(j+1<m)
                    right = mat[i][j+1];
                if(i+1<n)
                    down = mat[i+1][j];
                if( j+1 < m && i+1 < n)
                    dia = mat[i+1][j+1];

                int size = min(right,min(down,dia)) + 1 ;

                if(mat[i][j]){
                    ans = max(size,ans);
                    mat[i][j] = size;
                }


            }
        }

        return ans;
    }
    
    
public:
    int maxSquare(int n, int m, vector<vector<int>>  mat){
        // code here
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = 0;
        // solve(0,0,mat,ans);
        // solve_mem(0,0,mat,ans,dp);
        // return solve_tabu(n,m,mat);
        return more_op(mat);
        // return ans;
    }
};
