//    https://leetcode.com/problems/min-cost-climbing-stairs/description/



class Solution {
public:
  //pohuch ke ready rahne ka cost n pe
    int solve(vector<int>& cost,int pos) {

        //BASE
        if(pos<2){
            return 0;
        }


        return min(solve(cost,pos-1)+cost[pos-1],solve(cost,pos-2)+cost[pos-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        return solve(cost,n);
    }
};
