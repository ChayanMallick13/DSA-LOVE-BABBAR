/*
      QUESTION LINK :- https://www.naukri.com/code360/problems/build-min-heap_1171167?leftPanelTab=0
*/


#include <bits/stdc++.h> 


//CALL THE HEAPIFY FUNCTION
void heapify(vector<int> & arr,int size,int curr){

    int check = curr;

    //LEFT CHILD INDEX
    int left = 2* curr +1;

    //RIGHT CHILD INDEX
    int right = 2*curr + 2;

    //CHECK IF THE LEFT CHILD IS SAMLLER IF SO CHECK WITH RIGHT IF SO THE SWAP PARENT AND LEFT
    if(left<size && arr[left]<arr[curr] && (right>=size || arr[right]>arr[left])){

        swap(arr[left],arr[curr]);

        curr = left;

    }  //CHECK THE SAME FOR THE RIGHT NODES
    else if(right<size && arr[right]<arr[curr]){

        swap(arr[curr],arr[right]);

        curr = right;

    }

    //IF CHANGES HAVE OCCURED THEN CALL FOR THE NEW NODE SWAPPED WITH AND HEAPIFY IT
    if(curr != check){

        heapify(arr, size, curr);

    }
    else{

        // NO CHANGE MADE SO RETURN IT IS ALREADY A GOOD HEAP
        return;

    }

}


//MAKE THE ARRAY A HEAP
void make_heap(vector<int> & arr,int size){

    // HEAPIFY ALL THE NODES FROM LAST LEAVING THE LEAF NODES N/2 TO N 
    for(int i = size/2-1;i>=0;i--){

        heapify(arr,size,i);

    }

}

//MAIN FUNCTION
vector<int> buildMinHeap(vector<int> &arr)
{
    
    // MAKE THE ARRAY A HEAP 
    make_heap(arr,arr.size());

    // RETURN THE ANS
    return arr;
}
