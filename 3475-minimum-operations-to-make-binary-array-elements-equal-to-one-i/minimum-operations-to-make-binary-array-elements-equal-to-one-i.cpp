class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0; i+2<n; i++){
            if(nums[i] == 0){
                nums[i] ^= 1;
                nums[i+1] ^= 1;
                nums[i+2] ^= 1;
                cnt++;
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                return -1;
            }
        }
        return cnt;
    }
};