/*

https://www.naukri.com/code360/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

*/



vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {

    //FOR STORING THE NEIGBOURS OF A NODE
    vector<int> vec[n];

    //STORE THE NEIGHBOUR OF NODE IN ITS INDEX 
    for(int i = 0;i<m;i++){

        int u = edges[i][0];
        int v = edges[i][1];

        //UNDIRECTED SO DO BOTH
        vec[u].push_back(v);
        vec[v].push_back(u);

    }

    vector<vector<int>> ans(n);

    //FINALLY INSERT INTO ANS
    for(int i = 0;i<n;i++){

        ans[i].push_back(i);

        for(int j = 0;j<vec[i].size();j++){
            ans[i].push_back(vec[i][j]);
        }

    }
    
    return ans;
}
