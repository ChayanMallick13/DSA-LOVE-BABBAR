#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//definition of node
class Node{
    public:
        int data;
        Node * left;
        Node * right;
    public:
        Node(int x) : data(x),left(nullptr),right(nullptr){}
};

Node * insert(Node * root,int data){
    if(root==NULL){
        return new Node(data);
    }
    else if(root->data>data){
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }
}

void take_input(Node * & root){
    int x;
    cout<<"Enter the data to input : ";
    cin>>x;
    while(x!=-1){
        root = insert(root,x);
        cin>>x;
    }
    cout<<"out"<<endl;
}

void level(Node *  root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        if(temp==nullptr){
            cout<<"\n";
            if(!q.empty()){
                q.push(nullptr);
            }
            continue;
        }
        cout<<temp->data<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

void inorder(Node * root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void pre(Node * root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}
void post(Node * root){
    if(root==nullptr){
        return;
    }
    post(root->left);
    post(root->right);
    cout<<root->data<<" ";
}

Node * maxi(Node * root){
    if(root->right!=NULL){
        return maxi(root->right);
    }
    else{
        return root;
    }
}

Node * mini(Node * root){
    if(root->left!=NULL){
        return mini(root->left);
    }
    else{
        return root;
    }
}

Node * delNode(Node * root,int val){
    if(val==root->data){
        if(root->left==NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left&&!root->right){
            Node * temp = root->left;
            delete root;
            return temp;
        }
        else if(!root->left&&root->right){
            Node * temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node * prede = maxi(root->left);
            root->data = prede->data;
            root->left = delNode(root->left,prede->data);
            return root;
        }
    }
    else if(root->data>val){
        root->left = delNode(root->left,val);
    }
    else{
        root->right = delNode(root->right,val);
    }
    return root;
}

int main()
{
    Node * root = nullptr;
    take_input(root);
    cout<<"The level order of the BST is : \n";
    level(root);
    cout<<"\n\nThe inorder of the BST is : \n";
    inorder(root);
    cout<<"\n\nThe pre of the BST is : \n";
    pre(root);
    cout<<"\n\nThe post of the BST is : \n";
    post(root);

    cout<<"\n\nThe minimun in the tree is "<<mini(root)->data<<endl;
    cout<<"\n\nThe maximum in the tree is "<<maxi(root)->data<<endl;

    root = delNode(root,50);
    cout<<"After deletion : \n\n"<<endl;
    cout<<"The level order of the BST is : \n";
    level(root);


    // 70 61 50 40 30 45 65 64 67 69 90 -1
    return 0;
}
