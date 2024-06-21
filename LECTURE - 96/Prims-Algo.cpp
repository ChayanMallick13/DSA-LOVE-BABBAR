
//   https://www.naukri.com/code360/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // make the adjacency list
    vector<pair<int,int>> adj[n+1];
    for(auto i : g){

        int u = i.first.first;
        int v = i.first.second;
        int w = i.second;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    //key
    vector<int> key(n+1,INT_MAX);

    //mst
    vector<bool> mst(n+1,false);

    //parent
    vector<int> parent(n+1,-1);

    //manually set key of src 0
    int src = 1;
    key[src]=0;

    for(int i = 1;i<=n;i++){

        int min_node = -1;
        int min_val = INT_MAX;
        
        //find the min node in the key
        for(int i = 1;i<=n;i++){
            if((!mst[i]) && key[i]<min_val){
                min_node = i;
                min_val = key[i];
            }
        }

        //mark mst of min as true
        mst[min_node]=true;

        //check for its adj
        for(auto i : adj[min_node]){
            if((!mst[i.first])&&i.second<key[i.first]){
                key[i.first]=i.second;
                parent[i.first]=min_node;
            }
        }
    }

    //creating the answer
    vector<pair<pair<int,int>,int>> ans;
    for(int i = 2;i<=n;i++){

        //this has node with parent node with dis key value
        ans.push_back({{i, parent[i]}, key[i]});

    }

    //return ans
    return ans;
}



// heap ka use se 
#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // make the adjacency list
    vector<pair<int,int>> adj[n+1];
    for(auto i : g){

        int u = i.first.first;
        int v = i.first.second;
        int w = i.second;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    //key
    vector<int> key(n+1,INT_MAX);

    //mst
    vector<bool> mst(n+1,false);

    //parent
    vector<int> parent(n+1,-1);

    //manually set key of src 0
    int src = 1;
    key[src]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
    min_heap.push({0,src});

    for(int i = 1;i<=n;i++){

        while(mst[min_heap.top().second]){
            min_heap.pop();
        }
        int min_node = min_heap.top().second;
        min_heap.pop();
        int min_val = INT_MAX;
        

        //mark mst of min as true
        mst[min_node]=true;

        //check for its adj
        for(auto i : adj[min_node]){
            if((!mst[i.first])&&i.second<key[i.first]){
                min_heap.push({i.second,i.first});
                key[i.first]=i.second;
                parent[i.first]=min_node;
            }
        }
    }

    //creating the answer
    vector<pair<pair<int,int>,int>> ans;
    for(int i = 2;i<=n;i++){

        //this has node with parent node with dis key value
        ans.push_back({{i, parent[i]}, key[i]});

    }

    //return ans
    return ans;
}

