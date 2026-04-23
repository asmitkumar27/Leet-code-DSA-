class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        // Step 1: Build adjacency list
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]); // undirected
        }
        
        // Step 2: BFS
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            if (node == destination) return true;
            
            if (visited[node]) continue;
            visited[node] = true;
            
            for (int nei : adj[node]) {
                if (!visited[nei]) {
                    q.push(nei);
                }
            }
        }
        
        return false;
    }
};