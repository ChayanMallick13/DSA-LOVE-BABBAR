/*
  QUESTION LINK = https://www.naukri.com/code360/problems/largest-bst-subtree_893103?leftPanelTab=0&leftPanelTabValue=PROBLEM
*/

// creating a new class to return four value in function call
class datas{
    public:
    // no of nodes in BST 
    int nodes;

    //maximum value in BST
    int maxi;

    //minimum value in BST
    int mini;

    //Is the BT a binary tree
    bool isBst;

    //CONSTRUCTOR
    datas(int a,int b,int c,bool d) : nodes(a),maxi(b),mini(c),isBst(d){}

};

//SOLVE FUNCTION
datas solve(TreeNode * root,int & ans){
    //BASE CONDITION
    if(root == NULL ){
        datas ret(0,INT_MIN,INT_MAX,1);
        return ret;
    }

    //LEFT KA HAL CHECK KARO
    datas left = solve(root->left,ans);

    //RIGHT KA HAL CHECK KARO
    datas right = solve(root->right,ans);

    //CHECK KARO KYA YE BST HAIN
    // 4 CHECKS
    // 1> LEFT TREE BST HONA CHAHIYE LEFT.ISBST = 1
    // 2> RIGHT TREE BST HONA CHAHIYE RIGHT.ISBST = 1
    // 3> LEFT PART KA MAXI  LEFT.MAXI SE ROOT KA DATA BADA HONA CHAHIYE
    // 4> RIGHT PART KA MINI SE ROOT KA DATA CHOTA HONA CHAHIYE
    bool isBst = left.isBst&right.isBst&(root->data>left.maxi && root->data < right.mini);

    //NO OF NODES CHANGE HOGA
    int nodes = left.nodes + right.nodes +1;

    //AGAR YE BST HAIN TO ANS UPDATE KARO
    if(isBst){
        ans = max(ans,nodes);
    }

    //RETURN KARNE KE LIYE OBJECT READY KARO
    datas ret(nodes,max(root->data,right.maxi),min(left.mini,root->data),isBst);

    // OBJECT RETURN KARDO
    return ret;
}
int largestBST(TreeNode * root){

    //ANSWER STORE RAHE GA
    int ans = INT_MIN;

    // FUNC call
    solve(root, ans);

    // RETURN ANS
    return ans;
    
}
