class Solution {
  public:
    vector<int> search(string pattern, string text) {
        // code here.
        vector<int> ans;
        int bigPrime = 10007;
        int pHash = 0;
        int tHash = 0;
        int base = 26;
        int expo = 1;
        for(int i = 1;i<pattern.length();i++){
            expo = (expo*base)%bigPrime;
        }
        for(int i = 0;i<pattern.length();i++){
            pHash = (pHash*base + pattern[i])%bigPrime;
            tHash = (tHash*base + text[i])%bigPrime;
        }
        
        int i = 0;
        int j = pattern.length()-1;
        while(j<=text.length()){
            if(pHash==tHash){
                int x = i;
                bool isAns = true;
                for(int k = 0;k<pattern.length();k++){
                    if(pattern[k]!=text[x++]){
                        isAns = false;
                        break;
                    }
                }
                if(isAns){
                    ans.push_back(i+1);
                }
            }
            j++;
            if(j<text.length()){
                tHash = (((tHash-text[i]*expo)*base) + text[j])%bigPrime;
            }
            if(tHash<0){
                tHash+=bigPrime;
            }
            i++;
        }
        return ans;
    }
};