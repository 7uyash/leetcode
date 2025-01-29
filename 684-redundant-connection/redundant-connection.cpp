class Solution {
 vector<int> parent , rank;

    int findYourParent(int node)
    {
        if(node == parent[node])
        {
            return node;
        }
        return parent[node] = findYourParent(parent[node]);
    }

    void unionByRank(int u , int v)
    {
        int pu = findYourParent(u);
        int pv = findYourParent(v);

        if(pu == pv) return ;
        else if(rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        parent.resize(n+1);
        for(int i= 0 ; i < n+1 ; i++) parent[i] = i;
        rank.resize(n+1 , 0);
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            if(findYourParent(u) == findYourParent(v))
            {
                return it;
            }
            unionByRank(u , v);
        }

        return {};
    }
};