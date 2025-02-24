class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& step, int node, int parent, int time) {
        step[node] = time;
        if (node == 0) {
            return true;
        }
        for (auto& neighbor : adj[node]) {
            if (neighbor != parent) {
                if (dfs(adj, step, neighbor, node, time + 1)) {
                    return true;
                }
            }
        }
        step[node] = -1;
        return false;
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> step(n, -1);
        dfs(adj, step, bob, -1, 0);

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        vector<int> visited(n, 0);
        int maxProfit = INT_MIN;

        while (!q.empty()) {
            auto [node, data] = q.front();
            int time = data.first, profit = data.second;
            q.pop();

            if (step[node] == time) {
                profit += amount[node] / 2;
            } else if (step[node] == -1 || step[node] > time) {
                profit += amount[node];
            }
            
            visited[node] = 1;
            bool isLeaf = true;

            for (auto& neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    q.push({neighbor, {time + 1, profit}});
                    isLeaf = false;
                }
            }

            if (isLeaf) {
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();