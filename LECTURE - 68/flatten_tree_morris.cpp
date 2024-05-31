class Solution
{
    private:
    
    //function to find the inorder predeccesor
    Node * find(Node * root){
        if(root==nullptr){
            return NULL;
        }
        
        root = root->left;
        while(root->right!=NULL){
            root = root->right;
        }
        
        return root;
    }
    
    
    public:
    void flatten(Node *root)
    {
        
        // cuurent is  root
        Node * curr = root;
        
        while(curr!=NULL){
            
            if(curr->left==NULL){       //left child do not exist
                //increment cuur to right
                curr = curr->right;
            }
            else{                       //left child exist
                // get predeccesor
                Node * pre = find(curr);
                
                //make connection of predeccesor to right of curr
                pre->right = curr->right;
                
                //curr ka left connection thodo and make right left
                curr->right = curr->left;
                curr->left = NULL;
                
                //increment cuur to right
                curr=curr->right;
            }
        }
    }
};
