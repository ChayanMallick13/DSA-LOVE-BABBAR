/*

    question link :-    https://www.naukri.com/code360/problems/median-in-a-stream_975268?leftPanelTab=0&leftPanelTabValue=PROBLEM

*/


#include<bits/stdc++.h>

//main function to take out the median till now
void give_median(int element,priority_queue<int> & maxheap,
priority_queue<int,vector<int>,greater<int>> & minheap,int & median){


	//get the size of the min heap
	int minheapsize = minheap.size();

	//max heap ka size nikalo
	int maxheapsize = maxheap.size();

	//check ek tarah se indicator hain
	int check = minheapsize-maxheapsize;

	//cases for different values of 
	switch(check){

		//			 	  Median
		//	 (previous median ye stream se ane se pehle)
		//				/		\
		//            /			  \
		//			/     			\
		//		 left(maxheap) 	  right(minheap)


		//maxheap n-1   and    minheap n
		case 1:

			// max heap me dalna hoag phir
			if(median > element){

				//max heap ka size n hoga to dal sakte hain
				maxheap.push(element);

			}
			else{  //min heap me dalna hain

				//but min heap ka n+1 size hoga not possible 

				//pehle ek element min se uthake max me dal do
				maxheap.push(minheap.top());

				//min se yo element hata do
				//min -> n-1 and max -> nikalo
				minheap.pop();

				//ab dal sakte hian
				minheap.push(element);

			}

			//min and max me equal elements hain n and n so median avg hoga 
			median = (maxheap.top()+minheap.top())/2;

			break;

		//min -> n-1 and max -> n
		case -1:

			//min heap me dalna hain
			if(element > median){

				//possible hain daldo
				minheap.push(element);

			}
			else{ //max heap me dalna hain

				//but directly dale to n+1 size ho jayega max heap ka

				//pehle maxheap se element nikalke min me daldo
				minheap.push(maxheap.top());

				//element hata do max se
				// max -> n-1 and min -> n
				maxheap.pop();

				//ab dal sakte hain dal do
				maxheap.push(element);

			}

			//even case hain so avg nikalna padega
			median = (maxheap.top()+minheap.top())/2;

			break;

		//agar dono same size hain
		// min -> n and max -> n
		case 0:

			//base case for first insertion
			if(median == INT_MIN){

				//just daldo koi bhi heap part me ek hi ele hain na
				maxheap.push(element);

				//ab ek element hain to ohi hi median hain
				median = element;

			}
			else{	//ab baki cases

				//min me dalna hain
				if(element > median){

					//daldo isime
					minheap.push(element);

					//max n and min n+1
					// so min ka top ans hain
					median = minheap.top();

				}  //max me dalna hain
				else{

					//max me daldo
					maxheap.push(element);

					//max -> n+1 min-> n
					//so max ka top ans hain
					median = maxheap.top();

				}

			}

			break;

	}
	
}

vector<int> findMedian(vector<int> &arr, int n){
	
	//vector to store the median of incomming stream
	vector<int> ans;

	// creating two heaps min and max to segrate the incomming elemnts 
	// to create two sorted parts like structure

	//max heap
	priority_queue<int> maxheap;

	//min heap
	priority_queue<int,vector<int>,greater<int>> minheap;

	//we want to put the first element into the min part so median start with min
	int median = INT_MIN;

	//for each incomming stream get the median
	for(auto i : arr){

		give_median(i,maxheap,minheap,median);

		//median jo mila wo answer me dal lo
		ans.push_back(median);

	}


	//return ans
	return ans;
}
