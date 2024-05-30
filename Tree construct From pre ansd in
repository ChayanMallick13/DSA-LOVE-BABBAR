class Solution{
    Node * solve(int in[],int pre[],int & curr,int s,int e,int n){
        if(s>e){
            return NULL;
        }
        if(curr>=n){
            return NULL;
        }
        Node * root = new Node(pre[curr]);
        int index;
        for(int i = s;i<=e;i++){
            if(in[i]==pre[curr]){
                index = i;
                break;
            }
        }
        curr++;
        root->left = solve(in,pre,curr,s,index-1,n);
        root->right = solve(in,pre,curr,index+1,e,n);
        return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int curr = 0;
        Node * ans = solve(in,pre,curr,0,n-1,n);
        return ans;
    }
};
