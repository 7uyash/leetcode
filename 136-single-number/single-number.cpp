class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }else{
            sort(nums.begin(), nums.end());
            int i = 0;
            for(int i = 0; i<nums.size(); ){
                if(nums[i]!=nums[i+1]){
                    return nums[i];
                }
                i+=2;
            }
        }
        return 9;
    }
};