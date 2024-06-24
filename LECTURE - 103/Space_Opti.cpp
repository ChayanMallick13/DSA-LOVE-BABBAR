


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.push_back(0);

      //steep 1
        int prev1 = cost[0];
        int prev2 = cost[1];

      // step 2
        for(int i = 2;i<=n;i++){
            int curr = min(prev1,prev2)+cost[i];
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};
