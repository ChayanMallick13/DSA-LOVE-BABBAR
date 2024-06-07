/*
  question link - https://www.naukri.com/code360/problems/validate-bst_799483?leftPanelTab=0&leftPanelTabValue=PROBLEM
*/

typedef BinaryTreeNode<int> Node;
bool solve(Node * root,int left,int right){
    if(root==NULL){
        return 1;
    }
    return solve(root->left,left,root->data)&&solve(root->right,root->data,right)&&((root->data>=left)&&(root->data<=right));
}
bool validateBST(BinaryTreeNode<int> *root) {
    return solve(root,INT_MIN,INT_MAX);
}
