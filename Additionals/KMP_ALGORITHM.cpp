
// this is the algorithm for checking b is present in a or not in O(n+m) TC
bool kmp(string & a,string & b){
        
        vector<int> lps(b.length(),0);
        
        //calculate the lps of the other
        int length = 0,i=1;
        while(i<b.length()){
            if(b[length]==b[i]){
                length++;
                lps[i++] = length;
            }
            else{
                while(length && b[length]!=b[i]){
                    length = lps[length-1];
                }
                if(length){
                    length++;
                    lps[i++] = length;
                }
                else{
                    lps[i++] = 0;
                }
            }
        }
        
        i = 0;
        int j = 0;
        while(i<a.length() && j<b.length()){
            while(a[i]==b[j]){
                i++;
                j++;
            }
            if(j>=b.length()){
                return true;
            }
            if(j==0){
                i++;
            }
            else{
                j = lps[j-1];
            }
        }
        
        return false;
    }