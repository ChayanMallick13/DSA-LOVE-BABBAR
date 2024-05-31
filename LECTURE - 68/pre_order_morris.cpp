class Solution{
    private:
    Node * find(Node * root){
        if(root==NULL){
            return NULL;
        }
        Node * temp = root;
        temp = temp->left;
        while(temp->right!=NULL&&temp->right!=root){
            temp=temp->right;
        }
        return temp;
    }
    public:
    vector<int> preOrder(Node* root)
    {
        vector<int> ans;
        Node * curr = root;
        while(curr!=NULL){
            if(curr->left){
                Node * pre = find(curr);
                if(pre->right){
                    pre->right = NULL;
                    curr = curr->right;
                }
                else{
                    pre->right = curr;
                    ans.push_back(curr->data);
                    curr = curr->left;
                }
                
            }
            else{
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
        return ans;
    }
};
