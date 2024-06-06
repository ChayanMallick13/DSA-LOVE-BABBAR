/*  Question : - https://www.naukri.com/code360/problems/h_920474?leftPanelTab=0&leftPanelTabValue=SUBMISSION&nps=true         */


//normal FUNCTION TO STORE THE INORDER OF THE TREE
void get_in(TreeNode *root, vector<int> &ans) {
  //BASE CONDITION
  if (root == NULL) {
    return;
  }

  //LEFT
  get_in(root->left, ans);

  //NODE
  ans.push_back(root->data);

  //RIGHT
  get_in(root->right, ans);
  
}

//FUNCTION TO CONVERT A BSTT TO A DOUBLY LINKE LIST WITH O(HEIGHT) SPACE
void treetoDLL(TreeNode * root,TreeNode * & head){

  //BASE CONDITION
  if(root == NULL){
    return;;
  }

  //RIGHT ME JATE RAHO
  treetoDLL(root->right, head);

  //ROOT KA NEXT PREVIOUS WALA HEAD HOGA CONNECTIONS BANAO
  root->right = head;
  if(head)
    head->left = root;
  
  // NAYA HEAD HOGA ABHI JAHA HAIN HEAD KO MODIFY KARO
  head = root;

  //LEFT KO BANAO 
  treetoDLL(root->left, head);
  
}

//SIMPLE FUNCTION TO MAKE THE MERGING OF TWO SORTED LINKED LIST
TreeNode * merge(TreeNode * h1,TreeNode * h2){

  //DUMMY HEAD
  TreeNode * dum,*tail;
  dum = tail = new TreeNode(-1);

  
  while(h1&&h2){

    //HEAD 1 KA DATA CHOTA HAIN TO YO DALO
    if(h1->data>h2->data){
      tail->right = h2;
      h2->left = tail;
      tail = h2;
      h2=h2->right;
    }
    else{    //NAHI TO HEAD2 DALO
      tail->right = h1;
      h1->left = tail;
      tail = h1;
      h1=h1->right;
    }
  }

  // H1 ME JITNA BAKI BACHA HAIN DAL DO
  while(h1){
    tail->right = h1;
    h1->left = tail;
    tail = h1;
    h1=h1->right;
  }

  //H2 ME JITNA BAKI HAIN UTNA DALDO
  while(h2){
    tail->right = h2;
    h2->left = tail;
    tail = h2;
    h2=h2->right;
  }

  //HEAD RETURN KARO
  return dum->right;
  
}

//FUNCTION TO CALCULATE THE LENGTH OF A LINKED LIST
int len(TreeNode * root){
  int cnt = 0;
  while(root){
    cnt++;
    root=root->right;
  }
  return cnt;
}

//FUNCTION TO CREATE A BST FROM A SORTED LINKED LIST
TreeNode * create_tree(TreeNode * & head,int n){

  //BASE CONDITION
  if(head==NULL||n<=0){
    return NULL;
  }

  // N/2 PREVIOUS NODES SE LEFT PART BANAKE LAO OR USKA ROOT RETURN KARO
  TreeNode * left = create_tree(head, n/2);

  // N TH NODE SE ROOT NODE BANALO OR LEFT CONNECTION BANAO LEFT PART WALA SE
  TreeNode * root = new TreeNode(head->data);
  root->left = left;

  //HEAD AB HEAD KA NEXT HOGA YE DATA USED HO GAYA ISILIYE
  head = head->right;

  //REST N - N/2 - 1 BAKI NODES SE RIGHT PART BANAKE LAO OR UKA ROOT RETURN KARO AND RIGHT CONNECTIONS BANAO 
  root -> right = create_tree(head, n-n/2-1);

  //RETURN KARO ROOT
  return root;
  
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
  //LINKED LIST CONVERSION
  TreeNode * head1 = NULL,*head2=NULL;
  treetoDLL(root1, head1);
  treetoDLL(root2, head2);

  //MERGE THE TWO SORTED LINKED LIST TO ONE
  head1 = merge(head1, head2);

  //MAKE THE TREE FROM THE SORTED LINKED  LIST
  int n = len(head1);
  TreeNode * root = create_tree(head1, n);

  //JO TREE BANAO USKA INORDER STORE KARAKE LAO
  vector<int> ans;
  get_in(root,ans);

  //ANSWER RETURN KARO
  return ans;
  
}
