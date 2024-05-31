class Solution {
private:

//to find the predeccesor
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
    vector<int> inOrder(Node* root)
    {
        //code here
        vector<int> ans;
        Node * curr = root;
        while(curr!=NULL){
            if(curr->left){
                Node * pre = find(curr);
                if(pre->right){
                    pre->right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
                else{
                    pre->right = curr;
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
