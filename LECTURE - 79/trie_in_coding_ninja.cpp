/*

      Question Link :-   https://www.naukri.com/code360/problems/implement-trie_631356?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

*/


/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class Node  {
    public:
        char data;
        Node ** child;
        bool isTerminal;

    public:
        Node(char data){
            this->data = data;
            isTerminal = false;
            child = new Node*[26];
            for(int i = 0;i<26;i++){
                child[i]=NULL;
            }
        }
};


class Trie {
private:
    void in(Node * root,string s){
        if(s.length()==0){
            root->isTerminal = true;
            return;
        }

        int index = s[0]-'a';
        if(root->child[index]==NULL){
            root->child[index]=new Node(s[0]);
        }
        in(root->child[index], s.substr(1));
    }
    bool se(Node * root,string s){
        if(s.length()==0){
            return root->isTerminal;
        }

        int index = s[0]-'a';

        if(root->child[index]==NULL){
            return false;
        }

        return se(root->child[index], s.substr(1));
    }
    bool start(Node * root,string s){
        if(s.length()==0){
            return true;
        }

        int index = s[0]-'a';

        if(root->child[index]==NULL){
            return false;
        }

        return start(root->child[index], s.substr(1));
    }
public:
    Node * root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node('\0');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        in(root, word);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return se(root, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return start(root, prefix);
    }
};
