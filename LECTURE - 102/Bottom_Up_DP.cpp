/*

https://www.naukri.com/code360/problems/nth-fibonacci-number_74156?leftPanelTab=0&leftPanelTabValue=SUBMISSION

*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;
        cin>>n;

        vector<int> dp(n+1);
        dp[1]=1;
        dp[2]=1;

        for(int i = 3;i<=n;i++){
                dp[i]=dp[i-1]+dp[i-2];
        }

        cout<< dp[n]<<endl;

        return 0;

}
