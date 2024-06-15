/*

  https://www.naukri.com/code360/problems/dfs-traversal_630462?leftPanelTab=0&leftPanelTabValue=PROBLEM

*/





//MAIN DFS FUNCTION
void DFS(vector<int>  adj[],int node,unordered_map<int,bool> & visited,vector<int> & ans){

    //NODE PAR AGAY TO VISIT KARLO
    visited[node]=1;
    ans.push_back(node);

    //ISKE NEIGHBOURS ME AGAR KOI UNVISITED HAIN TO USKE LIYE CALL KARO
    for(int i = 0;i<adj[node].size();i++){

        int new_node = adj[node][i];

        //CALL FOR NEW UNVISITED NODE
        if(!visited[new_node]){
            DFS(adj, new_node, visited, ans);
        }

    }

}

//DRIVER FUNCTION
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{

    //FOR CREATING A ADJACENCY LIST
    vector<int> adj[V];
    for(int i = 0;i<E;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    // TO STORE THE ANSWER
    vector<vector<int>> ans;

    //FOR MARKING VISISTED
    unordered_map<int,bool> m;

    //CHECKING KI KOI NODE UNVISISTED NAH RAH JAYE MATLAB KI KOI COMPONENT UNVISITED NA HOJAYE
    for(int i = 0;i<V;i++){

        //VISITED NAHI HANI TO TRAVERSE KARO
        if(!m[i]){
            vector<int> temp;
            DFS(adj,i,m,temp);
            ans.push_back(temp);
        }     

    }

    //RETURN THE ANSWER
    return ans;

}








// ANOTHER APPROACH FOR ADJACENCY MATRIX


//MAIN DFS FUNCTION
void DFS(unordered_map<int,list<int>>& adj,int node,unordered_map<int,bool> & visited,vector<int> & ans){

    //NODE PAR AGAY TO VISIT KARLO
    visited[node]=1;
    ans.push_back(node);

    //ISKE NEIGHBOURS ME AGAR KOI UNVISITED HAIN TO USKE LIYE CALL KARO
    for(auto i : adj[node]){

        int new_node = i;

        //CALL FOR NEW UNVISITED NODE
        if(!visited[new_node]){
            DFS(adj, new_node, visited, ans);
        }

    }

}

//DRIVER FUNCTION
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{

    //FOR CREATING A ADJACENCY LIST
    unordered_map<int,list<int>> adj;
    for(int i = 0;i<E;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    // TO STORE THE ANSWER
    vector<vector<int>> ans;

    //FOR MARKING VISISTED
    unordered_map<int,bool> m;

    //CHECKING KI KOI NODE UNVISISTED NAH RAH JAYE MATLAB KI KOI COMPONENT UNVISITED NA HOJAYE
    for(int i = 0;i<V;i++){

        //VISITED NAHI HANI TO TRAVERSE KARO
        if(!m[i]){
            vector<int> temp;
            DFS(adj,i,m,temp);
            ans.push_back(temp);
        }     

    }

    //RETURN THE ANSWER
    return ans;

}
