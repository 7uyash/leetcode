class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> res= nums;
        int s = res.size();
        for(int i = 0; i<s; i++){
            int a = nums[i];
            res[i]= nums[a];
        }
        return res;
    }
};