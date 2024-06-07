/*
  QUESTION LINK :-   https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
*/



class Solution{
    private:
    void heapify(vector<int> & arr,int size,int i){
        
        int check = i;
        
        // TAKE OUT THE LEFT CHILD INDEX
        int left = 2*i+1;
        
        // TAKE OUT THE RIGHT CHILD INDEX
        int right = 2*i+2;
        
        //CHECK IF LEFT EXIST AND CHECK IS TO SWAP WITH PARENT
        if(left<size && arr[left]>arr[i] && (right>=size || arr[right]<arr[left])){
            swap(arr[left],arr[i]);
            i = left;
        }                       //SAME CHECK FOR RIGHT CHILD
        else if(right < size && arr[right] > arr[i]){
            swap(arr[right],arr[i]);
            i = right;
        }
        
        
        //CHECK IF ANY CHANGE IS MADE
        if(i != check){
            
            //CHANGE MADE SO CALL FOR THE HEAIFY FUNCTION FOR THE SWAPPED ELEMENT
            heapify(arr,size,i);
            
        }
        else{
            
            //NO CHANGE MADE SO RETURN 
            return;
        }
    }
    
    //FUNCTION TO MAKE A VECTOR A HEAP
    void make_heap(vector<int> & arr,int size){
        
        //START FROM EXCEPT THE LEAF (LEAF FROM N/2 TO N) SO STRAT FROM /2-1
        for(int i = size/2-1;i>=0;i--){
            
            // HEAPIFY THE SELECTED NODE
            heapify(arr,size,i);
            
        }
        
    }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        // MERGE THE TWO HEP ARRAYS INT ONE
        vector<int> c;
        for(auto i : a){
            c.push_back(i);
        }
        for(auto i : b){
            c.push_back(i);
        }
        
        //HEAPIFY THE ARRAY
        make_heap(c,m+n);
        
        // return the vector ans c
        return c;
        
    }
};
