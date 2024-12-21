class Solution {
public:
    vector<vector<int>>g;
    vector<bool>vis;
    int ans=0;
    long long dfs(int node,int k,vector<int>& vals)
    {
        vis[node]=1;
        long long sum=vals[node];
        for(auto ch:g[node])
        {
            if(vis[ch]==0){
               sum+=dfs(ch,k,vals);
            }
        }
        if(sum%k==0)
        {
            ans++;
            cout<<"a ";
            return 0;
        }
        else return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& e, vector<int>& vals, int k) {
        g=vector<vector<int>>(n+1);
        vis=vector<bool>(n+1);
        map<int,int>mp;
        for(int i=0;i<e.size();i++)
        {
            mp[e[i][0]]++;
            mp[e[i][1]]++;
            g[e[i][0]].push_back(e[i][1]);
            g[e[i][1]].push_back(e[i][0]);
        }
        int node=0;
        for(auto [i,j]:mp)if(j==2)node=i;
        dfs(node,k,vals);
        cout<<node;
        return ans;   
    }
};