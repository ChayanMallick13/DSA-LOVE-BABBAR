/*  Question : - https://www.naukri.com/code360/problems/h_920474?leftPanelTab=0&leftPanelTabValue=SUBMISSION&nps=true         */


//normal FUNCTION TO STORE THE INORDER OF THE TREE
void get_in(TreeNode *root, vector<int> &ans) {

  if (root == NULL) {
    return;
  }
  get_in(root->left, ans);
  ans.push_back(root->data);
  get_in(root->right, ans);
}

void treetoDLL(TreeNode * root,TreeNode * & head){
  if(root == NULL){
    return;;
  }
  treetoDLL(root->right, head);
  root->right = head;
  if(head)
    head->left = root;
  head = root;
  treetoDLL(root->left, head);
}
TreeNode * merge(TreeNode * h1,TreeNode * h2){
  TreeNode * dum,*tail;
  dum = tail = new TreeNode(-1);
  while(h1&&h2){
    if(h1->data>h2->data){
      tail->right = h2;
      h2->left = tail;
      tail = h2;
      h2=h2->right;
    }
    else{
      tail->right = h1;
      h1->left = tail;
      tail = h1;
      h1=h1->right;
    }
  }
  while(h1){
    tail->right = h1;
    h1->left = tail;
    tail = h1;
    h1=h1->right;
  }
  while(h2){
    tail->right = h2;
    h2->left = tail;
    tail = h2;
    h2=h2->right;
  }
  return dum->right;
}
int len(TreeNode * root){
  int cnt = 0;
  while(root){
    cnt++;
    root=root->right;
  }
  return cnt;
}
TreeNode * create_tree(TreeNode * & head,int n){
  if(head==NULL||n<=0){
    // cout<<head<<endl;
    return NULL;
  }
  TreeNode * left = create_tree(head, n/2);
  TreeNode * root = new TreeNode(head->data);
  root->left = left;
  head = head->right;
  root -> right = create_tree(head, n-n/2-1);
  return root;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
  TreeNode * head1 = NULL,*head2=NULL;
  treetoDLL(root1, head1);
  treetoDLL(root2, head2);
  head1 = merge(head1, head2);
  int n = len(head1);
  TreeNode * root = create_tree(head1, n);
  vector<int> ans;
  get_in(root,ans);
  return ans;
}
