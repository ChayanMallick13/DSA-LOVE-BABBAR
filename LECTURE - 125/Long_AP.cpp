
//   https://www.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1




#include<bits/stdc++.h>
class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        if(n<3){
            return n;
        }
        unordered_map<int,int> m[n];
        int ans = 0;
        for(int i = 1;i<n;i++){
            for(int j = i-1 ;j>=0;j--){
                int diff = A[i]-A[j];
                
                int cnt = 1;
                
                if(m[j].count(diff))
                    cnt = m[j][diff];
                    
                m[i][diff] = 1 + cnt;
                ans = max(ans,m[i][diff]);
            }
        }
        return ans;
    }
};
