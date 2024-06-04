/*
  QUESTION - https://www.naukri.com/code360/problems/two-sum-in-a-bst_1062631?leftPanelTab=0
*/

#include <bits/stdc++.h> 

//store the inorder in a vector by doing inorder traversal in the BST
void get_in(BinaryTreeNode<int>* root,vector<int> & in){

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
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {

	vector<int> in;
    get_in(root,in);
    int i = 0,j=in.size()-1;
    int sum;
    //perform two sum question on sorted array by two pointers i and j
    while(i<j){
        sum = in[i]+in[j];

        //mil gaya
        if(sum==target)
            return 1;

        //chota ele chahiye
        if(sum>target)
            j--;

        //bada ele chahiye
        if(sum<target)
            i++;
            
    }

    return 0;
}
