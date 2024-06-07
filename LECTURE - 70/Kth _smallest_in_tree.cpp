/*
  question link -  https://www.naukri.com/code360/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=0&leftPanelTabValue=SUBMISSION
*/


int kthSmallest(BinaryTreeNode<int>* root, int & k) {
    //base case
    if(root==NULL)        return -1;

    //left
    int left = kthSmallest(root->left, k);
    if(left!=-1)             return left;  //if left side se ans agaya to return kardo

    //root
    k--;
    if(k==0){
        return root->data;
    }
    
    // right
    return kthSmallest(root->right, k);
}
