/*
    QUESTION LINK : -    https://www.naukri.com/code360/problems/convert-bst-to-min-heap_920498
*/




//GET THE INORDER IN THE IN VECTOR
void get_in(BinaryTreeNode* root,vector<int> & in){

	//BASE
	if(root == NULL){
		return ;
	}

	//L
	get_in(root->left,in);
	
	//N
	in.push_back(root->data);
	
	//R
	get_in(root->right,in);

}

//TRAVERSE PREORDERLY AND PUT THE INORDER VALUE ONE BY ONE
void populate(BinaryTreeNode* root,int & curr,vector<int> & in){

	//BASE
	if(root==NULL){
		return;
	}

	//POPULATE 
	//N
	root->data = in[curr++];

	//L
	populate(root->left, curr, in);

	//R
	populate(root->right, curr, in);

}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	//TO STORE THE INORDER
	vector<int> in;
	get_in(root,in);

	//POPUATE THE TREE WITH THE INORDER DATA
	int curr = 0;
	populate(root, curr, in);

	// RETURN THE TREE node
	return root;

}
