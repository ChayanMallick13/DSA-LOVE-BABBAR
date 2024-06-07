/*
QUESTION LINK :- 
*/

/*******************************************************  APPROACH 1  **************************************************************/
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        
        //Approach 1
        vector<int> ans;
        
        //make a new vector from the given datas
        for(int i = l;i<=r;i++){
            ans.push_back(arr[i]);
        }
        
        //sort the array
        sort(ans.begin(),ans.end());
        
        //return the ans
        return ans[k-1];
    }
};

/*****************************************************************************************************************************************/



/*******************************************************  APPROACH 2  ********************************************************************/

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        
        //   APPROACH 2 USING HEAP MAX HEAP
        
        //INITIALISE A MAX HEAP
        priority_queue<int> pq;
        
        // ENTER THE FIRST K ELEMENTS OF THE ARRAY
        for(int i = l;i<k;i++){
            pq.push(arr[i]);
        }
        
        //JUST TRAVERSE THROUGH REST N-K ELEMENTS ANS
        //JUST CHECK THE TOP OF THE MAXHEAP IF IT IS GREATER POP PUSH THE ARRAY ELEMENT
        for(int i = k;i<=r;i++){
            if(pq.top()>arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        //NOW THE HEAP WILL CONTAIN ONLY K SMALLEST ELEMENTS AND MAX HEAP TOP IS THE ANS
        return pq.top();
        
    }
    
};
