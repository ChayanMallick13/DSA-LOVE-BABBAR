
/*
 330
 https://leetcode.com/problems/patching-array/?envType=daily-question&envId=2024-06-16

*/




class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int pathes = 0;
        long long int maxreach = 0;
        int index = 0;
        int size = nums.size();

        while(maxreach<n){
            if(index>=size||nums[index]>maxreach+1){
                pathes++;
                maxreach+=(maxreach+1);
            }
            else{
                maxreach+=nums[index];
                index++;
            }


        }


        return pathes;
    }
};
