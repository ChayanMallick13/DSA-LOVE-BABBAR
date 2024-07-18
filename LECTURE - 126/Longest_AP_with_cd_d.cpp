//  https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/submissions/1311555274/




class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> m;
        int ans = 0;
        for(int i = 0;i<arr.size();i++){
            int next = arr[i] - difference;
            int size = 1;
            if(m.count(next)){
                size = size + m[next];
            }
            m[arr[i]]=size;
            ans = max(size,ans);
        }
        return ans;
    }
};
