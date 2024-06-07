#include<iostream>
using namespace std;

class heap{
    public:
        int * arr;
        int size;
        int maxi;

    public:
        heap(int size){
            this->size = 0;
            arr = new int[size];
            maxi = size;
        }

        void push(int x){
            if(size == maxi){
                // cout<<"The heap is full"<<endl;
                return;
            }
            size ++;
            arr[size]=x;
            int index = size;
            while(index>1){
                int parent = index/2;
                if(arr[parent]<arr[index]){
                    swap(arr[parent],arr[index]);
                    index = parent;
                }
                else{
                    return;
                }
            }
        }

        void pop(){
            if(size == 0){
                return;
            }
            arr[1]=arr[size];
            size--;
            int index = 1;
            while(index<=size){
                int left = 2*index;
                int right = 2*index +1;
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


void heapify(int * arr,int size,int index){
    if(index > index){
        return;
    }
    int check = index;
    int left = 2*index;
    int right = 2 * index +1;

    if(left<= size && arr[left]>arr[index] && arr[left]>arr[right]){
        swap(arr[index],arr[left]);
        index = left;
    }
    else if(right <= size && arr[right]>arr[index]){
        swap(arr[index],arr[right]);
        index = right;
    }

    if(index != check){
        heapify(arr,size,index);
    }

    return;
}

void make_heap(int * arr,int size){
    for(int i = size/2;i>0;i--){
        heapify(arr,size,i);
    }
}