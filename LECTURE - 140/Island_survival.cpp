//  https://www.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1



class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        
        int total = S * M;
        
        int sundays = S/7;
        
        int buying_days = S - sundays;
        
        if(S>6 and (N-M)*6<M)
            return -1;
        
        int ans = (S * M)/N;
        
        if((S * M) % N != 0){
            ans = (S * M)/N + 1;
        }
        
        if(ans<=buying_days){
            return ans;
        }
        else{
            return -1;
        }
    
    }
};
