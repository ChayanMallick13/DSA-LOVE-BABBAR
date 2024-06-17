/*

      https://www.naukri.com/code360/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

*/



//USING DFS 


#include <bits/stdc++.h> 

//TOPOLOGICAL SORT USING THE DFS MODIFICATION
void dfs(vector<int> adj[],vector<bool> &visited,vector<int> &ans,int &ans_ind,int node){

    //YAHA AGAY TO VISIT KARO IS NODE KO
    visited[node]=1;

    //ISKE NEIGHBOURS CHALE JAYO AGAR VISITED NAHI HAIN TO
    for(auto i : adj[node]){

        if(!visited[i]){
            dfs(adj, visited, ans, ans_ind, i);
        }

    }

    //YAHA SE KAHI NAHI JA SAKTE HAIN TO ISKO LAST ME DALDO OR IND KO NEXT ME KARDO
    ans[ans_ind]=node;
    ans_ind--;

}

//DRIVER FUNCTION
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    //TOPOLOGICAL SORT USING DFS

    //ISME ANSWER JAYEGA OR KAHA SE DALNA HAIN
    vector<int> ans(v);
    int ans_ind = v-1;

    //CREATE THE ADJ LIST
    vector<int> adj[v];

    for(int i = 0;i<e;i++){

        adj[edges[i][0]].push_back(edges[i][1]);

    }

    //CREATE A VISITED LIST
    vector<bool> visited(v,0);

    //DFS CALL SO THAT ISOLATED PART OR NOT VISITED PART IS ALSO VISITED
    for(int i = 0;i<v;i++){

        //AGAR YO VISITED NAHI HAIN TO START KARDO PHIR
        if(!visited[i]){
            dfs(adj,visited,ans,ans_ind,0);
        }

    }

    //RETURN KARDO ANSWER
    return ans;

}
