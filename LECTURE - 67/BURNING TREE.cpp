class Solution {
    
    //create a mapping for the nodes with thier parent using level order traversal
    Node * make_mapping(Node * root,map<Node *,Node *> & m,int start){
        
        queue<Node *> q;
        q.push(root);
        
        //no parent for root
        m[root]=NULL;
        
        //this will store the target node address and return it
        Node * ans;
        
        while(!q.empty()){
            
            Node * temp = q.front();
            q.pop();
            
            //to find the target node
            if(temp->data==start){
                ans = temp;
            }
            
            //if left exists 
            if(temp->left){
                m[temp->left]=temp;
                q.push(temp->left);
            }
            
            //if right exists
            if(temp->right){
                m[temp->right]=temp;
                q.push(temp->right);
            }
            
        }
        return ans;
    }
    
    //start burning the tree from the target node
    int solve(Node * start,map<Node *,Node *> & m){
        
        // mapping to check if the node is burnt or not
        map<Node *,bool> visited;
        
        //queue for do bfs including the root node
        queue<Node *> q;
        q.push(start);
        
        int ans = 0;
        bool flag = 0;
        
        
        while(!q.empty()){
            
            //check the number of nodes caught on fire
            int n = q.size();
            
            //burn them and see if more nodes are there to burn
            for(int i = 0;i<n;i++){
                
                //take out the node
                Node * temp = q.front();
                q.pop();
                
                //mark it visited
                visited[temp]=1;
                
                //check for left child to burn
                if(temp->left&&(!visited[temp->left])){
                    flag = 1;
                    q.push(temp->left);
                }
                
                //check for the right child to burn
                if(temp->right&&(!visited[temp->right])){
                    flag = 1;
                    q.push(temp->right);
                }
                
                //check for the parent to burn
                if(m[temp]&&(!visited[m[temp]])){
                    flag = 1;
                    q.push(m[temp]);
                }
                
            }
            
            //if more nodes are to be burned increase the time
            if(flag)
                ans++;
                
            // reset flag
            flag = 0;
            
        }
        return ans;
    }
  public:
    int minTime(Node* root, int target) 
    {
        map<Node *,Node *> m;
        
        //get the target node
        Node * s = make_mapping(root,m,target);
        
        return solve(s,m);
    }
};
