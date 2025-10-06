class Solution {
public:
    bool possible(vector<int>& nums,int mid ,int k){
        int maxAllowedsum = mid; 
        int curr_sum = 0;
        int splits = 1;   
        for(int i = 0 ; i<nums.size() ; i++){
           if(nums[i] > maxAllowedsum){  
            return false;
           }
           if(curr_sum + nums[i] <= maxAllowedsum){
            curr_sum = curr_sum + nums[i];
           }
           else{
            splits++ ; 
            curr_sum = nums[i]; 
           }   
        }
        if(splits > k )return false;  
        return true;
    }
    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin() ,nums.end()); 
        int sum = 0;
        for(int &x :nums){
            sum += x;
        }
        int high = sum ; 
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2 ;
            if(possible(nums , mid , k)){
                ans = mid ; 
                high = mid-1 ; 
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};