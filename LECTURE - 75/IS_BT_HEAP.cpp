/*
      QUESTION LINK :- https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1
*/



class Solution {
    private:
    
    //FUNCTION TO COUNT NO OF NODES IN THE TREE
    int get_nodes(Node * root){
        
        //BASE
        if(root == 0){
            return 0;
        }
        
        //COUNT LEFT AND RIGHT NODES AND ADD 1 TO ANS
        return get_nodes(root->left)+get_nodes(root->right)+1;
        
    }
    
    //FUNCTION TO CHECK WHETHER THE BINARY TREE IS COMPLETE OR NOT
    bool iscbt(Node * root,int nodes,int i){
        
        //BASE COND
        if(root == NULL){
            return 1;
        }
        
        //IT SHOUL NOT OCCUR IN A COMPLETE BINARY TREE
        if(i>nodes){
            return 0;
        }
        
        //UPTO THIS NODE IT IS CBT CHECK FOR LEFT AND RIGHT TREE AND RETURN ANS
        return iscbt(root->left,nodes,2*i)  &&  iscbt(root->right,nodes,2*i+1);
        
    }
    
    //FUNCTION TO CHECK THE ORDER FOLLOW IN THE TREE MAX HEAP ORDER
    bool forder(Node * root,int limit){
        
        //BASE COND
        if(root == NULL){
            return 1;
        }
        
        //EVERY BELOW NODE SHOULD HAVE A VALUE LESS THAN THE ROOT NODE
        bool a = root->data <= limit;
        
        //CHECK FOR LEFT AND RIGHT SUBTREE
        return a&&forder(root->left,root->data)&&forder(root->right,root->data);
        
    }
  public:
    bool isHeap(struct Node* tree) {
        
        //TO CHECK IF BT IS A HEAP TWO CONDN IS TO SATISFY
        // 1> IS COMPLETE BT
        // 2> FOLLOW THE HEAP ORDER MAX HEAP HERE
        
        //GET NUMBER OF TREE NODES
        int no_of_nodes = get_nodes(tree);
        
        //CHECK FOR IS COMPLETE BINARY TREE
        bool isCBT = iscbt(tree,no_of_nodes,1);
        
        // CHECK FOR IF IT FOLLOWS THE MAX HEAP ORDER
        bool FollowsOrder = forder(tree,INT_MAX);
        
        // RETURN ANS
        return isCBT && FollowsOrder;
    }
};
