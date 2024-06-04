/*
  QUESTION LINK : -   https://www.naukri.com/code360/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0
*/


#include <bits/stdc++.h> 

//inorder vector me store karo
void get_in(TreeNode<int>* root,vector<int> & in){

    //base 
    if(root==NULL)
        return ;

    //L
    get_in(root->left, in);

    // N
    in.push_back(root->data);

    //R
    get_in(root->right, in);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> in;
    get_in(root, in);

    //dummy head
    TreeNode<int> * dum = new TreeNode<int>(-1),*tail = dum;

    // in order sorted hota hain to vector se har element uthake new ll return kardo
    for(int i = 0;i<in.size();i++){
        TreeNode<int> * temp = new TreeNode<int>(in[i]);
        temp->left = NULL;
        temp->right = NULL;
        tail->right=temp;
        tail=temp;
    }

    
    return dum->right;
}
