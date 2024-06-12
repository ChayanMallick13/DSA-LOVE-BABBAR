#include<iostream>
#include<vector>
using namespace std;

//The Node structure for a Trie Node
class TrieNode {

    public:
    
    //it will store the character
    char data;

    //it will create the 52 childrens of capital and small letters
    TrieNode ** children;

    //is it a terminal node to resolve ambiguity
    bool isTerminal;

    //construtor for initialisation
    TrieNode(char data){

        //set the character data
        this->data = data;

        //allocte the space for the 52 chilrens
        children = new TrieNode*[52];

        //initially set the terminal false
        isTerminal = false;

        //set all childrens of the node before as NULL
        for(int i = 0;i<52;i++){

            children[i]=NULL;

        }

    }

};


//class containing the function for functions and utilities of the trie
class Trie {

    //contains the private functions
    private:

    //create a root with null character
    TrieNode * root = new TrieNode('\0');

    //function for getting the child array index for a character
    int get_index(char c){

        //for small caharcters
        if(c>='a'&&c<='z'){

            return c-'a';

        }
        else{   //for capital letters

            return 26 + c - 'A';

        }

    }

    //function for insertion
    void insert(TrieNode * root,string s){

        //base case
        if(s.length()==0){

            //set root node terminal true so it can be searched
            root->isTerminal = true;

            return;

        }

        //find its children index
        int index = get_index(s[0]);

        //check if for that child is it null
        if(root->children[index]==NULL){

            //if true create a new node for that character and set as root s child
            root->children[index] = new TrieNode(s[0]);

        }

        //now root is the new children
        root = root->children[index];

        //nw call the insert function for the rest of the string
        insert(root,s.substr(1));

    }

    //function for searching in the trie
    bool search(TrieNode * root,string s){

        //base case
        if(s.length()==0){

            //if this is the terminal then this word will be present else not
            return root->isTerminal;

        }

        //get the index for the child dor the character
        int index = get_index(s[0]);

        //if it is NULL
        if(root->children[index]==NULL){

            //the string or word is thus not present thus return false
            return false;

        }

        //else check for the rest of the string characters
        return search(root->children[index],s.substr(1));

    }

    //function for deletion
    TrieNode * remove(TrieNode * root,string s){

        //base case
        if(s.length()==0){

            //if it was not a terminal node then this word is not present
            if(root->isTerminal==false){

                cout<<"No such Word to delete"<<endl;

            }

            //make the terminal as false to delete 
            root->isTerminal = false;

            //check if it has childrens that is it is common to more words
            for(int i = 0;i<52;i++){

                //if yes then nothing to do return
                if(root->children[i]){

                    return root;

                }

            }

            //else it is not common to any other word so delete it
            delete root;

            return NULL;

        }

        //find the index of the next character for the child array
        int index = get_index(s[0]);

        //if the child for that char not exist then eord does not exist nothing to delete
        if(root->children[index]==NULL){

            cout<<"No such WORD to delete"<<endl;

            return root;

        }

        //if present calll for the deletion of that node
        root->children[index]=remove(root->children[index],s.substr(1));

        //if this is common to any other i.e it has is terminal or has any child do not delete 
        if(root->isTerminal){
            return root;
        }
        for(int i = 0;i<52;i++){
            if(root->children[i]){
                return root;
            }
        }

        //else delete it
        delete root;

        return NULL;

    }

    //function for searching that if the words starting with s exist or not
    bool prefix_search(TrieNode * root,string s){

        //base case
        if(s.length()==0){

            //yaha takk agay matlab is prefix ka word hain
            return true;

        }

        //get the index of the children 
        int index = get_index(s[0]);

        //agar exist nahi kar raha hain to false return karo
        if(root->children[index]==NULL){

            return false;

        }

        //agar hain to rest string keliye check karo
        return prefix_search(root->children[index],s.substr(1));

    }

    //function for showing suggestions no 1
    void extend(TrieNode * root,vector<string> & ans,string temp){

        //if this is a possible word then sore it
        if(root->isTerminal){

            //add this character
            temp.push_back(root->data);

            //store in the vector
            ans.push_back(temp);

        }

        //else store this character and search for another possible word
        temp.push_back(root->data);

        //call this for all possible braches of the current root
        for(int i = 0;i<52;i++){

            if(root->children[i]){

                extend(root->children[i],ans,temp);

            }

        }

    }

    //function for showing suggestions no 2
    void get_em(TrieNode * root,string s,vector<string> & ans,int i){

        //base case
        if(i==s.length()){

            //pata chal gaya ki yaha tak words hain atleast ab no 1 kam karega
            extend(root,ans,s.substr(0,i-1));

        }

        //find the index for the child
        int index = get_index(s[i]);

        //agar children nahi hain to is word se suru hone wala koi nahi return
        if(root->children[index]==NULL){

            return;

        }

        //agar hain to next character ke liye check karo
        get_em(root->children[index],s,ans,i+1);

    }

    //now the function with a abstraction layer
    public:

    //driver function for insertion
    void insert_word(string s){

        insert(root,s);

    }

    //driver function for seraching
    bool search_word(string s){

        return search(root,s);

    }

    //driver function for deletion
    void remove_word(string s){

        remove(root,s);

    }

    //driver function for serching for a prefix
    bool words_present_for(string s){

        return prefix_search(root,s);

    }

    //driver function for showing suggestions
    vector<string> show_suggestions(string s){
        
        //vector for storing the answer
        vector<string> ans;

        get_em(root,s,ans,0);

        return ans;

    }
    
};







