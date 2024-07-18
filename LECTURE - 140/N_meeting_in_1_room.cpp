//  https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1




bool cmp(pair<int,int> & a,pair<int,int> & b){
    return a.second<b.second;
}
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> arr;
        for(int i = 0;i<n;i++){
            arr.push_back({start[i],end[i]});
        }
        sort(arr.begin(),arr.end(),cmp);
        int etime = -1;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(arr[i].first>etime){
                cnt++;
                etime = arr[i].second;
            }
        }
        return cnt;
    }
};
