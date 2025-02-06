class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, vector<pair<int,int>> >hash;

        int n = nums.size();
        int res = 0; 

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pair<int, int> p = {nums[i], nums[j]};
                hash[nums[i] * nums[j]].push_back(p);
            }
        }

        for(auto i : hash){
            int x = i.second.size();
            if(x > 1){
                res = res + x*(x-1)*4;
            }
        }
        return res;
    }
};