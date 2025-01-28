class Solution {
public:
    int dfs(int r, int c, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0 || visited[r][c])
            return 0;
        
        visited[r][c] = true;
        int sum = grid[r][c]; // Collect fish from the current cell

        // Explore all 4 possible directions
        sum += dfs(r + 1, c, grid, visited);
        sum += dfs(r - 1, c, grid, visited);
        sum += dfs(r, c + 1, grid, visited);
        sum += dfs(r, c - 1, grid, visited);
        
        return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int maxFish = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    maxFish = max(maxFish, dfs(i, j, grid, visited));
                }
            }
        }
        
        return maxFish;
    }
};