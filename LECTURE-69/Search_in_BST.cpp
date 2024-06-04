bool searchInBST(BinaryTreeNode<int> *root, int x) {
  
    while(root){
      //mil gaya node
        if(root->data==x){
            return 1;
        }

        // left me hoag agar hain to , left me serach karo
        else if(root->data>x){
            return searchInBST(root->left, x);
        }

        //right me hi hoga nahito,right serach karo
        else{
            return searchInBST(root->right,x);
        }
        return 0;
    }
}
