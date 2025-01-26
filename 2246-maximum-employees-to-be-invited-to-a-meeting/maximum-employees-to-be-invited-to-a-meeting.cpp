class Solution {
public:
    int findLengthMax(vector<vector<int>> &graph, int v) {
        int mx = 0;
        for(int i: graph[v]) {
            mx = max(mx, findLengthMax(graph, i));
        }

        return mx + 1;
    }

    int maximumInvitations(vector<int>& f) {
        int sz = f.size();
        vector<int> ind(sz);
        vector<vector<int>> graph(sz); // reverse graph

        for(int i = 0 ; i < sz; ++i) {
            ind[f[i]]++;
            graph[f[i]].push_back(i);
        }

        // Topological sorting here
        queue<int> q;
        vector<bool> visited(sz);
        for(int i = 0; i < sz; ++i) {
            if (ind[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            visited[v] = 1;
            if (--ind[f[v]] == 0) q.push(f[v]);
        }

        int length_2 = 0;
        int length_ = 0;
        vector<bool> temp(sz);
        for (int i = 0; i < sz; ++i) {
            if (visited[i] == false && temp[i] == false){
                // This could be the cycle.
                // lets find the cycle starting at this position
                int x = i;
                vector<int> cycle;
                while (!temp[x]) {
                    temp[x] = true;
                    cycle.push_back(x);
                    
                    x = f[x];
                }
                 cout<<cycle.size()<<" | ";

                if (cycle.size() == 2) {
                    int mx1 = 0;
                    for (int v: graph[cycle[0]]) {
                        if (!temp[v])
                        mx1 = max(mx1, findLengthMax(graph, v));
                    }

                    int  mx2 = 0;
                    for (int v: graph[cycle[1]]) {
                        if (!temp[v])
                        mx2 = max(mx2, findLengthMax(graph, v));
                    }
                     cout<<mx1<<" "<<mx2;

                    length_2 += (mx1 + mx2 + 2);
                } else {
                    length_ = max(length_, (int)cycle.size());
                }
            }
        }

        return max(length_, length_2);
    }
};