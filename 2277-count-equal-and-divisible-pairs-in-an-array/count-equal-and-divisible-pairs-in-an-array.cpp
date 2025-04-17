class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, unordered_map<int, int>> moduloMap;
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            int mod_i = i % k;

            if (moduloMap.count(nums[i])) {
                for (auto& [mod_j, count] : moduloMap[nums[i]]) {
                    if ((mod_i * mod_j) % k == 0) {
                        res += count;
                    }
                }
            }
            moduloMap[nums[i]][mod_i]++;
        }
        return res;
    }
};