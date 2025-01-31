class Solution {
public:
    int Bfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis,
    vector<vector<int>>& UpdateVis,vector<vector<int>>& group,int GroupNum){
        int n = grid.size(), m=grid[0].size();
        queue<pair<int,int>>q;
        int count =1;
        q.push({r,c});
        int dcol[] = {1,-1,0,0};
        int drow[] = {0,0,1,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr = row+drow[k];
                int nc = col+dcol[k];
                if(nc>=0 and nr>=0 and nr<n and nc<m and grid[nr][nc]==1 and vis[nr][nc]==0){
                    count++;
                    vis[nr][nc]=1;
                    group[nr][nc]=GroupNum;
                    q.push({nr,nc});
                    UpdateVis.push_back({nr,nc});
                }
            }

        }
        return count;

    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int ans=0,GroupNum=0;
        vector<vector<int>>group(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    vis[i][j]=1;
                    GroupNum++;
                    vector<vector<int>>UpdateVis;
                    UpdateVis.push_back({i,j});
                    group[i][j]=GroupNum;
                    int count = Bfs(i,j,grid,vis,UpdateVis,group,GroupNum);
                    cout<<"count "<<count<<" i,j "<<i<<" "<<j<<endl;
                    ans = max(ans,count);
                    for(auto it:UpdateVis){
                        vis[it[0]][it[1]]=count;
                    }
                }
            }
        }
        int dcol[] = {1,-1,0,0};
        int drow[] = {0,0,1,-1};
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(vis[r][c]==0){
                    int temp=1;
                    unordered_set<int>set;
                    for(int k=0;k<4;k++){
                        int nr = r+drow[k];
                        int nc = c+dcol[k];
                        if(nc>=0 and nr>=0 and nr<n and nc<m){
                            if(set.find(group[nr][nc])==set.end())temp +=vis[nr][nc];
                            set.insert(group[nr][nc]);
                        }
                        //cout<<"temp "<<temp<<" i,j "<<r<<" "<<c<<endl;
                    }
                    ans = max(temp,ans);
                }

            }
        }
        return ans;
        
    }
};