/*

    question link ;-   https://www.naukri.com/code360/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

*/




//MAIN FUNCTION FOR BFS
void BFS(unordered_map<int,bool> & m,vector<vector<int>> & adj,int front_node,vector<int> & ans){

    //QUEUE DECLARATION
    queue<int> q;

    //CURRENT NODE KO DADO APNE SE
    q.push(front_node);

    //USKO VISITED MARK BHI KARO
    m[front_node]=1;

    //STRAT PROCESSING
    while(!q.empty()){

        //FRONT WALA VISIT HOGAYA TO USE ANS ME DALO
        front_node = q.front();
        q.pop();
        ans.push_back(front_node);

        // /USSE CONNECTED ADJACENTS KO AGAR VISITED NAHI HAIN TO DALDO
        for(auto i : adj[front_node]){

            if(!m[i]){

                //DALTE WAQT VISITED MARK KARDENA
                m[i]=1;
                q.push(i);
                
            }

        }
    }
}




//DRIVER FUNCTION
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){

    //FOR STORING THE ANSWER
    vector<int> ans;

    //VISITED WALA 
    unordered_map<int,bool> m;
    
    //DIRECTED WALA HAIN HAIN AND NO COMPONENT CONCEPT SO NO LOOP
    BFS(m,adj,0,ans);

    // RETURN THE ANS 
    return ans;

}
