//   https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1



class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string ans;
        string temp;
        for(int i = S.length()-1;i>=0;i--){
            if(S[i]=='.'){
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans+=".";
                temp = "";
            }
            else{
                temp.push_back(S[i]);
            }
        }
        if(temp!=""){
            reverse(temp.begin(),temp.end());
            ans+=temp;
        }
        return ans;
    } 
};
