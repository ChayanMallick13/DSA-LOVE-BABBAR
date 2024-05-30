class Solution
{
     //find the index of the root in the inorder to call for left and right
    int get_index(int element,int in[],int instart,int inend){
        for(int i = instart;i<=inend;i++){
            if(in[i]==element)
                return i;
        }
        return -1;
    }
    
    //map banan lo
    void make_map(int in[],int n,unordered_map<int,int> & m){
        for(int i = 0;i<n;i++){
            m[in[i]]=i;
        }
    }
    
    Node * solve(int in[],int post[],int & postindex,int instart,int inend,int n){
        //base conditions 
        
        //out of bounds all node done
        if(postindex<0){
            return NULL;
        }
        
        //no node to left or right
        if(instart>inend){
            return NULL;
        }
        
        // get the index element
        int element = post[postindex--];
        
        //make a node of the index element
        Node * root = new Node(element);
        
        //find the element in the inorder traversal
        int index = get_index(element,in,instart,inend);
        
        /*
        [We make the right call first because as we make the root from post array 
        then we make index -- so now the index element will be present in the 
        second half so right call mustr be done first]
        */
        
        // call for right part
        root->right = solve(in,post,postindex,index+1,inend,n);
        
        
        //call for the left part
        root->left = solve(in,post,postindex,instart,index-1,n);
        
        
        // return the current root
        return root;
    }
    
    
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        int postindex = n-1;
        unordered_map<int,int> m;
        make_map(in,n,m);
        return solve(in,post,postindex,0,n-1,n);
    }
};
