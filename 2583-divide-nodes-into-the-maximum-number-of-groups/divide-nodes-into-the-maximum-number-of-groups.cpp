class Solution {
public:
    vector<vector<int>> adj;
    vector<int> color;
    bool isBipartite;
    vector<int> compNodes;

    int getMaxDistFromNode(int src, int totalNodes) {
        vector<int> dist(totalNodes + 1, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 1;
        int maxDist = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neigh : adj[curr]) {
                if (dist[neigh] == -1) {
                    dist[neigh] = dist[curr] + 1;
                    q.push(neigh);
                    maxDist = max(maxDist, dist[neigh]);
                }
            }
        }
        return maxDist;
    }

    void dfs(int node, int currColor) {
        color[node] = currColor;
        compNodes.push_back(node);

        for (int neigh : adj[node]) {
            if (!color[neigh]) {
                dfs(neigh, 3 - currColor);
            } else if (color[neigh] == currColor) {
                isBipartite = false;
            }
        }
    }

    int magnificentSets(int n, vector<vector<int>> &edges) {
        for (int i = 0; i <= n; i++) {
            color.push_back(0);
            adj.push_back({});
        }

        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int maxGroups = 0;
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) {
                compNodes.clear();
                isBipartite = true;

                dfs(i, 1);
                if (!isBipartite) return -1;

                int maxCompDist = 0;
                for (int node : compNodes) {
                    maxCompDist = max(maxCompDist, getMaxDistFromNode(node, n));
                }
                maxGroups += maxCompDist;
            }
        }
        return maxGroups;
    }
};