/*

    https://www.geeksforgeeks.org/problems/articulation-point-1/1

    article
    https://www.naukri.com/code360/library/articulation-points-in-a-graph

*/


class Solution {
private:
    // DFS function define kar rahe hain
    void dfs(vector<int> adj[], vector<int> &disc, vector<int> &lowest, vector<bool> &visited, int &timer, int parent, int node, vector<int> &ap) {
        
        // Node ko visited mark kar rahe hain
        visited[node] = true;

        // Discovery time aur lowest time ko update kar rahe hain
        disc[node] = lowest[node] = timer++;
        
        int child = 0;

        // Current node ke adjacency list ke liye loop
        for(auto i : adj[node]) {
            if(!visited[i]) {
                child++;
                dfs(adj, disc, lowest, visited, timer, node, i, ap);
                
                // Lowest time update kar rahe hain
                lowest[node] = min(lowest[node], lowest[i]);

                // Articulation point check kar rahe hain
                if((lowest[i] >= disc[node]) && (parent != -1)) {
                    ap[node] = true;
                }
            }

            // Back edge check kar rahe hain
            if(i != parent) {
                lowest[node] = min(lowest[node], disc[i]);
            }
        }

        // Root node ke liye articulation point check kar rahe hain
        if((child > 1) && (parent == -1)) {
            ap[node] = true;
        }
    }

public:
    // Function to find articulation points
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        int n = V;
        vector<int> disc(n, -1);
        vector<int> lowest(n, -1);
        vector<bool> visited(n, false);
        vector<int> ap(n, false);

        int timer = 0;

        // Sabhi nodes ke liye DFS call kar rahe hain
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(adj, disc, lowest, visited, timer, -1, i, ap);
            }
        }

        vector<int> ans;
        // Articulation points ko result mein add kar rahe hain
        for(int i = 0; i < V; i++) {
            if(ap[i]) {
                ans.push_back(i);
            }
        }
        
        // Agar koi articulation point nahi mila toh -1 return kar rahe hain
        if(ans.size() == 0) {
            return {-1};
        }
        return ans;
    }
};
