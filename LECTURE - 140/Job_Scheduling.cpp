//https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1



/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
bool cmp(Job & a,Job & b){
    return a.profit > b.profit;
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        
        vector<int> tim(n+1,-1);
        
        int jobs=0,profit=0;
        
        for(int i = 0;i<n;i++){
            int dead = arr[i].dead;
            for(int k = dead;k>=1;k--){
                if(tim[k]==-1){
                    tim[k]=arr[i].id;
                    jobs++;
                    profit+=arr[i].profit;
                    break;
                }
            }
        }
        vector<int> ans={jobs,profit};
        return ans;
    } 
};
