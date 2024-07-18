//   https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1




class Solution
{
    public:
    static bool cmp(pair<int,int> & a,pair<int,int> & b){
        return a.second<b.second;
    }
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        
        vector<pair<int,int>> arr;
        
        for(int i = 0;i<n;i++){
            arr.push_back({start[i],end[i]});
        }
        
        sort(arr.begin(),arr.end(),cmp);
        int ans = 0;
        
        int lday = -1;
        
        for(int i = 0;i<n;i++){
            int s = arr[i].first;
            int e = arr[i].second;
            // cout<<lday<<" "<<s<<endl;
            if(s>lday){
                ans++;
                lday = e;
            }
        }
        return ans;
    }
};
