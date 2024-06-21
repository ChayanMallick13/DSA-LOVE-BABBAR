/*

    https://www.naukri.com/code360/problems/minimum-spanning-tree_631769?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

*/


#include <algorithm>

// hamara khud ka likha huya comparator (Our custom comparator)
bool cmp(vector<int> &a, vector<int> &b) {
    return (a[2] < b[2]);
}

// disjoint set

// parent nikalna (Finding the parent of a node)
int get_parent(vector<int> &parent, int node) {
    // base case (Base case)
    if (parent[node] == node) {
        return node;
    }

    // path compression (Path compression)
    int ans = get_parent(parent, parent[node]);
    parent[node] = ans;

    return ans;
}

// union by rank wala chiz (Union by rank function)
void merge(vector<int> &parent, vector<int> &rank, int u, int v) {
    // parent nikal lo (Find the parents)
    int p1 = get_parent(parent, u);
    int p2 = get_parent(parent, v);

    // rank ke hisab se check karo (Check according to rank)
    if (rank[p1] > rank[p2]) {
        parent[p2] = p1;
    } else if (rank[p1] < rank[p2]) {
        parent[p1] = p2;
    } else {
        parent[p2] = p1;
        rank[p1]++;
    }
}

// MST banane ka function (Function to create the MST)
int minimumSpanningTree(vector<vector<int>> &edges, int n) {
    // pehle sort kardo edges ko weight ke basis pe (First, sort edges based on weight)
    sort(edges.begin(), edges.end(), cmp);
    
    // parent wala array khud ka parent khud (Parent array where each node is its own parent initially)
    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // rank wala array banega (Create the rank array)
    vector<int> rank(n, 0);

    // answer me weight dalna hain (Variable to store the total weight of the MST)
    int ans = 0;

    // jitna edges hain usse iterate karo (Iterate through all edges)
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int p1 = get_parent(parent, u);
        int p2 = get_parent(parent, v);

        // agar parents different hain to merge kardo (If parents are different, merge them)
        if (p1 != p2) {
            merge(parent, rank, u, v);
            ans += edges[i][2]; // weight ko add karo (Add the weight to the answer)
        }
    }
    return ans; // total weight of MST return karo (Return the total weight of the MST)
}
