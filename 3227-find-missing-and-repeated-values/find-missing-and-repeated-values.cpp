class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int repeat = -1;
        vector<int>res(n*n+1, 0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(res[grid[i][j]]){
                    repeat = grid[i][j];
                }else{
                    res[grid[i][j]]=true;
                }
            }
        }
        for(int i = 1; i<=n*n; i++){
            if(!res[i]){
                return {repeat, i};
            }
        }
        return {};
    }
};