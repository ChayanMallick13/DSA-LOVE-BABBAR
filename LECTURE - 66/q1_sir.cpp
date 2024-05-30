class Solution{
    private:
    
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
    
    
    Node * solve(int in[],int pre[],int & preindex,int instart,int inend,int n){
        //base conditions 
        
        //out of bounds all node done
        if(preindex>=n){
            return NULL;
        }
        
        //no node to left or right
        if(instart>inend){
            return NULL;
        }
        
        // get the index element
        int element = pre[preindex++];
        
        //make a node of the index element
        Node * root = new Node(element);
        
        //find the element in the inorder traversal
        int index = get_index(element,in,instart,inend);
        
        //call for the left part
        root->left = solve(in,pre,preindex,instart,index-1,n);
        
        // call for right part
        root->right = solve(in,pre,preindex,index+1,inend,n);
        
        
        // return the current root
        return root;
    }
    
    Node * solve1(int in[],int pre[],int & preindex,int instart,int inend,int n,unordered_map<int,int> & m){
        //base conditions 
        
        //out of bounds all node done
        if(preindex>=n){
            return NULL;
        }
        
        //no node to left or right
        if(instart>inend){
            return NULL;
        }
        
        // get the index element
        int element = pre[preindex++];
        
        //make a node of the index element
        Node * root = new Node(element);
        
        //find the element in the inorder traversal
        int index = m[element];
        
        //call for the left part
        root->left = solve1(in,pre,preindex,instart,index-1,n,m);
        
        // call for right part
        root->right = solve1(in,pre,preindex,index+1,inend,n,m);
        
        
        // return the current root
        return root;
    }
    
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preindex = 0;
        unordered_map<int,int> m;
        make_map(in,n,m);
        Node * ans = solve1(in,pre,preindex,0,n-1,n,m);
        // Node * ans1 = solve(in,pre,preindex,0,n-1,n);
        return ans;
    }
};
