
/*question : - https://www.geeksforgeeks.org/problems/duplicate-subtrees/1*/

bool is_sam(Node * r1,Node * r2){
    if(r1==NULL && r2==NULL){
        return 1;
    }
    if((r1==NULL && r2!=NULL)||(r1!=NULL && r2 == NULL)){
        return 0;
    }
    
    bool a = (r1->data == r2->data);
    if(!a)
        return 0;
        
    bool b = is_sam(r1->left,r2->left);
    if(!b)
        return 0;
        
    bool c = is_sam(r1->right,r2->right);
    if(!c)
        return 0;
        
    return 1;
}
void find_same(Node * root,Node * key,vector<Node *> & same){
    if(root==NULL)
        return;
    if((root->data == key->data)&&(root!=key)){
        same.push_back(root);
    }
    find_same(root->left,key,same);
    find_same(root->right,key,same);
}
void solve(Node * root,Node * temp,vector<Node *> &s,unordered_map<Node*,bool> & m){
    if(root==NULL){
        return;
    }
    solve(root->left,temp,s,m);
    vector<Node *> same;
    find_same(temp,root,same);
    bool flag = true ;
    for(auto i : same ){
        bool f = is_sam(root,i) ;
        if(f && m[root]==0 && flag){
            s.push_back(i);
            m[i]=1;
            flag = 0 ;
        }
        if(f){
            m[i] = 1 ;
        }
    }
    solve(root->right,temp,s,m);
}

vector<Node*> printAllDups(Node* root)
{
    vector<Node *> ans;
    // set<Node *> s;
    unordered_map<Node *,bool> m;
    solve(root,root,ans,m);
    // for(auto i : s){
    //     ans.push_back(i);
    // }
    return ans;
}
