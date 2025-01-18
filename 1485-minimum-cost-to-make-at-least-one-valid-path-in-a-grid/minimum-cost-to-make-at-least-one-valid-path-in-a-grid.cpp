class Solution {
    vector<int> a = {0,0,1,-1};
    vector<int> b = {1,-1,0,0};

    bool check(int x,int y,int n,int m){
        if(x>=0 && x<n && y>=0 && y<m)
            return 1;
        return 0;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<bool>> visit(n,vector<bool>(m,0));
        pq.push({0,0,0});
        while(!pq.empty()){
            vector<int> temp = pq.top();
            pq.pop();
            int x= temp[1], y = temp[2], c = temp[0];
            if(visit[x][y]==1) continue;
            visit[x][y] = 1;
            if(x==n-1 && y==m-1) return c;
            for(int i=0;i<4;i++){
                if(check(x+a[i],y+b[i],n,m) && !visit[x+a[i]][y+b[i]]){
                    if(i == grid[x][y]-1)
                        pq.push({c,x+a[i],y+b[i]});
                    else{
                        pq.push({c+1,x+a[i],y+b[i]});
                    }
                }
            }
        }
        return -1;
    }
};