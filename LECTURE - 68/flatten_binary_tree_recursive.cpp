class Solution
{
    private:
    Node * solve(Node * root){
        
        //base case
        if(root==NULL){
            return NULL;
        }
        
        //make the left subtree as a ll and get the head
        Node * left = solve(root->left);
        
        //make the right subtree as a ll and get the head
        Node * right = solve(root->right);
        
        //make the left of root as null
        root->left = nullptr;
        
        //right of root is left subtree ll
        root->right = left;
        
        //left ka end node ka right ko right karo
        while(left!=NULL&&left->right!=NULL){
            left = left->right;
        }
        if(left)
            left->right = right;
        
        // left nahi hain right hain
        if(left==NULL&&right!=NULL)
            root->right = right;
            
            
        // return head
        return root;
    }
    public:
    void flatten(Node *root)
    {
        root = solve(root);
    }
};
