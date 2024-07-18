//   https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1




bool cmp(pair<pair<int,int>,int> & a,pair<pair<int,int>,int> & b){
    if(a.first.second != b.first.second)
        return a.first.second<b.first.second;
    if(a.first.first != b.first.first)
        return a.first<b.first;
    return a.second<b.second;
}

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        
        vector<int> ans;
        
        vector<pair<pair<int,int>,int>> arr;
        
        for(int i = 0;i<N;i++){
            arr.push_back({{S[i],F[i]},i+1});
        }
        
        sort(arr.begin(),arr.end(),cmp);
        

        
        int etime = -1;
        for(int i = 0;i<N;i++){
            pair<pair<int,int>,int> temp = arr[i];
            if(temp.first.first>etime){
                ans.push_back(temp.second);
                etime = temp.first.second;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
