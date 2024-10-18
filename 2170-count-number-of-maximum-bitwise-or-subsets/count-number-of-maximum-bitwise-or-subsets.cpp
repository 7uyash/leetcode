class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        int count =0;
        for(int num :nums){
            maxOr |= num;

        }
        int totalSubsets = 1<<nums.size();
        for(int i =1; i<totalSubsets; ++i){
            int currentOr = 0;
            for(int j =0; j<nums.size(); ++j){
                if(i &(1<<j)){
                    currentOr |=nums[j];
                }
            }
            if(currentOr == maxOr){
                count++;
            }
        }
        return count;
    }
};