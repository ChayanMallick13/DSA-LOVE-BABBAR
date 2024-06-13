/*

    QUESTION LINK :-    https://www.naukri.com/code360/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

*/





// Node struture for a trie
class TrieNode {

    //data memebers
    public:

        //main data character for the node
        char data;

        //IS NODE KE 26 BIRADRI WALE
        TrieNode ** child;

        //TERMINAL NODE HAIN KI NAHI CHECK KARNE KE LIYE
        bool isTerminal;
    

    //MEMBER FUNCTIONS
    public:

        //CONSTRUCTOR
        TrieNode(char x){

            //SET NODES DATA
            this->data=x;

            //MAKE THE SPACE FOR STORING THE ADDRESS OF THE 26 CHILDRENS
            this->child = new TrieNode *[26];

            //SET THE CHILDRENS TO NULL FOR NEW NODE
            for(int i = 0;i<26;i++){
                child[i]=NULL;
            }

            //SET THE TERMINAL TO FALSE FOR NEW NODE
            this->isTerminal=false;

        }

};


//TRIE CLASS WITH UTILITIES FUNCTION
class Trie {

    // DATA MEMEBERS 
    private:
        
        // ROOT OF THE TRIE 
        TrieNode * root = new TrieNode('\0');

    //BACKEND FUNCTIONS
    private:

        //INSRTION FUNCTION
        void in(TrieNode * root,string s){

            //IF THE WHOLE WORD IS INSERTED MARK THE LAT WORD NODE AS TERMINAL
            if(s.length()==0){

                root->isTerminal = true;
                return;

            }

            //ELSE TAKE OUT THE CHILD INDEX FOR THAT CHARACTER
            int ind = s[0]-'a';

            //IF CHILD NOT EXIST MAKE IT
            if(root->child[ind]==NULL){
                root->child[ind] = new TrieNode(s[0]);
            }

            //NOW CALL FOR THE CHILD WITH THE REST OF THE WORD
            in(root->child[ind], s.substr(1));

        }


        //THIS FUNCTION GENERATES ALL THE WORDS POSSIBLE TO GET FROM THAT NODE AND STORE IN VECTOR
        void print_suggest(vector<string> & ans,TrieNode * root,string temp){

            //WE REACHED A WORD INSERT IT BUT THERE CAN BE MORE 
            if(root->isTerminal){

                ans.push_back(temp);

            }

            //OKAY THIS CHARACTER IS INSERTED NOW CHECK AND CALL FOR ALL POSSIBLE BRANCHES
            for(int i = 0;i<26;i++){

                //BRACNCH PRESENT
                if(root->child[i]){

                    //PUSH ITS CHILD VALUE
                    temp.push_back(root->child[i]->data);

                    //CALL FOR THAT CHILD
                    print_suggest(ans, root->child[i], temp);

                    //TEMP KO CLEAN KARENGE FOR NEXT CALL
                    temp.pop_back();

                }

            }

        }

    //DRIVER FUNCTIONS
    public:

        //DRIVER FUNCTION FOR THE INSERTION
        void insert(string s){
            in(root, s);
        }

        //DRIVER FUNCTION FOR GETTING THE SUGGESTIONS
        void get_suggestion(vector<vector<string>> & ans,string prefix){

            //TEMP ME PREFIX KA SUBSTR STORE HOTA JAYEGA
            string temp="";

            //TAKI ASLI ROOT NA CHANGE HO
            TrieNode * ptr = root;

            //TRAVERSE THROUGH THE PREFIX
            for(auto i : prefix){

                //DALDO CHARACTER INTO TEMP
                temp.push_back(i);

                //CHECK KARO YO WALA CHARACTER KA CHILD HAIN KI NAHI
                if (root->child[i - 'a']) {

                    //HAIN 
                    vector<string> suggest;

                    //TO US NODE SE POSSIBLE JITNE WORDS HAIN SAB NIKALO
                    print_suggest(suggest, root->child[i - 'a'],temp);

                    //YE ISKE KE LIYE SUGGESTION HAIN
                    ans.push_back(suggest);

                    //ROOT KO CHNAGE KARO
                    root = root->child[i-'a'];

                }
                else{

                    //NAHI HAIN TO NO SUGGESTIONS BREAK
                    break;
                }

            }

        }

};







vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //CREATING A NEW TRIE
    Trie * newTrie = new Trie;

    //INSERTION IN A NEW TRIE
    for(auto i : contactList){
        newTrie->insert(i);
    }

    // CALLING THE MAIN REQUIRED FUNCTION 
    vector<vector<string>> ans;
    newTrie->get_suggestion(ans,queryStr);

    // RETURNNING ANS 
    return ans;
    
}
