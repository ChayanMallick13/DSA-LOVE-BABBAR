/*

https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0

*/






//     BFS HAMESHA SE SHORTEST PATH SE JATA HAIN


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	//VISITED WALA ARRAY
	vector<bool> visited(n+1,0);

	//PARENT STORE KARNE KE LIYE
	vector<int> parent(n+1,-1);

	//ADJ LIST IN MAKING
	vector<int> adj[n+1];
	for(int i = 0;i<m;i++){
		int a = edges[i].first;
		int b = edges[i].second;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	//BFS KA USE AND PARENT TRACKING SATH ME
	queue<int> q;
	q.push(s);
	visited[s]=true;

	while(!q.empty()){

		int front = q.front();
		q.pop();

		for(auto i : adj[front]){
			if(!visited[i]){
				q.push(i);
				parent[i]=front;
				visited[i]=true;
			}
		}
	}

	//ANSWER RETURN HOGA
	vector<int> ans;
	int path = t;

	//BACKTRACK KARTE RAHO PARENT KA USE KARKE
	while(path!=-1){
		ans.push_back(path);
		path = parent[path];
	}

	//ULTA SAHI ANS HOGA
	reverse(ans.begin(),ans.end());

	//RETURN ANS
	return ans;

}
