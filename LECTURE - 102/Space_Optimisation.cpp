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

        // two variables
        int prev1 = 1;
        int prev2 = 1;

        //agar 0 hoto use handle karlena khud se

        //step 3
        for(int i = 3;i<=n;i++){
                int curr = prev1+prev2;
                prev1 = prev2;
                prev2 = curr;
        }

        cout<< prev2 <<endl;

        return 0;

}
