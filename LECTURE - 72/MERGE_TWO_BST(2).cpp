/*
QUESTION :- https://www.naukri.com/code360/problems/h_920474?leftPanelTab=0&leftPanelTabValue=SUBMISSION&nps=true
*/

//FUNCTION TO GET THE INORDER IN A  VECTOR FROM A BST
void get_in(TreeNode *root, vector<int> &ans) {

  //BASE CONDN
  if (root == NULL) {
    return;
  }

  //LEFT
  get_in(root->left, ans);

  //NODE
  ans.push_back(root->data);

  //LEFT
  get_in(root->right, ans);
  
}

//FUNCTION TO MERGE TWO SORTED VECTORD INTO ONE ANOTHER VECTOR
void merge(vector<int> &a, vector<int> &b, vector<int> &c) {

  //TWO POINTERS ASSEMBLE
  int i = 0;
  int j = 0;
  int n = a.size();
  int m = b.size();

  
  while (i < n && j < m) {
    
    //B KA DATA CHOTA HAIN TO YO DALO
    if (a[i] > b[j]) {
      c.push_back(b[j]);
      j++;
    } else {   //NAHI TO A KA DATA DALO
      c.push_back(a[i]);
      i++;
    }
  }

  //A KA JITNA DATA BACH GAYA YO DAL DO AB
  while (i < n) {
    c.push_back(a[i++]);
  }

  //B KA AGAR DATA BACH GAYA TO WO DAL TO AB
  while (j < m) {
    c.push_back(b[j++]);
  }

  //DONE 
}

// FUNCTION TO CREATE A BST FROM A SORTED VECTOR
TreeNode *create(vector<int> &c, int s, int e) {

  //BASE CONDITION
  if (s > e) {
    return NULL;
  }
  //MID NIKALO
  int m = s + (e - s) / 2;

  //MID SE NODE BANALO
  TreeNode *root = new TreeNode(c[m]);

  //LEFT PART SE TREE BANAKE LAO OR ROOT SE CONNECT KARO
  root->left = create(c, s, m - 1);
  //RIGHT PART SE TREE BNAKAE LAO OR ROOT SE CONNECT KARO
  root->right = create(c, m + 1, e);

  //TREE KA ROOT RETURN KARO
  return root;
  
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2) {

  //INRODER NIKAL LA DO TREES KA
  vector<int> a, b, c;
  get_in(root1, a);
  get_in(root2, b);

  //DONO KA INOORDER MERGE KARNA
  merge(a, b, c);

  //MERGED INOREDR KO INORDER LEKE NAYA TREE BANALO
  TreeNode * root = create(c, 0, c.size()-1);

  //NAYA BANAYA HUA TTREE KA INORDER NIKALO
  vector<int> d;
  get_in(root, d);

  //ANSWER JO NIKALO YO RETURN KARO
  return d;
  
}
