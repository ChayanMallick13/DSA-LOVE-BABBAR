/*



*/



/********************    Approach - 1 ***********/
string longestCommonPrefix(vector<string> &arr, int n)
{
    string s = arr[0];
    string ans="";
    for(int j = 0;j<s.length();j++){
      int ch = s[j];
      for(int i = 1;i<n;i++){
        if(arr[i][j]!=ch){
          return ans;
        }
      }
      ans.push_back(ch);
    }
    return ans;
}
/****************************************************************************/




/***************************    Appproach - 2    **************/
#include<bits/stdc++.h>

class node {
  public:
  char data;
  node * child;
  bool isterminal;

  node(char c) : data(c),child(NULL),isterminal(false){}
};

class trie{
  node * root = new node('-');

  void in(node * root,string s){
    if(s.length()==0){
      root->isterminal = true;
      return;
    }
    if(root->child == NULL){
      root->child = new node(s[0]);
      in(root->child, s.substr(1));
    }
    else if(root->child->data == s[0]){
      in(root->child, s.substr(1));
    }
    else{
      root->isterminal = true;
      return;
    }
  }

  void ans(node * root,string & a){
    if(root->isterminal){
      if(root->data != '-'){
        a.push_back(root->data);
      }
      return;
    }
    if(root->data != '-')
      a.push_back(root->data);
    ans(root->child, a);
  }
  public:
  void insert(string s){
    in(root, s);
  }
  void get_ans(string & a){
    ans(root, a);
  }
};



string longestCommonPrefix(vector<string> &arr, int n)
{
  trie * t = new trie;
  for(auto i : arr){
    t->insert(i);
  }
  string a="";
  t->get_ans(a);
  return a;
}

/****************************************************************************/





/**********************  Approach - 3 ********************/
class node {
  public:
  char data;
  bool isterminal;
  node ** child;
  int count;

  node(char x) : data(x),isterminal(false),count(0){
    child = new node*[26];
    for(int i = 0;i<26;i++){
      child[i]=NULL;
    }
  }
};

class trie {
  node * root = new node('\0');
  void in(node * root,string s){
    if(s.length()==0){
      root->isterminal=true;
      return;
    }
    int index = s[0]-'a';

    if(root->child[index]==NULL){
      root->child[index]=new node(s[0]);
      root->count++;
    }
    
    in(root->child[index],s.substr(1));
  }

  void get(node * root,string ans,string & t){
    for(int i = 0;i<ans.length();i++){
      if(root->count!=1){
        return;
      }
      if(root->isterminal){
        return;
      }
      t.push_back(root->child[ans[i]-'a']->data);
      root = root->child[ans[i]-'a'];
    }
  }

  public:
  void insert(string s){
    in(root, s);
  }

  void getns(string ans,string & t){
    get(root, ans, t);
  }
};



string longestCommonPrefix(vector<string> &arr, int n)
{
    trie * t = new trie;
    for(auto i : arr){
      t->insert(i);
    }
    string ans="";
    t->getns(arr[0],ans);
    return ans;
}

/****************************************************************************/
