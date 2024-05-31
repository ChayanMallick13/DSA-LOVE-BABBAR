class Solution
{
    private:
    Node* solve(Node * root){
        if(root==NULL){
            return NULL;
        }
        
        Node * temp = newNode(root->key);
        temp->right = solve(root->left);
        Node * t = temp;
        while(t->right!=NULL){
            t=t->right;
        }
        t->right = solve(root->right);
        return temp;
    }
    public:
    void flatten(Node * & root)
    {
        root = solve(root);
    }
};
