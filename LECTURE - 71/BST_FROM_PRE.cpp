/*
QUESTION LINK :-   https://www.naukri.com/code360/problems/preorder-traversal-to-bst_893111?leftPanelTab=0
*/


#include <bits/stdc++.h> 

typedef BinaryTreeNode<int> Node;

//use the interval strategy like for checking is BST or root
Node * create(vector<int> & pre,int & i,int l,int r){

    //sab nodes dal diya return karo
    if(i>=pre.size()){
        return NULL;
    }

    //yahi nahi dal sakte hain back karo
    if(pre[i]>r||pre[i]<l){
        return NULL;
    }

    //dal sakte hain to new Node banao
    Node * root = new Node(pre[i++]);

    //left part banake lao
    root->left = create(pre, i, l, root->data);

    //right part banake lao
    root->right = create(pre, i, root->data, r);

    //answer return karo
    return root;
    
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int i = 0;
    return create(preorder, i, INT_MIN, INT_MAX);
}
