// https://www.geeksforgeeks.org/problems/huffman-encoding3345/1


class Node {
    public:
    int data;
    Node * left;
    Node * right;
    
    Node(int val) : data(val) , left(NULL) , right(NULL) {}
    
    Node(int val,Node * l,Node * r) : data(val) , left(l) , right(r) {}
};

class cmp{
    public:
    bool operator()(Node * a,Node * b){
        return a->data > b->data;
    }
};

class Solution
{
    
        void pre(vector<string> & ans,string temp,Node * root){
            
            if(root->left==NULL && root->right == NULL){
                ans.push_back(temp);
                return;
            }
            
            temp.push_back('0');
            pre(ans,temp,root->left);
            temp.pop_back();
            temp.push_back('1');
            pre(ans,temp,root->right);
        }
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*,vector<Node*>,cmp> pq;
		    for(int i = 0;i<N;i++){
		        pq.push(new Node(f[i]));
		    }
		    
		    while(pq.size()!=1){
		        Node * a = pq.top();
		        pq.pop();
		        Node * b = pq.top();
		        pq.pop();
		        
		        Node * now = new Node(a->data+b->data,a,b);
		        pq.push(now);
		    }
		    
		    vector<string> ans;
		    string temp = "";
		    pre(ans,temp,pq.top());
		    return ans;
		}
};
