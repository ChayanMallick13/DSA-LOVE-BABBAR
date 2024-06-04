/*
  question link - https://www.naukri.com/code360/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0
*/


#include <bits/stdc++.h>

//store the inorder in a vector
void get_in(TreeNode<int>* root,vector<int> & in){
    //base
    if(root==NULL)
        return ;

    //L
    get_in(root->left, in);

    //N
    in.push_back(root->data);

    //R
    get_in(root->right, in);

}

//function to create a balanced BST from inorder
TreeNode<int> * create(int s,int e,vector<int> & in){
    //base
    if(s>e){
        return nullptr;
    }

    //find mid
    int m = s+(e-s)/2;

    //make a new Node
    TreeNode<int>* root = new TreeNode<int>(in[m]);

    //left part banake lao
    root->left = create(s, m-1, in);

    //right part banake lao
    root->right = create(m+1, e, in);

    //ans return karo
    return root;
}


TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> in;
    get_in(root, in);
    return create(0, in.size()-1, in);
}
