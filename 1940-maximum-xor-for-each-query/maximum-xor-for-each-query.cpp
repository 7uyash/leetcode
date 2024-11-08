class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int totalXor = 0;
        for(int num : nums){
            totalXor ^= num;

        }
        int maxK = (1<<maximumBit)-1;
        vector<int>ans;
        for(int i = nums.size()-1; i>=0; --i){
            ans.push_back(totalXor ^ maxK);
            totalXor^=nums[i];
        }
        return ans;
    }
};