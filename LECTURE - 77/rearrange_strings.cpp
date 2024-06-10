/*

      Question links : -  https://www.naukri.com/code360/problems/rearrange-string_982765?leftPanelTab=0&leftPanelTabValue=SOLUTION

*/



#include <bits/stdc++.h> 

///my own defined data
class info{

	public:

	//store the character
	char data;

	//store the frequency
	int freq;

	//constructor to initialise the data 
	info(char a,int b) : data(a),freq(b){}

};

//comparator for the info data structure for max heap
class func{

	public:

	bool operator()(info * a,info * b){

		return a->freq < b->freq;

	}

};

//main driver function
string reArrangeString(string &s)
{

	//initialise the max heap
	priority_queue<info *,vector<info *>,func> q;

	//just to get characters freq in o(n)
	unordered_map<char,int> m;

	//store the characters freq
	for(auto i : s){

		m[i]++;
		
	}

	//put charcters and freq in pair for in info data structure
	for(auto i : m){

		q.push(new info(i.first,i.second));

	}

	//to track the last entered char
	char now = '1';

	//to store the ans
	string  ans = "";

	//do this while until only one character reapting remains or all are placed
	while(q.size()>0 && !(q.size()==1&&q.top()->data == now)){

		//to store the element which is same as previous and needs to pop
		vector<info *> pushing;

		//do popping and storing
		while(q.top()->data == now){

			pushing.push_back(q.top());

			q.pop();

		}

		//if all were same not possible to make that
		if(q.empty()){
			return "not possible";
		}
		else{ 

			//take out the top element
			info * temp = q.top();
			q.pop();

			//put this in ans
			ans.push_back(temp->data);

			//update last entered data
			now = temp->data;

			//ek dal diya to freq kam hoga
			temp->freq--;

			//isko bhi wapas dalna hain na
			pushing.push_back(temp);

			//jisko faltu nikale usko wapas daldo agar yo bacha hain to
			for(auto i : pushing){

				//bacha hain to
				if(i->freq){	

					q.push(i);

				}

			}

		}

	}

	//agar ek element reh gaya and usko nahi place kar payenge
	if((q.size()==1&&q.top()->data == now)){
		return "not possible";
	}

	//nahito ans ban gaya
	return ans;
	
}
