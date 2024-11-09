class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>num_map;
        for(int i = 0; i<nums.size(); ++i){
            int cmp = target-nums[i];
            if(num_map.find(cmp) != num_map.end()){
                return {num_map[cmp], i};
            }
            num_map[nums[i]]=i;
        }
        return {};
    }
};