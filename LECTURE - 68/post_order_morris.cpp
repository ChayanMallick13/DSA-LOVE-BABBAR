class Solution{
    Node * find(Node * root){
        if(root==NULL){
            return NULL;
        }
        Node * temp = root;
        temp = temp->right;
        while(temp->left!=NULL&&temp->left!=root){
            temp=temp->left;
        }
        return temp;
    }
    public:
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        Node * curr = root;
        while(curr!=NULL){
            if(curr->right){
                Node * pre = find(curr);
                if(pre->left){
                    pre->left = NULL;
                    curr = curr->left;
                }
                else{
                    pre->left = curr;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
                
            }
            else{
                ans.push_back(curr->data);
                curr = curr->left;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
