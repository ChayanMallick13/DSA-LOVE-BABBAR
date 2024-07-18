// https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1


class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        
        int maxi=0,mini=0;
        int i=0,j=N-1;
        while(i<=j){
            mini+=candies[i];
            j-=(K);
            i++;
        }
        i = 0,j=N-1;
        while(i<=j){
            maxi+=candies[j];
            j--;
            i+=(K);
        }
        
        vector<int> ans= {mini,maxi};
        return ans;
    }
};
