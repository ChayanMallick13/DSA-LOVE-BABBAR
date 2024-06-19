/*

      https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/0

*/


class Solution {
    private:
    void dfs(vector<bool> &visited,stack<int> &topo,
    int node,vector<pair<int,int>> adj[]){
        visited[node]=true;
        
        for(auto i : adj[node]){
            if(!visited[i.first]){
                dfs(visited,topo,i.first,adj);
            }
        }
        topo.push(node);
    }
    public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
       
       //CREATING THE ADJACENCY LIST 
       //  (CONATAINS NEIGHBOUR NODE AND WEIGHT ON THE EDGE)
       vector<pair<int,int>> adj[N];
       for(auto i : edges){
           adj[i[0]].push_back({i[1],i[2]});
       }
       
       //CREATING THE TOPOLOGICAL SORT USING DFS CALL
       stack<int> topo;
       vector<bool> visited(N,false);
       for(int i = 0;i<N;i++){
           if(!visited[i]){
               dfs(visited,topo,i,adj);
           }
       }
       
       //ANS WALA ARRAY
       vector<int> ans(N,INT_MAX);
       
       //SRC NODE KA DIS 0 MARK KARO
       ans[0]=0;
       
       //TOPO SORT KA ISTEMAL KARO
       while(!topo.empty()){
           
           //TOP NIKALO
           int top = topo.top();
           topo.pop();
           
           //AGAR YE SRC KE BAD HAIN TO 
           if(ans[top]!=INT_MAX){
               
               //SRC SE YAHA TAK KA SHRT DIS
               int node_dis = ans[top];
               
               //ISKE NEIGBOURS NODES
               for(auto i : adj[top]){
                   
                   //NEIGHBOUR
                   int adj_node = i.first;
                   
                   //CHECK KARO SRC SE NEIGH NODE VIA THIS NODE IS SORTEST OR NOT
                   ans[adj_node]=min(ans[adj_node],node_dis+i.second);
                   
               }
       
           }
           else{
               
               //AGAR YE SRC SE PEHLE HAIN TO -1 SET KARO NAHI JA SAKTE YAHA
               ans[top]=-1;
               
           }
       }
       
       //RETURN KARDO ANSWER
       return ans;
    } 
};
