int mod = (1e9+7);

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //Bi-directional
        vector<pair<int , int>> adj[n];
        for(auto& it : roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});            
        }
        //min heap 
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,
         greater<pair<long long,long long>>> store;
         
        store.push({0,0});

        vector<long long> dist(n,LONG_MAX);
        dist[0] = 0;
        
        vector<long long> ways(n,0);
        ways[0] = 1;
        
        while(!store.empty())
        {
            long long time = store.top().first;
            long long node = store.top().second;
            store.pop();

            for(auto& it : adj[node])
            {
                long long adjnode = it.first;
                long long time_needed = it.second;
                
                if(time_needed + time < dist[adjnode])
                {
                    dist[adjnode] = time_needed + time;
                    store.push({time_needed + time , adjnode});
                    ways[adjnode] = ways[node];
                }
                else if(time_needed + time == dist[adjnode])
                {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1];
    }
};