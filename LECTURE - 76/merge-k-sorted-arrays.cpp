/*

      Question link :-    https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379?leftPanelTab=0&leftPanelTabValue=SUBMISSION

*/



#include <bits/stdc++.h> 

//creating my own define data type
class mydata{

    public:

    //to store the current data
    int data;

    //to store this elements row
    int i;

    //to store this elements column
    int j;

    //to store this current element vectors size
    int size;

    // constructor to set data
    mydata(int a,int b,int c,int d) : data(a) , i(b),j(c),size(d){}

};

//a default greater function to use for the user defined data case
class myfunc{

    public:

    //how to decide which a or b which is greater 
    bool operator()(mydata * a,mydata * b){

        return a->data > b->data;

    }

};

//lets start the main task
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{

    //create a min heap
    priority_queue<mydata *,vector<mydata *>,myfunc> q;

    // put every arrays first element into the min heap
    for(int i = 0;i<k;i++){

        //convert the required data and put into min heap
        q.push(new mydata(kArrays[i][0],i,0,kArrays[i].size()));

    }

    //final ans vector
    vector<int> ans;

    //do this untill all elements are once pushed into heap and taken out
    while(!q.empty()){

        //pop out the smallest element thats min heap for you
        mydata * temp = q.top();

        //now delete the top element
        q.pop();

        //put the value in ans
        ans.push_back(temp->data);

        //if next element for that vector of which this is the element push it into heap
        if(temp->j+1<temp->size)
            q.push(new mydata(kArrays[temp->i][temp->j+1],temp->i,temp->j+1,temp->size));
    
    }

    //our answer is ready
    return ans;
    
}
