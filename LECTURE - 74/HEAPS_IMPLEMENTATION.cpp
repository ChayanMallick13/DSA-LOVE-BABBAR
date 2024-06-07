/* ******************  HEAP IMPLEMENTATION CODE IN ARRAY    ********************************/

#include<iostream>
using namespace std;


//HEAP CLASS MAX HEAP
class heap{
    public:

        //ARRAY TO STORE THE DATA
        int * arr;

        //CURRENT SIZE OF THE HEAP
        int size;

        //MAXIMUM SIZE OF THE HEAP
        int maxi;

    public:

        //CONSTRICTOR  
        heap(int size){

            //SET SIZE TO 0
            this->size = 0;
            
            //TO ALLOCATE THE SPACE OF THE ARRAY DYNAMICALLY
            arr = new int[size];

            //AND SET MAX SIZE
            maxi = size;

        }


        //CODE TO INSERT A ELEMENT INTO THE HEAP
        void push(int x){

            //CHECK FOR FULL CONDITION
            if(size == maxi){
                return;
            }

            //INCRAESE SIZE OF THE HEAP
            size ++;

            //PUT THE ELEMENT AT LAST
            arr[size]=x;

            //STORE THE INDEX AT WHICH THE ELEMENT IS BEING PUT
            int index = size;

            //TAKE THE ELEMENT TO ITS CORRECT POSITION IN THE HEAP
            while(index>1){

                //FIND PARENT
                int parent = index/2;

                //IF PARENT IS SMALLER THAN CHILD SWAP
                if(arr[parent]<arr[index]){

                    swap(arr[parent],arr[index]);

                    //AGAIN CHECK NOW FOR PARENT INDEX
                    index = parent;

                }
                else{
                    return;     //ELSE IT IS MAX HEAP SO RETURN
                }

            }

        }

        void pop(){

            //CHECK FOR EMPTY CONDITION
            if(size == 0){
                return;
            }

            //PUT THE LAST ELEMENT IN THE FIRST PLACE
            arr[1]=arr[size];

            //DECREASE THE SIZE
            size--;

            //PUT THE FIRST ELEMENT IN ITS CORRECT POSITION IN THE MAX HEAP
            int index = 1;

            while(index<=size){

                //FIND LEFT
                int left = 2*index;

                //FIND RIGHT
                int right = 2*index +1;

                //CHECK CONDITIONS
                if(left<=size && arr[left]>arr[index] && arr[left]>arr[right]){

                    swap(arr[left],arr[index]);

                    index = left;

                }
                else if(right <= size && arr[right]>arr[index]){

                    swap(arr[index],arr[right]);

                    index = right;

                }
                else{

                    return;

                }

            }

        }
        void print(){

            for(int i = 1;i<=size;i++){
                cout<<arr[i]<<"   ";
            }

            cout<<"\n\n";

        }
};


//FUNCTION TO TAKE A ELEMNT TO ITS CORRECT POSITION
void heapify(int * arr,int size,int index){

    //FIND RIGHT AND LEFT
    int check = index;
    int left = 2*index;
    int right = 2 * index +1;


    //AGAIN CHECK LEFT AND RIGHT CHILDRENS
    if(left<= size  && arr[left]>arr[index] && (right >size ||arr[left]>arr[right])){
        swap(arr[index],arr[left]);
        index = left;
    }
    else if(right <= size && arr[right]>arr[index]){
        swap(arr[index],arr[right]);
        index = right;
    }

    //IF CHANGE IS MADE CHECK FOR THE CORRECT POSTION FOR THE SWAPPED ELEMENT
    if(index != check){
        heapify(arr,size,index);
    }

    //NO CHANGE THEN IT IS GOOD MAX HEAP RETURN
    return;

}

//FUNCTION TO CONVERT A ARRAY INTO A HEAP
void make_heap(int * arr,int size){

    //CALL HEAPIFY FOR ALL NODES EXCEPT NODE N/2 +1 -> N
    for(int i = size/2;i>0;i--){
        heapify(arr,size,i);
    }

}


void print_array(int * arr,int size){

    for(int i = 1;i<=size;i++){
        cout<<arr[i]<<"   ";
    }
    cout<<"\n\n\n";

}


//HEAP SORT 
void heap_sort(int * arr,int size){

    //FIRST MAKE THE ARRAY HEAP
    make_heap(arr,size);

    //NOW 
    while(size>1){

        //SWAP THE FIRST ELEMENT WITH LAST
        swap(arr[size],arr[1]);

        //REDUCE SIZE
        size--;

        //TAKE THE SWAPPED ELEMENT TO ITS CORRECT POSITION
        heapify(arr,size,1);

    }
}





int main(){

    
    heap h(100);
    h.push(50);
    h.push(55);
    h.push(53);
    h.push(52);
    h.push(54);
    h.print();
    cout<<"After deletion"<<endl;
    h.pop();
    h.print(); 

    int arr[] = {-1,54,53,55,52,50};
    int size = 5;
    heap_sort(arr,size);
    print_array(arr,size);

    return 0;
}
