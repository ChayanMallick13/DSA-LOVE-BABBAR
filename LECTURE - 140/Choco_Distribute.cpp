//  https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1





class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long N, long long M){
    //code
        sort(a.begin(),a.end());
        
        long long ans = INT_MAX;
        
        for(int i = 0;M-1+i<N;i++){
            ans = min(ans,a[M-1+i]-a[i]);
        }
        
        return ans;
    }   
};
