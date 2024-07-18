// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1



/*
struct Item{
    int value;
    int weight;
};
*/
bool cmp(Item & a,Item & b){
    return ((a.value*1.0)/a.weight) > ((b.value*1.0)/b.weight);
}
class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        sort(arr,arr+n,cmp);
        double ans = 0;
        double cw=0;
        for(int i = 0;i<n;i++){
            int weight = arr[i].weight;
            int value = arr[i].value;
            
            
            if(cw+weight > w){
                ans += ((value*1.0)/weight) * (w-cw);
                break;
            }
            else{
                cw+=weight;
                ans+=value;
            }
        }
        return ans;
    }
};
