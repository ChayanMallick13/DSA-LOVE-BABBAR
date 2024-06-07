/*
      QUESTION LINK : - https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
*/



class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        //INITIALISE A MIN HEAP AND A ANS
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        long long ans = 0;
        
        //PUT ALL THE ELEMENTS OF THE ARRAY IN THE MIN HEAP
        for(long long i = 0;i<n;i++){
            pq.push(arr[i]);
        }
        
        // PERFORM THIS UNTILL ONLY ONE ELEMENT LIES IN THE QUEUE
        while(pq.size()>1){
            
            //POP SMALLEST ELEMENT
            long long a = pq.top();
            pq.pop();
            
            //POP SECOND SMALLEST ELEMENT
            long long b = pq.top();
            pq.pop();
            
            //TAKE OUT THIER SUM
            long long sum = a+b;
            
            //ADD THE COST TO FINAL ANS
            ans+=sum;
            
            //PUSH THE NEW LENGTH IN THE MIN HEAP
            pq.push(sum);
            
        }
        
        //RETURN ANS
        return ans;
        
    }
};
