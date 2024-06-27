
//   https://www.naukri.com/code360/problems/count-derangements_873861?leftPanelTab=0&leftPanelTabValue=PROBLEM




#include<bits/stdc++.h>
#define MOD 1000000007


/****************************************************************  RECURSION ONLY ************************************************************************************/
long long int rec(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }

    return (((n-1)%MOD)*(( ( rec(n-2) % MOD ) + ( rec(n-1) % MOD )))%MOD)%MOD;
}


/****************************************************************  RECURSION + MEMORISATION *************************************************************************/
long long int solve(vector<long long int> & dp,long long int n){
    if(n<3){
        return n-1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n] = (((n-1)%MOD) * ( (solve(dp, n-1)%MOD) + (solve(dp, n-2)%MOD)  )%MOD);
    return dp[n];
}


/****************************************************************  TABULATION ************************************************************************************/
long long int tab(int n){
    vector<long long int> tabu(n+1);
    tabu[1]=0;
    tabu[2]=1;
    for(int i = 3;i<=n;i++){
        tabu[i] = (((i-1)%MOD) * ((tabu[i-2]%MOD)+ (tabu[i-1]%MOD))%MOD);
    }
    return tabu[n];
}


/****************************************************************  SPACE OPTIMISATION *******************************************************************************/
long long int sp_op(int n){
    if(n==1){
        return 0;
    }
    long long int prev1 = 1,prev2 = 0;
    for(int i = 3;i<=n;i++){
        long long int curr = (((i-1)%MOD) * ((prev2%MOD)+ (prev1%MOD))%MOD);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}



/****************************************************************  DRIVER CODE   ***********************************************************************************/
long long int countDerangements(int n) {
    // Write your code here.
    vector<long long int> dp(n+1,-1);
    // return mem(n, dp);
    // return rec(n);
    // return solve(dp, n);
    // return tab(n);
    return sp_op(n);
}
