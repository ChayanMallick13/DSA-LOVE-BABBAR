/*
  QUESTION LINK :- https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0&leftPanelTabValue=SUBMISSION
*/

/**************************    APPROACH -->   1 BRUTE FORCE      ******************************************************************/

#include<bits/stdc++.h>

int getKthLargest(vector<int> &arr, int k)
{

	//Approach 1 not optimised

	// SPACE TO STORE THE SUM OF POSSIBLE SUBARRAYS
	vector<int> ans;

	// SIZE OF THE ARRAY
	int n = arr.size();

	//TO FIND ALL THE SUBARRAYS
	for(int i = 0;i<n;i++){

		int sum = 0;

		for(int j = i;j<n;j++){

			sum+=arr[j];

			//ONE POSSIBLE SUBARRAY SUM SO PUSH THIS INTO THE ANSWER ARRAY
			ans.push_back(sum);

		}

	}


	//SORT THE ARRAY CONTAINING ALL THE POSSIBLE SUBARRRAY SUMS
	sort(ans.begin(),ans.end());

	// RETURN THE KTH ELEMENT FROM THE END 
	return ans[ans.size() - k];
	
}








/**********************************    APPROACH --->  2 OPTIMISED SOLUTION       **********************************************/


#include<bits/stdc++.h>



int getKthLargest(vector<int> &arr, int k)
{

	//INITIALISE THE MIN HEAP FOR GETTING THE 
	priority_queue<int,vector<int>,greater<int>> pq;

	// TAKE OUT THE SIZE OF THE ARRAY
	int n = arr.size();

	//FIND OUT ALL THE SUBARRAYS POSSIBLE
	for(int i = 0;i<n;i++){

		int sum = 0;

		for(int j = i;j<n;j++){

			sum += arr[j];

			//IF HEAP IS NOT HAVING K ELEMENTS PUSH IT
			if(pq.size()<k){

				pq.push(sum);

			}
			else if(pq.top()<sum){  //TOP ELEMENT IS SMALLER SO

				//POP THE TOP ELEMENT
				pq.pop();

				//PUSH THE NOW GREATER ELEMENT
				pq.push(sum);

			}

		}

	}

	//THE TOP ELEMENT OF THE MIN HEAP IS THE KTH LARGEST
	return pq.top();
	
}
