/*

Question Link :- https://www.naukri.com/code360/problems/merge-k-sorted-lists_992772?leftPanelTab=0&leftPanelTabValue=SUBMISSION

*/






//using Node * to create a min heap so default compare func
class func{

    public:

    //to check how to compare a and b
    bool operator()(Node * a,Node * b){

        return a->data > b->data;

    }

};

//lets begin
Node* mergeKLists(vector<Node*> &listArray){

    //a dum  head to store the ans my making tail connections
    Node * dum = new Node(-1);
    Node * tail = dum;

    //initialise a min heap
    priority_queue<Node *,vector<Node *>,func> minheap;

    //put all lists first elements address
    for(int i = 0;i<listArray.size();i++){

        minheap.push(listArray[i]);

    }

    //perform untill each element is push into heap and taken out
    while(!minheap.empty()){

        //pop the smallest element from the heap thats min heap for you
        Node * temp = minheap.top();
        minheap.pop();

        //add this to next of tail making the ans and move to new tail now
        tail->next = temp;
        tail=tail->next;

        //check if more elements of that list are present if so then push next to heap
        if(temp->next)
            minheap.push(temp->next);

    }

    //make the tail ka next NULL
    tail->next = NULL;

    //return the ans list
    return dum->next;
    
}
