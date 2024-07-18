//  https://leetcode.com/problems/longest-palindromic-subsequence/description/



class Solution {
    int sp_op(string a, string b){

        int n = a.length();
        int m = b.length();

        if(n<m){
            swap(a,b);
            swap(n,m);
        }

        vector<int> now(m+1,0);
        vector<int> prev(m+1,0);

        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(a[i]==b[j]){
                    now[j] = 1 + prev[j+1];
                }
                else{
                    now[j] = max(prev[j],now[j+1]);
                }
            }
            prev = now;
        }

        return prev[0];
    }
public:
    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(a.begin(),a.end());
        return sp_op(s,a);
    }
};
