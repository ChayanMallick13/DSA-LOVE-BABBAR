/*
  Question :-  https://www.naukri.com/code360/problems/lca-in-a-bst_981280?leftPanelTab=0&leftPanelTabValue=SUBMISSION
*/


TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    //check NULL agay
    if(root==NULL)
        return NULL;

    
    if(root->data < P->data && root->data < Q->data)   //dono right me hain to right jao
        return LCAinaBST(root->right, P, Q);
    
    
   
    else if((root->data > P->data && root->data > Q->data))  //dono left me hain to left jao
        return LCAinaBST(root->left, P, Q);
   
    else   //dono alag alag side hain to yahi lca hain
        return root;
}
