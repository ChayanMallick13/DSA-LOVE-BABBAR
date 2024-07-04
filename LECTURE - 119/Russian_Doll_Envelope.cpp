//   https://leetcode.com/problems/russian-doll-envelopes/




bool cmp(vector<int> & a,vector<int> & b){
    if(a[0]!=b[0]){
        return a[0]<b[0];
    }
    else{
        return a[1]>b[1];
    }
}


class Solution {
public:
    int solve(vector<vector<int>> & en){
        vector<int> ans(1,en[0][1]);
        for(int i = 1;i<en.size();i++){
                if(ans[ans.size()-1] < en[i][1]){
                    ans.push_back(en[i][1]);
                }
                else{
                    int f = lower_bound(ans.begin(),ans.end(),en[i][1]) - ans.begin();
                    // cout<<f<<endl;
                    ans[f] = en[i][1];
                }
                
        }
        return ans.size();
    }
public:
    int maxEnvelopes(vector<vector<int>>& en) {
        sort(en.begin(),en.end(),cmp);
        return solve(en);
    }
};
