/*

    QUESTION LINK :-    https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

*/



/**************************************************************  USING BFS   *******************************************************************/


#include <bits/stdc++.h>

//YE BFS MODIFICATION HAIN
bool have_cycle(unordered_map<int,int> & parent,unordered_map<int,bool>& visited,
                                                                unordered_map<int,list<int>> & adj,int curr_node){
    
        //QUEUE FOR BFS
        queue<int> q;

        //KHUD SE PEHLA ELEMENT DALDO
        q.push(curr_node);

        //VISITED BHI KARDO
        visited[curr_node]=1;

        //ISKA KOI PARENT NAHI HOGA TO -1 PARENT KARDO
        parent[curr_node]=-1;

        //JAB TAK EMPTY NAHI BFS KARO
        while(!q.empty()){

            //YE HOGA CURR NODE JISPE HAIN ABHI USKO NIKALO
            curr_node = q.front();
            q.pop();

            //USKE NEIGHBOURS ADJ LIST SE TACKLE KARO
            for(auto i : adj[curr_node]){

                //AGAR YO NEIGHBOUR VISITED NAHI HAIN TO SIMPLY QUEUE ME DAL DO
                if(!visited[i]){
                    parent[i]=curr_node;
                    visited[i]=1;
                    q.push(i);
                }

                //AGAR YO PEHLE SE VISITED HAIN AND IS CURRNODE KA PARENT HAIN TO MILGAYA CYCLE
                else if(visited[i]&&parent[curr_node]!=i){
                    return true;
                }

            }

        }

        //PURA TRAVERSE HOGAYA NAHI MILA LOOP SO RETURN FLASE
        return false;

    }


//DRIVER CODE
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    
    //VISITED MAP
    unordered_map<int,bool> visited;

    //PARENT_MAP
    unordered_map<int,int> parent;

    //ADJACENCY MATRIX
    unordered_map<int,list<int>> adj;

    //PREPARE THE ADJ LIST
    for(int i = 0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    //TO RETURN THE ANSWER
    string ans = "No";
    
    //DISCONNECTED POSSIBLE SO CALL CHECK FOR EVERY NODE
    for(int i = 0;i<n;i++){

        //IF NOT VISITED SO THEN START BFS FROM THAT NODE
        if(!visited[i]){
            if(have_cycle(parent,visited,adj,i)){
                ans = "Yes";
            }
        }

    }

    //RETURN ANS
    return ans;

}




/***********************************************************************************************************************************************/









/**************************************************************  USING DFS   *******************************************************************/


#include <bits/stdc++.h>

//YE DFS MODIFICATION HAIN
bool have_cycle(int parent,unordered_map<int,bool>& visited,
                                unordered_map<int,list<int>> & adj,int curr_node){

    //JIS NODE PE AAGAY US NODE KO VISITED MARK KARDO
    visited[curr_node]=true;

    //SARE NEIGHBOURS KE LIYE CHECK KARO
    for(auto i : adj[curr_node]){

        //GARA VISITED NAHI HAIN TO USKE LIYE CALL KARO AND CURR NODE USKA PARENT
        if(!visited[i]){

            //AGAR IS BRACH SE ANS AYA CYCLE HAIN TO RETURN KARDENA NAHITO BAKI 
            //BRACH KE LIYE CHECK KARO
            bool cycle = have_cycle(curr_node,visited,adj,i);
            if(cycle)
                return true;
            
        }

        //VISITED HAIN AND PARENT NAHI HAIN TO MIL GAYA CYCLE TRUE RETURN KARDENA
        else if(visited[i]&&i!=parent){
            return true;
        }

    }

    //NAHI KISIBHI BRANCH ME CCYCLE NAHI HAIN
    return false;

}


//DRIVER CODE
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    
    //VISITED MAP
    unordered_map<int,bool> visited;

    //ADJACENCY MATRIX
    unordered_map<int,list<int>> adj;

    //PREPARE THE ADJ LIST
    for(int i = 0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    
    //DISCONNECTED POSSIBLE SO CALL CHECK FOR EVERY NODE
    for(int i = 0;i<n;i++){

        //IF NOT VISITED SO THEN START BFS FROM THAT NODE
        if(!visited[i]){
            if(have_cycle(-1,visited,adj,i)){
                return "Yes";
            }
        }

    }

    //RETURN ANS
    return "No";

}




/***********************************************************************************************************************************************/
