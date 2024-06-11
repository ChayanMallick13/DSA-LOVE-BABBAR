/*

  question link :- https://www.naukri.com/code360/problems/maximum-frequency-number_920319?leftPanelTab=0&leftPanelTabValue=PROBLEM

*/


#include<map>

int maximumFrequency(vector<int> &arr, int n)
{
    //create a map
    unordered_map<int,int> m;

    //to store the maxfreq of the element
    int maxfreq = -1;

    //push the elemnets in the map with thier freq inc evry time they appear
    for(auto i :arr){

        m[i]++;

        //update the max freq every time we insert an elemnt
        maxfreq = max(maxfreq,m[i]);

    }

    //check for which element we have got the max freq from left given in question
    for(auto i : arr){

        if(m[i]==maxfreq){
            
            //isi ki freq max hain
            return i;
        
        }

    }

    //not possible 
    return -1;
    
}
