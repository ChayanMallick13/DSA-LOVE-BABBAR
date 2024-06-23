/*

https://www.naukri.com/code360/problems/nth-fibonacci-number_74156?leftPanelTab=0&leftPanelTabValue=PROBLEM

*/


#include<bits/stdc++.h>
using namespace std;

int fib(int n,int dp[]){
        if(n<3){
                return 1;
        }

        //step 3
        if(dp[n]!=-1){
                return dp[n];
        }

        //step 2
        dp[n] = fib(n-1, dp)+fib(n-2, dp);
        return dp[n];
}
int main()
{

        int n;
        cin>>n;

        //step 1
        int * dp = new int[n+1];
        for(int i = 0;i<=n;i++){
                dp[i]=-1;
        }
        cout<<fib(n,dp)<<endl;
        delete dp;
        return 0;
}
