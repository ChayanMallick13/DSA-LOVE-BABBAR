/*

https://www.naukri.com/code360/problems/bridges-in-graph_893026?leftPanelTab=0&leftPanelTabValue=SUBMISSION

*/





#include <bits/stdc++.h>
using namespace std;

// DFS function to find bridges in the graph
void dfs(int &timer, vector<int> &discovery, vector<int> &lowest, vector<bool> &visited, int node, vector<vector<int>> &ans, unordered_map<int, vector<int>> &adj, int parent) {
    // Timer ko update kar do (Increment the timer)
    timer++;

    // Node ko visited mark kar do (Mark the current node as visited)
    visited[node] = true;

    // Discovery time aur lowest time set kar do (Set discovery and lowest times for the current node)
    discovery[node] = timer;
    lowest[node] = timer;

    // Saare neighbors check karo (Check all neighbors of the current node)
    for (auto i : adj[node]) {
        // Agar neighbor visited nahi hai (If the neighbor is not visited)
        if (!visited[i]) {
            // DFS call karo neighbor ke liye (Recursively call DFS for the neighbor)
            dfs(timer, discovery, lowest, visited, i, ans, adj, node);

            // Current node ka lowest time update karo (Update the lowest time of the current node)
            lowest[node] = min(lowest[node], lowest[i]);

            // Agar lowest time neighbor ka discovery time se bada hai (If the lowest time of the neighbor is greater than the discovery time of the current node)
            if (lowest[i] > discovery[node]) {
                // Yeh edge bridge hai (This edge is a bridge)
                ans.push_back({node, i});
            }
        }
        // Agar back edge hai (If it is a back edge)
        else if (i != parent) {
            // Current node ka lowest time update karo (Update the lowest time of the current node)
            lowest[node] = min(lowest[node], discovery[i]);
        }
    }
}

// Function to find all bridges in the graph
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Assets laker aata hu (Declare necessary data structures)

    // Adjacency list banalo (Create adjacency list for the graph)
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // Adjacency list me edges add kar do (Add edges to the adjacency list)
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Discovery time ka array (Array to store discovery times of nodes)
    vector<int> discovery(v, -1);

    // Lowest time ka array (Array to store the lowest discovery times reachable from each node)
    vector<int> lowest(v, -1);

    // Visited array (Array to mark nodes as visited or not)
    vector<bool> visited(v, false);

    // Timer ko initialize karo (Initialize the timer)
    int timer = -1;

    // Result ke bridges store karne ka array (Vector to store the bridges)
    vector<vector<int>> ans;

    // Saare nodes pe DFS call karo (Call DFS for all nodes to handle disconnected components)
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            // Agar node visited nahi hai to DFS call karo (If the node is not visited, call DFS)
            dfs(timer, discovery, lowest, visited, i, ans, adj, -1);
        }
    }

    // Bridges return karo (Return the list of bridges)
    return ans;
}
