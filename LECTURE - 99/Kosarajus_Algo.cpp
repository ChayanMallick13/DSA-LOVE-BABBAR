/*

https://www.naukri.com/code360/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0&leftPanelTabValue=PROBLEM

*/


#include<bits/stdc++.h>
using namespace std;

// Depth First Search (DFS) function
void dfs(unordered_map<int,vector<int>> &adj, vector<bool> &visited, stack<int> &s, int node) {
    // Current node ko visited mark karte hain
    visited[node] = true;
    
    // Saare adjacent nodes par DFS lagate hain jo abhi visited nahi hain
    for(auto i : adj[node]) {
        if(!visited[i]) {
            dfs(adj, visited, s, i);
        }
    }
    
    // Saare adjacent nodes ko visit karne ke baad current node ko stack mein push karte hain
    s.push(node);
}

// Check function jo transpose graph par DFS chalata hai
void check(unordered_map<int,vector<int>> &adj, vector<bool> &visited, int node) {
    // Current node ko visited mark karte hain
    visited[node] = true;
    
    // Saare adjacent nodes par DFS lagate hain jo abhi visited nahi hain
    for(auto i : adj[node]) {
        if(!visited[i]) {
            check(adj, visited, i);
        }
    }
}

// Function to find Strongly Connected Components (SCC) using Kosaraju's Algorithm
int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
    // Adjacency list aur transpose graph banate hain
    unordered_map<int,vector<int>> adj;
    unordered_map<int,vector<int>> trans;
    for(auto i : edges) {
        adj[i[0]].push_back(i[1]);  // Original graph ke adjacency list mein edge add karte hain
        trans[i[1]].push_back(i[0]); // Transpose graph ke adjacency list mein edge add karte hain
    }
    
    stack<int> s; // Stack to store nodes in order of completion time
    vector<bool> visited(v, false); // Visited array to keep track of visited nodes
    
    // Pehle DFS chalate hain sabhi nodes par original graph par to fill the stack
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            dfs(adj, visited, s, i);
        }
    }
    
    // Visited array ko reset karte hain for second pass
    for(int i = 0; i < v; i++) {
        visited[i] = false;
    }
    
    int ans = 0; // SCC count
    
    // Stack ke nodes ko pop karte hain aur transpose graph par DFS chalate hain
    while(!s.empty()) {
        int node = s.top();
        s.pop();
        if(!visited[node]) {
            ans++; // Naya SCC milta hai
            check(trans, visited, node);
        }
    }
    
    return ans; // Total SCC count return karte hain
}
