/*

    Question link :-   https://www.naukri.com/code360/problems/smallest-range-from-k-sorted-list_1069356?leftPanelTab=0&leftPanelTabValue=PROBLEM

*/

#include<bits/stdc++.h>

//for storing the info of the element
class info{
    public:

    //its data
    int data;

    //its row
    int i;

    //its col
    int j;

    //constructor to set data
    info(int a,int b,int c) : data(a),i(b),j(c){}

};


//comparator for info
class comp{
    public:
    bool operator()(info * a,info * b){
        return a->data > b->data;
    }
};


//main driver func
int kSorted(vector<vector<int>> &a, int k, int n) {
    
    //in range only possible to maximise the minimum now

    //we use a min heap 
    priority_queue<info *,vector<info *>,comp> pq;

    //we define max and mini
    int mini ,maxi;
    mini = INT_MAX;
    maxi = INT_MIN;

    //put every first element of the arrays in the min heap
    for(int i = 0;i<k;i++){

        //keep a track of mini
        mini = min(mini,a[i][0]);

        //keep a track of max
        maxi = max(maxi,a[i][0]);

        //ush into min heap
        pq.push(new info(a[i][0],i,0));

    }

    //to get the minimum possible answer
    int ans = INT_MAX;

    //do while it is not empty
    while(!pq.empty()){

        //ans update karo agar ye interval smallest hain to previous wale se
        ans = min(ans,maxi-mini+1);

        //naya wala min banake ka taiyari
        info * temp = pq.top();
        pq.pop();

        //agar iska next element hain to usko dalo taki hum
        // min ko maximise kar paye 
        if (temp->j + 1 < n) {
          
          //maxi ka track bhi rakho
          maxi = max(maxi, a[temp->i][temp->j + 1]);

          //naya elemnt daldo
          pq.push(new info(a[temp->i][temp->j+1],temp->i,temp->j+1));

          //naya mini top pe hoga
          mini = pq.top()->data;

        }
        else{

            //isse bada min lenge to temp wala array ka elemnt nahi ayega 
            //to or maximise nahi karpayenge isko
            return ans;

        }

    }

    //answer agaya hoga
    return ans;
    
}
