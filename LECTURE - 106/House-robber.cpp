//  https://www.naukri.com/code360/problems/house-robber_839733?leftPanelTab=0&leftPanelTabValue=SOLUTION



#include <bits/stdc++.h> 
// Function problem ko solve karne ke liye
long long int solve(vector<int>& arr){
    long long int prev1 = arr[0], prev2 = 0; // Previous values initialize karo
    long long int ans1, ans2; // Answers store karne ke liye variables
    int n = arr.size(); // Array ka size lo

    // Array ke second element se lekar second last element tak loop karo
    for(int i = 1; i < n-1; i++){
        long long int curr = max(prev2 + arr[i], prev1); // Current maximum calculate karo
        prev2 = prev1; // Previous values update karo
        prev1 = curr; // Previous values update karo
    }
    ans1 = prev1; // Pehla answer store karo

    // Previous values reset karo
    prev1 = prev2 = 0;

    // Array ke first element se lekar last element tak loop karo
    for(int i = 1; i < n; i++){
        long long int curr = max(prev2 + arr[i], prev1); // Current maximum calculate karo
        prev2 = prev1; // Previous values update karo
        prev1 = curr; // Previous values update karo
    }
    ans2 = prev1; // Dusra answer store karo

    return max(ans1, ans2); // Dono answers me se maximum return karo
}

// Main function jo house robber problem solve karega
long long int houseRobber(vector<int>& arr)
{
    return solve(arr); // Solve function call karo
}
