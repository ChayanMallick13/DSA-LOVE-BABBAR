class Solution
{
    Node * solve(int in[],int post[],int & curr,int s,int e,int n){
        if(s>e){
            return NULL;
        }
        if(curr<0){
            return NULL;
        }
        Node * root = new Node(post[curr]);
        int index;
        for(int i = s;i<=e;i++){
            if(in[i]==post[curr]){
                index = i;
                break;
            }
        }
        curr--;
        root->right =  solve(in,post,curr,index+1,e,n);
        root->left = solve(in,post,curr,s,index-1,n);
        return root;
    }
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        int curr = n-1;
        Node * ans = solve(in,post,curr,0,n-1,n);
        return ans;
    }
};
