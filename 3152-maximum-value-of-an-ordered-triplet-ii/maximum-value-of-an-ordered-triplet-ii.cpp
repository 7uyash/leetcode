class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n  = nums.size();
        if(n<3) {
            return 0;
        }
        vector<int> preMax(n ,-1);
        vector<int> postMax(n,-1);
        int maxi = nums[0];
        preMax[0] = 0;
        for(int i =1; i< n;i++) {
            if(nums[i-1] > maxi) {
                maxi = nums[i-1];
                preMax[i] = i-1;
            }
            else{
                preMax[i] = preMax[i-1];
            }
        }
        // 
        int postMaxi = nums[n-1];
        postMax[n-1] = n-1;
        for(int i = n-2;i >=0 ; i--) {
            if(nums[i+1] > postMaxi) {
                postMaxi = nums[i+1];
                postMax[i] = i+1;
            }
            else {
                postMax[i] = postMax[i+1];
            }
        }
         long long ans = 0;
        for (int i = 1; i < n - 1; i++) {  
            if (preMax[i] == -1 || postMax[i] == -1) continue;

            int leftMax = nums[preMax[i]];
            int rightMax = nums[postMax[i]];

            ans = max(ans, (long long)(leftMax - nums[i]) * rightMax);
        }
        if(ans < 0) {
            return -1;
        }
        return ans;
    }
};