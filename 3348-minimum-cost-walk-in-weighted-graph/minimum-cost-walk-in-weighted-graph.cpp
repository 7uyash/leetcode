class Solution {
public:
    int pt[100001];
    int pt_wt[100001]; 
    int find(int a) {
        if (pt[a] != a) {
            pt[a] = find(pt[a]);
        }
        return pt[a];
    }
    void union_(int a, int b, int wt) {
        pt_wt[find(a)] = wt & pt_wt[find(a)] & pt_wt[find(b)];
        pt[find(b)] = find(a);
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        for (int i = 0; i <= 100000; i++) {
            pt[i] = i;
            pt_wt[i] = ~0; 
        }
        for (auto &edge : edges) {
            int a = edge[0], b = edge[1], wt = edge[2];
            union_(a, b, wt);
        }
        vector<int> ans(query.size());
        for (int i = 0; i < query.size(); i++) {
            int a = query[i][0], b = query[i][1];

            if (find(a) != find(b)) {
                ans[i] = -1; 
            } else {
                ans[i] = pt_wt[find(a)];
            }
        }
        return ans;
    }
};