/*

https://www.naukri.com/code360/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

*/

  //USING BFS

#include <bits/stdc++.h> 

//TOPOLOGICAL SORT USING THE DFS MODIFICATION
void bfs(vector<int> adj[],vector<int> &ans,vector<int> &indegree,int v){


    //JISKA INDEGREE HAIN 0 HAIN DALDO
    queue<int> q;
    for(int i = 0;i<v;i++){

      if (indegree[i] == 0) {
        q.push(i);
      }

    }

    //JAB TAK QUEUE EMPTY NAHI HAIN 
    while(!q.empty()){

        //FRONT NODE NIKALO
        int front_node = q.front();
        q.pop();

        //ANSWER ME DALDO
        ans.push_back(front_node);

        //ISKE NEIGHBOURS KE INDEGREE EK KAM KARO 
        for(auto i : adj[front_node]){

            indegree[i]--;

            //AGAR ISKE INDEGREE 0 HO GAYA TO DALDO
            if(indegree[i]==0){
                q.push(i);
            }

        }

    }

}

//DRIVER FUNCTION
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    //TOPOLOGICAL SORT USING DFS

    //ISME ANSWER JAYEGA OR KAHA SE DALNA HAIN
    vector<int> ans;

    //CREATE THE ADJ LIST
    vector<int> adj[v];

    //IN DEGREE KA TRACK RAKHO
    vector<int> indegree(v,0);

    //ADJ LIST IN MAKING
    for(int i = 0;i<e;i++){

        adj[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;

    }

    //DO THE KAHNS ALGO
    bfs(adj,ans,indegree,v);

    //RETURN KARDO ANSWER
    return ans;

}
