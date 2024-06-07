#include<iostream>
#include<queue>
using namespace std;




int main()
{

    // STL FUNCTIONS EXPERIMENT FOR MAX HEAP
    priority_queue<int> maxheap;
    maxheap.push(8);
    maxheap.push(98);
    maxheap.push(54);
    maxheap.push(5);
    maxheap.push(99);
    maxheap.push(43);

    cout<<"The size of the queue is : "<<maxheap.size()<<endl;  
    while(!maxheap.empty()){
        cout<<"Max element is "<<maxheap.top()<<endl;
        maxheap.pop();
    }

    cout<<"\n\n"<<endl;


    //  STL FUNCTIONS FOR MIN HEAP
    priority_queue<int,vector<int>,greater<int>> minheap;

    minheap.push(8);
    minheap.push(98);
    minheap.push(54);
    minheap.push(5);
    minheap.push(99);
    minheap.push(43);

    cout<<"The size of the queue is : "<<minheap.size()<<endl;  
    while(!minheap.empty()){
        cout<<"Min element is "<<minheap.top()<<endl;
        minheap.pop();
    }

    return 0;
}