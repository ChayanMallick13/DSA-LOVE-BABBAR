



class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        //n th val 
        cost.push_back(0);

        //step 1
        vector<int> tabu(n+1);

        //step 2
        tabu[0]=cost[0];
        tabu[1]=cost[1];

        //step 3
        for(int i = 2;i<=n;i++){
            tabu[i] = min(tabu[i-1],tabu[i-2])+cost[i];
        }

        return tabu[n];
        
    }
};
